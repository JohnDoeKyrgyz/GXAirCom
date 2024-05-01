#include "HT_DisplayAdapter.h"


HT_DisplayAdapter::HT_DisplayAdapter(ScreenDisplay &display) : GxEPD2_EPD(0, 0, 0, 0, 0, 0, 0, 0, GxEPD2::GDE0213B1,
                                                                          false, false, false) {
    this->_screen = &display;
}


void HT_DisplayAdapter::clearScreen(uint8_t value) {
    this->_screen->clear();
}


void HT_DisplayAdapter::hibernate() {

}


void HT_DisplayAdapter::powerOff() {

}


void HT_DisplayAdapter::refresh(int16_t x, int16_t y, int16_t w, int16_t h) {

}


void HT_DisplayAdapter::refresh(bool partial_update_mode) {

}


void HT_DisplayAdapter::drawNative(const uint8_t *data1, const uint8_t *data2, int16_t x, int16_t y,
                                   int16_t w, int16_t h, bool invert, bool mirror_y, bool pgm) {

}


void HT_DisplayAdapter::drawImagePart(const uint8_t *black, const uint8_t *color, int16_t x_part,
                                      int16_t y_part, int16_t w_bitmap, int16_t h_bitmap, int16_t x,
                                      int16_t y, int16_t w, int16_t h, bool invert, bool mirror_y,
                                      bool pgm) {

}


void
HT_DisplayAdapter::drawImage(const uint8_t *black, const uint8_t *color, int16_t x, int16_t y, int16_t w,
                             int16_t h, bool invert, bool mirror_y, bool pgm) {

}


void
HT_DisplayAdapter::drawImagePart(const uint8_t *bitmap, int16_t x_part, int16_t y_part, int16_t w_bitmap,
                                 int16_t h_bitmap, int16_t x, int16_t y, int16_t w, int16_t h,
                                 bool invert, bool mirror_y, bool pgm) {

}


void HT_DisplayAdapter::drawImage(const uint8_t *bitmap, int16_t x, int16_t y, int16_t w, int16_t h,
                                  bool invert, bool mirror_y, bool pgm) {

}


void HT_DisplayAdapter::writeNative(const uint8_t *data1, const uint8_t *data2, int16_t x, int16_t y,
                                    int16_t w, int16_t h, bool invert, bool mirror_y, bool pgm) {

}


void HT_DisplayAdapter::writeImagePart(const uint8_t *black, const uint8_t *color, int16_t x_part,
                                       int16_t y_part, int16_t w_bitmap, int16_t h_bitmap, int16_t x,
                                       int16_t y, int16_t w, int16_t h, bool invert, bool mirror_y,
                                       bool pgm) {

}


void HT_DisplayAdapter::writeImage(const uint8_t *black, const uint8_t *color, int16_t x, int16_t y,
                                   int16_t w, int16_t h, bool invert, bool mirror_y, bool pgm) {

}


void HT_DisplayAdapter::writeImagePart(
        const uint8_t *bitmap, int16_t x_part, int16_t y_part,
        int16_t w_bitmap, int16_t h_bitmap, int16_t x, int16_t y,
        int16_t w, int16_t h, bool invert, bool mirror_y, bool pgm) {

}


void HT_DisplayAdapter::writeImage(const uint8_t *bitmap, int16_t x, int16_t y, int16_t w, int16_t h, bool invert,
                                   bool mirror_y, bool pgm) {

}


void HT_DisplayAdapter::writeScreenBuffer(uint8_t value) {

}
