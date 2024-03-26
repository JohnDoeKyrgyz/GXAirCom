#include "fileOps.h"
#include <Preferences.h>

Preferences preferences;  

void load_configFile(SettingsData* pSetting){
  log_i("LOAD CONFIG FILE");
  preferences.begin("settings", false);
  pSetting->settingsView = preferences.getUChar(KEY_SETVIEW,0);
  pSetting->wifi.appw = preferences.getString(KEY_ACESSPOINT_PASSWORD,"12345678");
  pSetting->boardType = eBoard(preferences.getUChar(KEY_BOARDTYPE,UNKNOWN));
  pSetting->CPUFrequency = preferences.getUChar(KEY_CPUFREQU,240);
  pSetting->bHasExtPowerSw = preferences.getUChar(KEY_EXTPWSW,0);//external power-switch
  pSetting->RFMode = preferences.getUChar(KEY_RFM,11);//default FntRx + FntTx + LegTx
  pSetting->awLiveTracking = preferences.getUChar(KEY_AWLIVE,0);
  pSetting->bOutputSerial = preferences.getUChar(KEY_OSerial,0);
  pSetting->outputModeVario = eOutputVario(preferences.getUChar(KEY_OVario,OVARIO_LK8EX1));
  pSetting->outputFLARM = preferences.getUChar(KEY_OFLARM,1);
  pSetting->outputGPS = preferences.getUChar(KEY_OGPS,1);
  pSetting->outputFANET = preferences.getUChar(KEY_OFANET,1);
  pSetting->PilotName = preferences.getString(KEY_PILOTNAME,"");
  pSetting->myDevId = preferences.getString(KEY_myDevId,"");
  pSetting->myDevIdType = preferences.getULong(KEY_myDevIdType,2); //Default FLARM
  pSetting->gps.customGPSConfig = preferences.getBool(KEY_customGPSConfig,false);
  pSetting->gps.Baud = preferences.getULong(KEY_GPSBAUD,9600);
  pSetting->wifi.uMode.mode = preferences.getUChar(KEY_WIFI_MODE,0);
  pSetting->wifi.connect = eWifiMode(preferences.getUChar(KEY_WIFI_CONNECT,CONNECT_NONE));
  pSetting->wifi.ssid = preferences.getString(KEY_WIFI_SSID,"");
  pSetting->wifi.password = preferences.getString(KEY_WIFI_PW,"");
  pSetting->wifi.tWifiStaStop = preferences.getUInt(KEY_WIFISTA_STOP,0); //stop wifi station after seconds.
  pSetting->wifi.tWifiApStop = preferences.getUInt(KEY_WIFIAP_STOP,180); //stop wifi access point after seconds.
  pSetting->AircraftType = preferences.getUChar(KEY_AIRCRAFTTYPE,1);
  pSetting->UDPServerIP = preferences.getString(KEY_UDP_SERVER,"192.168.4.2"); //UDP-IP-Adress to match connected device
  pSetting->UDPSendPort = preferences.getUInt(KEY_UDP_PORT,10110); //Port of udp-server
  pSetting->outputMode = eOutput(preferences.getUChar(KEY_OutputMode,oBLE)); //output-mode default ble
  pSetting->Mode = eMode(preferences.getUChar(KEY_Mode,AIR_MODULE));
  pSetting->fanetMode = eFnMode(preferences.getUChar(KEY_fntMode,FN_GROUNT_AIR_TRACKING));
  pSetting->fanetpin = preferences.getUInt(KEY_fntPin,0000);
  pSetting->bAutoupdate = preferences.getUChar(KEY_AUTOUPDATE,1); //auto-update"

  //gs settings
  pSetting->gs.lat = preferences.getFloat(KEY_GSLAT,0.0);
  pSetting->gs.lon = preferences.getFloat(KEY_GSLON,0.0);
  pSetting->gs.alt = preferences.getFloat(KEY_GSALT,0.0);
  pSetting->gs.geoidAlt = preferences.getFloat(KEY_GSGEOALT,0.0);

  pSetting->FntWuUpload[0].FanetId = preferences.getULong(KEY_F2WuF0,0);
  pSetting->FntWuUpload[1].FanetId = preferences.getULong(KEY_F2WuF1,0);
  pSetting->FntWuUpload[2].FanetId = preferences.getULong(KEY_F2WuF2,0);
  pSetting->FntWuUpload[3].FanetId = preferences.getULong(KEY_F2WuF3,0);
  pSetting->FntWuUpload[4].FanetId = preferences.getULong(KEY_F2WuF4,0);
  pSetting->FntWuUpload[0].ID = preferences.getString(KEY_F2WuI0,"");
  pSetting->FntWuUpload[1].ID = preferences.getString(KEY_F2WuI1,"");
  pSetting->FntWuUpload[2].ID = preferences.getString(KEY_F2WuI2,"");
  pSetting->FntWuUpload[3].ID = preferences.getString(KEY_F2WuI3,"");
  pSetting->FntWuUpload[4].ID = preferences.getString(KEY_F2WuI4,"");
  pSetting->FntWuUpload[0].KEY = preferences.getString(KEY_F2WuK0,"");
  pSetting->FntWuUpload[1].KEY = preferences.getString(KEY_F2WuK1,"");
  pSetting->FntWuUpload[2].KEY = preferences.getString(KEY_F2WuK2,"");
  pSetting->FntWuUpload[3].KEY = preferences.getString(KEY_F2WuK3,"");
  pSetting->FntWuUpload[4].KEY = preferences.getString(KEY_F2WuK4,"");
  pSetting->FntWiUpload[0].FanetId = preferences.getULong(KEY_F2WiF0,0);
  pSetting->FntWiUpload[1].FanetId = preferences.getULong(KEY_F2WiF1,0);
  pSetting->FntWiUpload[2].FanetId = preferences.getULong(KEY_F2WiF2,0);
  pSetting->FntWiUpload[3].FanetId = preferences.getULong(KEY_F2WiF3,0);
  pSetting->FntWiUpload[4].FanetId = preferences.getULong(KEY_F2WiF4,0);
  pSetting->FntWiUpload[0].ID = preferences.getString(KEY_F2WiI0,"");
  pSetting->FntWiUpload[1].ID = preferences.getString(KEY_F2WiI1,"");
  pSetting->FntWiUpload[2].ID = preferences.getString(KEY_F2WiI2,"");
  pSetting->FntWiUpload[3].ID = preferences.getString(KEY_F2WiI3,"");
  pSetting->FntWiUpload[4].ID = preferences.getString(KEY_F2WiI4,"");
  pSetting->FntWiUpload[0].KEY = preferences.getString(KEY_F2WiK0,"");
  pSetting->FntWiUpload[1].KEY = preferences.getString(KEY_F2WiK1,"");
  pSetting->FntWiUpload[2].KEY = preferences.getString(KEY_F2WiK2,"");
  pSetting->FntWiUpload[3].KEY = preferences.getString(KEY_F2WiK3,"");
  pSetting->FntWiUpload[4].KEY = preferences.getString(KEY_F2WiK4,"");
  pSetting->gs.SreenOption = eScreenOption(preferences.getUChar(KEY_GSSCR,ALWAYS_ON));
  pSetting->gs.PowerSave = eGsPower(preferences.getUChar(KEY_GSPS,GS_POWER_ALWAYS_ON));
  pSetting->gs.sunriseOffset = eGsPower(preferences.getInt("GsSrO",0));
  pSetting->gs.sunsetOffset = eGsPower(preferences.getInt("GsSsO",0));
  pSetting->wd.anemometer.AnemometerType = eAnemometer(preferences.getUChar(KEY_GSANEO,DAVIS));
  pSetting->wd.anemometer.AnemometerAdsGain = preferences.getUChar(KEY_WDANEOADSGAIN,2);;
  pSetting->wd.anemometer.AnemometerAdsWSpeedMinVoltage = preferences.getFloat("WDANEOADSWSMINV",0.0);
  pSetting->wd.anemometer.AnemometerAdsWSpeedMaxVoltage = preferences.getFloat("WDANEOADSWSMAXV",10.0);
  pSetting->wd.anemometer.AnemometerAdsWDirMinVoltage = preferences.getFloat("WDANEOADSWDMINV",0.0);
  pSetting->wd.anemometer.AnemometerAdsWDirMaxVoltage = preferences.getFloat("WDANEOADSWDMAXV",10.0);
  pSetting->wd.anemometer.AnemometerAdsWSpeedMinSpeed = preferences.getFloat("WDANEOADSWSMINS",0.0);
  pSetting->wd.anemometer.AnemometerAdsWSpeedMaxSpeed = preferences.getFloat("WDANEOADSWSMAXS",120.0);
  pSetting->wd.anemometer.AnemometerAdsWDirMinDir = preferences.getFloat("WDANEOADSWDMIND",0.0);
  pSetting->wd.anemometer.AnemometerAdsWDirMaxDir = preferences.getFloat("WDANEOADSWDMAXD",360.0);
  pSetting->wd.anemometer.AnemometerAdsVDivR1 = preferences.getFloat("WDANEOADSVDIVR1",8060000.0);
  pSetting->wd.anemometer.AnemometerAdsVDivR2 = preferences.getFloat("WDANEOADSVDIVR2",402000.0);
  pSetting->BattVoltOffs = preferences.getFloat("BATOFFS",0.0);
  pSetting->minBattPercent = preferences.getUChar(KEY_BattMinPerc,20);
  pSetting->restartBattPercent = preferences.getUChar(KEY_restartBattPerc,20);

  //live-tracking
  pSetting->OGNLiveTracking.mode = preferences.getUChar(KEY_OGN_LIVE,0);
  pSetting->screenNumber = preferences.getUChar(KEY_SCREEN,0);
  pSetting->displayType = eDisplay(preferences.getUChar(KEY_Display,NO_DISPLAY));
  pSetting->displayRotation = preferences.getUChar(KEY_DispRot,0);
  pSetting->traccarLiveTracking = preferences.getUChar(KEY_TRACCAR_LIVE,0);
  pSetting->TraccarSrv = preferences.getString(KEY_TRACCAR_SRV,"");
  
  //weathersettings
  pSetting->wd.mode.mode = preferences.getUChar(KEY_WsMode,0);
  pSetting->wd.sendFanet = preferences.getUChar(KEY_FanetWeather,0);
  pSetting->wd.tempOffset = preferences.getFloat(KEY_wdTempOffset,0.0);
  pSetting->wd.windDirOffset = preferences.getInt(KEY_wdWDirOffset,0);
  pSetting->wd.avgFactorFanet = preferences.getFloat(KEY_avgFanet,16);
  pSetting->wd.FanetUploadInterval = preferences.getULong(KEY_FanetWDInt,40000);
  pSetting->wd.avgFactorWU = preferences.getFloat(KEY_avgWU,128);
  pSetting->wd.WUUploadIntervall = preferences.getULong(KEY_WUIntervall,300000);

  //vario
  pSetting->vario.sinkingThreshold = preferences.getFloat(KEY_vSinkTh,-2.5);
  pSetting->vario.climbingThreshold = preferences.getFloat(KEY_vClimbTh,0.2);
  pSetting->vario.nearClimbingSensitivity = preferences.getFloat(KEY_vNClimbSens,0.2);
  pSetting->vario.volume = preferences.getUChar(KEY_VarioVolume,127); //full duty-cycle
  pSetting->vario.BeepOnlyWhenFlying = preferences.getUChar(KEY_VBeepFlying,1);
  pSetting->vario.useMPU = preferences.getUChar(KEY_useMPU,0);
  pSetting->vario.tempOffset = preferences.getFloat(KEY_vTOffs,0.0);
  pSetting->vario.sigmaP = preferences.getFloat(KEY_vSigmaP,0.1);
  pSetting->vario.sigmaA = preferences.getFloat(KEY_vSigmaA,0.6);

  //wu-upload
  pSetting->WUUpload.enable = preferences.getUChar(KEY_WUUlEnable,0);
  pSetting->WUUpload.ID = preferences.getString(KEY_WUUlID,"");
  pSetting->WUUpload.KEY = preferences.getString(KEY_WUUlKEY,"");

  //windy-upload
  pSetting->WindyUpload.enable = preferences.getUChar(KEY_WIUlEnable,0);
  pSetting->WindyUpload.ID = preferences.getString(KEY_WIUlID,"");
  pSetting->WindyUpload.KEY = preferences.getString(KEY_WIUlKEY,"");

  //gsm
  pSetting->gsm.apn = preferences.getString(KEY_GSMAPN,"");
  pSetting->gsm.user = preferences.getString(KEY_GSMUSER,"");
  pSetting->gsm.pwd = preferences.getString(KEY_GSMKEY,"");
  pSetting->gsm.NetworkMode = eGsmNetworkMode(preferences.getUChar(KEY_GSMMODE,GSM_NW_AUTO));
  pSetting->gsm.PreferredMode = eGsmPreferedMode(preferences.getUChar(KEY_GSMPREF,GSM_PREF_NOT_SET));
  pSetting->gsm.NB_IOT_Band = preferences.getString(KEY_NBIOT,"");
  pSetting->gsm.CAT_M_Band = preferences.getString(KEY_CATM,"");

  //fuel-sensor
  pSetting->bHasFuelSensor = preferences.getUChar(KEY_fuelSensor,0);

  //mqtt
  pSetting->mqtt.mode.mode = preferences.getUChar(KEY_MqttEn,0);
  pSetting->mqtt.server = preferences.getString(KEY_MqttServer,"");
  pSetting->mqtt.port = preferences.getInt(KEY_MqttPort,1883);
  pSetting->mqtt.pw = preferences.getString(KEY_MqttPw,"");
  preferences.end(); 

  //vario
  preferences.begin("fastvario", false);
  pSetting->vario.accel[0] = preferences.getInt(KEY_axOffset, 0);
  pSetting->vario.accel[1] = preferences.getInt(KEY_ayOffset, 0);
  pSetting->vario.accel[2] = preferences.getInt(KEY_azOffset, 0);
  pSetting->vario.gyro[0] = preferences.getInt(KEY_gxOffset, 0);
  pSetting->vario.gyro[1] = preferences.getInt(KEY_gyOffset, 0);
  pSetting->vario.gyro[2] = preferences.getInt(KEY_gzOffset, 0);
  pSetting->vario.tValues[0] = preferences.getFloat(KEY_t0,20.0);
  pSetting->vario.tValues[1] = preferences.getFloat(KEY_t1,0.0);
  pSetting->vario.zValues[0] = preferences.getFloat(KEY_z0,0.0);
  pSetting->vario.zValues[1] = preferences.getFloat(KEY_z1,0.0);
  preferences.end();
}

