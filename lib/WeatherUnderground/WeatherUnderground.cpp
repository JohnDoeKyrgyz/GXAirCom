#include <WeatherUnderground.h>


WeatherUnderground::WeatherUnderground(){
    client = NULL;
    xMutex = NULL;
}

void WeatherUnderground::setClient(Client *_client){
    client = _client;
}

void WeatherUnderground::setMutex(SemaphoreHandle_t *_xMutex){
    xMutex = _xMutex;
}



bool WeatherUnderground::getData(String ID,String KEY,wData *data){ //get Data from WU with Station-ID and API-Key
  char msg[1024]; //make this big enough to hold the resulting string
  bool bRet = true;
  if (xMutex == NULL){ //create new Mutex
      xMutex = new SemaphoreHandle_t();
      *xMutex = xSemaphoreCreateMutex();
  }
  //sprintf(msg,"http://api.weather.com/v2/pws/observations/current?stationId=%s&format=json&units=m&apiKey=%s",
  sprintf(msg,"/v2/pws/observations/current?stationId=%s&format=json&units=m&apiKey=%s",
          ID.c_str(),
          KEY.c_str()
          );
  //log_i("%s len=%d",msg,strlen(msg));
  String payload = ""; //http.getString();
  if (client == NULL){    
    client = new WiFiClient();
  }
  xSemaphoreTake( *xMutex, portMAX_DELAY );
  HttpClient http(*client, "api.weather.com");  
  int httpResponseCode = http.get(msg);
  if (httpResponseCode == 0){
    httpResponseCode = http.responseStatusCode();
    if (httpResponseCode == 200){
      int length = http.contentLength();
      if (length >= 0) {
        payload = http.responseBody();
      }else{
        log_e("content length <= 0");
        bRet = false;
      }
    }else{
      log_e("resp=%d",httpResponseCode);
      bRet = false;
    } 
  }else{
    log_e("failed to connect=%d",httpResponseCode);
    bRet = false;
  }
  http.stop();
  xSemaphoreGive( *xMutex );
  if (!bRet){
    return bRet;
  }
  //log_i("%s",payload.c_str());
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, payload);
  String stationID = doc["observations"][0]["stationID"].as<String>();
  if (stationID != ID){
    log_e("stationid not equal %s != %s",ID.c_str(),stationID.c_str());
    return false;
  }
  //if (doc["observations"][0]["stationID"]) log_i("%s",doc["observations"][0]["stationID"].as<String>().c_str());
  if (doc["observations"][0]["lat"]) data->lat = doc["observations"][0]["lat"].as<float>();
  if (doc["observations"][0]["lon"]) data->lon = doc["observations"][0]["lon"].as<float>();
  if (doc["observations"][0]["metric"]["elev"]) data->height = doc["observations"][0]["metric"]["elev"].as<float>();
  if (doc["observations"][0]["metric"]["temp"]) data->temp = doc["observations"][0]["metric"]["temp"].as<float>();
  if (doc["observations"][0]["humidity"]) data->humidity = doc["observations"][0]["humidity"].as<float>();
  String s = doc["observations"][0]["winddir"].as<String>();
  if (s != "null"){
    data->bWind = true;
    data->winddir = doc["observations"][0]["winddir"].as<float>();
    data->windspeed = doc["observations"][0]["metric"]["windSpeed"].as<float>();    
    data->windgust = doc["observations"][0]["metric"]["windGust"].as<float>();
  }else{
    log_i("no wind-data");
    data->bWind = false;
    data->winddir = 0.0;
    data->windspeed = 0.0;
    data->windgust = 0.0;
  }
  
  
  if (doc["observations"][0]["metric"]["pressure"]) data->pressure = doc["observations"][0]["metric"]["pressure"].as<float>();
  
  s = doc["observations"][0]["metric"]["precipRate"].as<String>();
  if (s != "null"){
    data->bRain = true;
    data->rain1h = doc["observations"][0]["metric"]["precipRate"].as<float>();
    data->raindaily = doc["observations"][0]["metric"]["precipTotal"].as<float>();
  }else{
    log_i("no rain-data");
    data->bRain = false;
    data->rain1h = 0.0;
    data->raindaily = 0.0;
  }
  return bRet;
}

bool  WeatherUnderground::sendData(String ID,String KEY,wData *data){ //send Data to WU with Station-ID and Station-Key
  //time_t now;
  bool bRet = true;
  if (xMutex == NULL){ //create new Mutex
      xMutex = new SemaphoreHandle_t();
      *xMutex = xSemaphoreCreateMutex();
  }
  //time(&now);
  char msg[1024]; //make this big enough to hold the resulting string
  char msg2[255]; //make this big enough to hold the resulting string
  float dewpoint = dewPointFast(data->temp,data->humidity);
  //sprintf(msg,"http://weatherstation.wunderground.com/weatherstation/updateweatherstation.php?ID=%s&PASSWORD=%s&dateutc=%04d-%02d-%02d+%02d%%3A%02d%%3A%02d",
  sprintf(msg,"/weatherstation/updateweatherstation.php?ID=%s&PASSWORD=%s&dateutc=%04d-%02d-%02d+%02d%%3A%02d%%3A%02d",
          ID.c_str(),
          KEY.c_str(),
          year(),
          month(),
          day(),
          hour(),
          minute(),
          second()
          );
  if (data->bWind){
    sprintf(msg2,"&winddir=%.2f&windspeedmph=%.2f&windgustmph=%.2f",
          data->winddir,
          kmh2mph(data->windspeed),
          kmh2mph(data->windgust)
          );
    strcat(msg,msg2);
  }
  sprintf(msg2,"&humidity=%.2f&tempf=%.2f&baromin=%.2f&dewptf=%.2f",
          data->humidity,
          deg2f(data->temp),
          data->pressure * 0.029529983071445,
          deg2f(dewpoint)
          );
  strcat(msg,msg2);
  if (data->bRain){
    sprintf(msg2,"&rainin=%.2f&dailyrainin=%.2f",
            data->rain1h,
            data->raindaily
            );
    strcat(msg,msg2);
  }  
  sprintf(msg2,"&softwaretype=GXAircom-%s&action=updateraw",
          VERSION
          );
  strcat(msg,msg2);
  //log_i("T1=%f h=%f p1=%f dp=%f",temp,humidity,baro,dewpoint);
  //log_i("%s len=%d",msg,strlen(msg));
  if (client == NULL){    
    client = new WiFiClient();
  }
  xSemaphoreTake( *xMutex, portMAX_DELAY );
  HttpClient http(*client, "weatherstation.wunderground.com");  
  int httpResponseCode = http.get(msg);
  if (httpResponseCode == 0){
    httpResponseCode = http.responseStatusCode();
    if (httpResponseCode != 200){
      log_e("resp=%d",httpResponseCode);
      bRet = false;
    } 
  }else{
    log_e("failed to connect=%d",httpResponseCode);
    bRet = false;
  }
  http.stop();
  xSemaphoreGive( *xMutex );
  return bRet;

  /*
  if (client != NULL){
    http.begin(client,msg);
  }else{
    http.begin(msg);
  }  
  //http.begin(msg);
  int httpResponseCode = http.GET();  
  if (httpResponseCode != 200){
    log_e("resp=%d %s",httpResponseCode,http.getString().c_str());
    xSemaphoreGive( *xMutex );
    return false;
  }
  */
}