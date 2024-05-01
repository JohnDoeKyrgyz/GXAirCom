#include "HT_DisplayAdapter.h"

template<const uint16_t height, const uint16_t width>
HT_DisplayAdapter<height, width>::HT_DisplayAdapter(ScreenDisplay &display) {
    this->_screen = display;
}

template<const uint16_t height, const uint16_t width>
void HT_DisplayAdapter<height, width>::clearScreen(uint8_t value) {
    this->_screen->clear();
}

template<const uint16_t height, const uint16_t width>
void HT_DisplayAdapter<height, width>::hibernate() {

}

template<const uint16_t height, const uint16_t width>
void HT_DisplayAdapter<height, width>::powerOff() {

}

template<const uint16_t height, const uint16_t width>
void HT_DisplayAdapter<height, width>::refresh(int16_t x, int16_t y, int16_t w, int16_t h) {

}

template<const uint16_t height, const uint16_t width>
void HT_DisplayAdapter<height, width>::refresh(bool partial_update_mode) {

}

template<const uint16_t height, const uint16_t width>
void HT_DisplayAdapter<height, width>::drawNative(const uint8_t *data1, const uint8_t *data2, int16_t x, int16_t y,
                                                  int16_t w, int16_t h, bool invert, bool mirror_y, bool pgm) {

}

template<const uint16_t height, const uint16_t width>
void HT_DisplayAdapter<height, width>::drawImagePart(const uint8_t *black, const uint8_t *color, int16_t x_part,
                                                     int16_t y_part, int16_t w_bitmap, int16_t h_bitmap, int16_t x,
                                                     int16_t y, int16_t w, int16_t h, bool invert, bool mirror_y,
                                                     bool pgm) {

}

template<const uint16_t height, const uint16_t width>
void
HT_DisplayAdapter<height, width>::drawImage(const uint8_t *black, const uint8_t *color, int16_t x, int16_t y, int16_t w,
                                            int16_t h, bool invert, bool mirror_y, bool pgm) {

}

template<const uint16_t height, const uint16_t width>
void
HT_DisplayAdapter<height, width>::drawImagePart(const uint8_t *bitmap, int16_t x_part, int16_t y_part, int16_t w_bitmap,
                                                int16_t h_bitmap, int16_t x, int16_t y, int16_t w, int16_t h,
                                                bool invert, bool mirror_y, bool pgm) {

}

template<const uint16_t height, const uint16_t width>
void HT_DisplayAdapter<height, width>::drawImage(const uint8_t *bitmap, int16_t x, int16_t y, int16_t w, int16_t h,
                                                 bool invert, bool mirror_y, bool pgm) {

}

template<const uint16_t height, const uint16_t width>
void HT_DisplayAdapter<height, width>::writeNative(const uint8_t *data1, const uint8_t *data2, int16_t x, int16_t y,
                                                   int16_t w, int16_t h, bool invert, bool mirror_y, bool pgm) {

}

template<const uint16_t height, const uint16_t width>
void HT_DisplayAdapter<height, width>::writeImagePart(const uint8_t *black, const uint8_t *color, int16_t x_part,
                                                      int16_t y_part, int16_t w_bitmap, int16_t h_bitmap, int16_t x,
                                                      int16_t y, int16_t w, int16_t h, bool invert, bool mirror_y,
                                                      bool pgm) {

}

template<const uint16_t height, const uint16_t width>
void HT_DisplayAdapter<height, width>::writeImage(const uint8_t *black, const uint8_t *color, int16_t x, int16_t y,
                                                  int16_t w, int16_t h, bool invert, bool mirror_y, bool pgm) {

}

template<const uint16_t height, const uint16_t width>
void HT_DisplayAdapter<height, width>::writeImagePart(const uint8_t *bitmap, int16_t x_part, int16_t y_part,
                                                      int16_t w_bitmap, int16_t h_bitmap, int16_t x, int16_t y,
                                                      int16_t w, int16_t h, bool invert, bool mirror_y, bool pgm) {

}

template<const uint16_t height, const uint16_t width>
void HT_DisplayAdapter<height, width>::writeImage(const uint8_t *bitmap, int16_t x, int16_t y, int16_t w, int16_t h,
                                                  bool invert, bool mirror_y, bool pgm) {

}

template<const uint16_t height, const uint16_t width>
void HT_DisplayAdapter<height, width>::writeScreenBuffer(uint8_t value) {

}