void write_configFile(SettingsData* pSetting){
  log_i("WRITE CONFIG FILE");
  preferences.begin("settings", false);
  preferences.putUChar(KEY_SETVIEW,pSetting->settingsView);
  preferences.putString(KEY_ACESSPOINT_PASSWORD,pSetting->wifi.appw);
  preferences.putUChar(KEY_BOARDTYPE,pSetting->boardType);
  preferences.putUChar(KEY_CPUFREQU,pSetting->CPUFrequency);
  preferences.putUChar(KEY_EXTPWSW,pSetting->bHasExtPowerSw);
  preferences.putUChar(KEY_RFM,pSetting->RFMode);
  preferences.putUChar(KEY_AWLIVE,pSetting->awLiveTracking);
  preferences.putUChar(KEY_OSerial,pSetting->bOutputSerial);
  preferences.putUChar(KEY_OVario,pSetting->outputModeVario);
  preferences.putUChar(KEY_OFLARM,pSetting->outputFLARM);
  preferences.putUChar(KEY_OGPS,pSetting->outputGPS);
  preferences.putUChar(KEY_OFANET,pSetting->outputFANET);
  preferences.putString(KEY_PILOTNAME,pSetting->PilotName);
  preferences.putString(KEY_myDevId,pSetting->myDevId);
  preferences.putULong(KEY_myDevIdType,pSetting->myDevIdType);
  preferences.putBool(KEY_customGPSConfig,pSetting->gps.customGPSConfig);
  preferences.putUChar(KEY_WIFI_MODE,pSetting->wifi.uMode.mode);
  preferences.putUChar(KEY_WIFI_CONNECT,pSetting->wifi.connect);
  preferences.putString(KEY_WIFI_SSID,pSetting->wifi.ssid);
  preferences.putString(KEY_WIFI_PW,pSetting->wifi.password);
  preferences.putUChar(KEY_AIRCRAFTTYPE,uint8_t(pSetting->AircraftType));
  preferences.putUInt(KEY_WIFI_AP_STOP,pSetting->wifi.tWifiApStop);
  preferences.putUInt(KEY_WIFI_STA_STOP,pSetting->wifi.tWifiStaStop);
  preferences.putString(KEY_UDP_SERVER,pSetting->UDPServerIP); //UDP-IP-Adress for sending Packets
  preferences.putUInt(KEY_UDP_PORT,pSetting->UDPSendPort); //Port of udp-server
  preferences.putUChar(KEY_OutputMode,pSetting->outputMode);
  preferences.putUChar(KEY_Mode,pSetting->Mode);
  preferences.putUChar(KEY_fntMode,pSetting->fanetMode);
  preferences.putUInt(KEY_fntPin,pSetting->fanetpin);
  preferences.putUChar(KEY_AUTOUPDATE,pSetting->bAutoupdate); //auto-update

 //GS Settings
  preferences.putFloat(KEY_GSLAT,pSetting->gs.lat);
  preferences.putFloat(KEY_GSLON,pSetting->gs.lon);
  preferences.putFloat(KEY_GSALT,pSetting->gs.alt);
  preferences.putFloat(KEY_GSGEOALT,pSetting->gs.geoidAlt);
  preferences.putUChar(KEY_GSSCR,pSetting->gs.SreenOption);
  preferences.putUChar(KEY_GSPS,pSetting->gs.PowerSave);
  preferences.putInt(KEY_GsSrO,pSetting->gs.sunriseOffset);
  preferences.putInt(KEY_GsSsO,pSetting->gs.sunsetOffset);
  preferences.putUChar(KEY_GSANEO,pSetting->wd.anemometer.AnemometerType);
  preferences.putUChar(KEY_WDANEOADSGAIN,pSetting->wd.anemometer.AnemometerAdsGain);
  preferences.putFloat(KEY_WDANEOADSVDIVR1,pSetting->wd.anemometer.AnemometerAdsVDivR1);
  preferences.putFloat(KEY_WDANEOADSVDIVR2,pSetting->wd.anemometer.AnemometerAdsVDivR2);
  preferences.putFloat(KEY_WDANEOADSWSMINV, pSetting->wd.anemometer.AnemometerAdsWSpeedMinVoltage);
  preferences.putFloat(KEY_WDANEOADSWSMAXV, pSetting->wd.anemometer.AnemometerAdsWSpeedMaxVoltage);
  preferences.putFloat(KEY_WDANEOADSWDMINV, pSetting->wd.anemometer.AnemometerAdsWDirMinVoltage);
  preferences.putFloat(KEY_WDANEOADSWDMAXV, pSetting->wd.anemometer.AnemometerAdsWDirMaxVoltage);
  preferences.putFloat(KEY_WDANEOADSWSMINS, pSetting->wd.anemometer.AnemometerAdsWSpeedMinSpeed);
  preferences.putFloat(KEY_WDANEOADSWSMAXS, pSetting->wd.anemometer.AnemometerAdsWSpeedMaxSpeed);
  preferences.putFloat(KEY_WDANEOADSWDMIND, pSetting->wd.anemometer.AnemometerAdsWDirMinDir);
  preferences.putFloat(KEY_WDANEOADSWDMAXD, pSetting->wd.anemometer.AnemometerAdsWDirMaxDir);
  preferences.putUChar(KEY_BattMinPerc,pSetting->minBattPercent);
  preferences.putUChar(KEY_restartBattPerc,pSetting->restartBattPercent);
  
  preferences.putULong(KEY_F2WuF0,pSetting->FntWuUpload[0].FanetId);
  preferences.putULong(KEY_F2WuF1,pSetting->FntWuUpload[1].FanetId);
  preferences.putULong(KEY_F2WuF2,pSetting->FntWuUpload[2].FanetId);
  preferences.putULong(KEY_F2WuF3,pSetting->FntWuUpload[3].FanetId);
  preferences.putULong(KEY_F2WuF4,pSetting->FntWuUpload[4].FanetId);
  preferences.putString(KEY_F2WuI0,pSetting->FntWuUpload[0].ID);
  preferences.putString(KEY_F2WuI1,pSetting->FntWuUpload[1].ID);
  preferences.putString(KEY_F2WuI2,pSetting->FntWuUpload[2].ID);
  preferences.putString(KEY_F2WuI3,pSetting->FntWuUpload[3].ID);
  preferences.putString(KEY_F2WuI4,pSetting->FntWuUpload[4].ID);
  preferences.putString(KEY_F2WuK0,pSetting->FntWuUpload[0].KEY);
  preferences.putString(KEY_F2WuK1,pSetting->FntWuUpload[1].KEY);
  preferences.putString(KEY_F2WuK2,pSetting->FntWuUpload[2].KEY);
  preferences.putString(KEY_F2WuK3,pSetting->FntWuUpload[3].KEY);
  preferences.putString(KEY_F2WuK4,pSetting->FntWuUpload[4].KEY);
  preferences.putULong(KEY_F2WiF0,pSetting->FntWiUpload[0].FanetId);
  preferences.putULong(KEY_F2WiF1,pSetting->FntWiUpload[1].FanetId);
  preferences.putULong(KEY_F2WiF2,pSetting->FntWiUpload[2].FanetId);
  preferences.putULong(KEY_F2WiF3,pSetting->FntWiUpload[3].FanetId);
  preferences.putULong(KEY_F2WiF4,pSetting->FntWiUpload[4].FanetId);
  preferences.putString(KEY_F2WiI0,pSetting->FntWiUpload[0].ID);
  preferences.putString(KEY_F2WiI1,pSetting->FntWiUpload[1].ID);
  preferences.putString(KEY_F2WiI2,pSetting->FntWiUpload[2].ID);
  preferences.putString(KEY_F2WiI3,pSetting->FntWiUpload[3].ID);
  preferences.putString(KEY_F2WiI4,pSetting->FntWiUpload[4].ID);
  preferences.putString(KEY_F2WiK0,pSetting->FntWiUpload[0].KEY);
  preferences.putString(KEY_F2WiK1,pSetting->FntWiUpload[1].KEY);
  preferences.putString(KEY_F2WiK2,pSetting->FntWiUpload[2].KEY);
  preferences.putString(KEY_F2WiK3,pSetting->FntWiUpload[3].KEY);
  preferences.putString(KEY_F2WiK4,pSetting->FntWiUpload[4].KEY);

 //live-tracking
  preferences.putUChar(KEY_OGN_LIVE,pSetting->OGNLiveTracking.mode);
  preferences.putUChar(KEY_Display,pSetting->displayType);
  preferences.putUChar(KEY_DispRot,pSetting->displayRotation);
  preferences.putUChar(KEY_TRACCAR_LIVE,pSetting->traccarLiveTracking);
  preferences.putString(KEY_TRACCAR_SRV,pSetting->TraccarSrv);
  

 //vario
  preferences.putFloat(KEY_vSinkTh,pSetting->vario.sinkingThreshold);
  preferences.putFloat(KEY_vClimbTh,pSetting->vario.climbingThreshold);
  preferences.putFloat(KEY_vNClimbSens,pSetting->vario.nearClimbingSensitivity);
  preferences.putUChar(KEY_VarioVolume,pSetting->vario.volume);
  preferences.putUChar(KEY_VBeepFlying,pSetting->vario.BeepOnlyWhenFlying);
  preferences.putUChar(KEY_useMPU,pSetting->vario.useMPU);
  preferences.putFloat(KEY_vTOffs,pSetting->vario.tempOffset);
  preferences.putFloat(KEY_vSigmaP,pSetting->vario.sigmaP);
  preferences.putFloat(KEY_vSigmaA,pSetting->vario.sigmaA);

 //weathersettings
  preferences.putUChar(KEY_WsMode,pSetting->wd.mode.mode);
  preferences.putUChar(KEY_FanetWeather,pSetting->wd.sendFanet);
  preferences.putFloat(KEY_wdTempOffset,pSetting->wd.tempOffset);
  preferences.putInt(KEY_wdWDirOffset,pSetting->wd.windDirOffset);
  preferences.putFloat(KEY_avgFanet,pSetting->wd.avgFactorFanet);
  preferences.putULong(KEY_FanetWDInt,pSetting->wd.FanetUploadInterval);
  preferences.putFloat(KEY_avgWU,pSetting->wd.avgFactorWU);
  preferences.putULong(KEY_WUIntervall,pSetting->wd.WUUploadIntervall);

 //wu-upload
  preferences.putUChar(KEY_WUUlEnable,pSetting->WUUpload.enable);
  preferences.putString(KEY_WUUlID,pSetting->WUUpload.ID);
  preferences.putString(KEY_WUUlKEY,pSetting->WUUpload.KEY);

 //windy-upload
  preferences.putUChar(KEY_WIUlEnable,pSetting->WindyUpload.enable);
  preferences.putString(KEY_WIUlID,pSetting->WindyUpload.ID);
  preferences.putString(KEY_WIUlKEY,pSetting->WindyUpload.KEY);

 //gsm
  preferences.putString(KEY_GSMAPN,pSetting->gsm.apn);
  preferences.putString(KEY_GSMUSER,pSetting->gsm.user);
  preferences.putString(KEY_GSMKEY,pSetting->gsm.pwd);
  preferences.putUChar(KEY_GSMMODE,pSetting->gsm.NetworkMode);
  preferences.putUChar(KEY_GSMPREF,pSetting->gsm.PreferredMode);
  preferences.putString(KEY_NBIOT,pSetting->gsm.NB_IOT_Band);
  preferences.putString(KEY_CATM,pSetting->gsm.CAT_M_Band);

  //fuel-sensor
  preferences.putUChar(KEY_fuelSensor,pSetting->bHasFuelSensor);

 //mqtt
  preferences.putUChar(KEY_MqttEn,pSetting->mqtt.mode.mode);
  preferences.putString(KEY_MqttServer,pSetting->mqtt.server);
  preferences.putInt(KEY_MqttPort,pSetting->mqtt.port);
  preferences.putString(KEY_MqttPw,pSetting->mqtt.pw);

  preferences.end();

 //vario
  preferences.begin("fastvario", false);
  if (pSetting->vario.accel[0] != 0 || pSetting->vario.accel[1] != 0 || pSetting->vario.accel[2] != 0){
    preferences.putInt(KEY_axOffset, pSetting->vario.accel[0]);
    preferences.putInt(KEY_ayOffset, pSetting->vario.accel[1]);
    preferences.putInt(KEY_azOffset, pSetting->vario.accel[2]);
  }
  if (pSetting->vario.gyro[0] != 0 || pSetting->vario.gyro[1] != 0 || pSetting->vario.gyro[2] != 0){
    preferences.putInt(KEY_gxOffset, pSetting->vario.gyro[0]);
    preferences.putInt(KEY_gyOffset, pSetting->vario.gyro[1]);
    preferences.putInt(KEY_gzOffset, pSetting->vario.gyro[2]);
  }
  preferences.putFloat(KEY_t0,pSetting->vario.tValues[0]);
  preferences.putFloat(KEY_t1,pSetting->vario.tValues[1]);
  preferences.putFloat(KEY_z0,pSetting->vario.zValues[0]);
  preferences.putFloat(KEY_z1,pSetting->vario.zValues[1]);
  preferences.end();
}

void write_screenNumber(){
 log_i("WRITE CONFIG FILE");
  preferences.begin("settings", false);
  preferences.putUChar(KEY_SCREEN,setting.screenNumber);
  preferences.end();
}

void write_Volume(){
 log_i("WRITE vario volume");
  preferences.begin("settings", false);
  preferences.putUChar(KEY_VarioVolume,setting.vario.volume);
  preferences.end();
}

void write_PilotName(){
  preferences.begin("settings", false);
  preferences.putString(KEY_PILOTNAME,setting.PilotName);
  preferences.end();
}
void write_AircraftType(){
  preferences.begin("settings", false);
  preferences.putUChar(KEY_AIRCRAFTTYPE,uint8_t(setting.AircraftType));
  preferences.end();
}

void write_AirMode(){
  preferences.begin("settings", false);
  preferences.putUChar(KEY_fntMode,setting.fanetMode);
  preferences.end();
}

void write_Mode(){
  preferences.begin("settings", false);
  preferences.putUChar(KEY_Mode,setting.Mode);
  preferences.end();
}

void write_RFMode(){
  preferences.begin("settings", false);
  preferences.putUChar(KEY_RFM,setting.RFMode);
  preferences.end();
}

void write_OutputMode(){
  preferences.begin("settings", false);
  preferences.putUChar(KEY_OutputMode,setting.outputMode);
  preferences.end();
}

void write_fuelsensor(){
  preferences.begin("settings", false);
  preferences.putUChar(KEY_fuelSensor,setting.bHasFuelSensor);
  preferences.end();
}

void write_battOffset(){
  preferences.begin("settings", false);
  preferences.putFloat(KEY_BATOFFS,setting.BattVoltOffs);
  preferences.end();
}

void write_battMinPerc(){
  preferences.begin("settings", false);
  preferences.putUChar(KEY_BattMinPerc,setting.minBattPercent);
  preferences.end();
}

void write_gpsBaud(){
  log_i("write new GPS-Baudrate=%d",setting.gps.Baud);
  preferences.begin("settings", false);
  preferences.putULong(KEY_GPSBAUD,setting.gps.Baud);
  preferences.end();
}

void write_wifiModeBits(){
  log_i("write new wifi mode bits=%d",setting.wifi.uMode.mode);
  preferences.begin("settings", false);
  preferences.putUChar(KEY_WIFI_MODE,setting.wifi.uMode.mode);
  preferences.end(); 
}

void write_CPUFrequency(){
  preferences.begin("settings", false);
  preferences.putUChar(KEY_CPUFREQU,setting.CPUFrequency);
  preferences.end(); 
}
