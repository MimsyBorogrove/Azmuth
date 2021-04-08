#ifndef AZMUTH_H
#define AZMUTH_H

#include "RTClib.h"
#include "Adafruit_NeoPixel.h"
#include "JC_Button.h"

extern RTC_DS3231 rtc;
extern Adafruit_NeoPixel ring;
extern Button buttonMain;
extern Button buttonLeft;
extern Button buttonRight;

extern const byte RING_PIN;
extern const byte LED_COUNT;
extern const byte MAIN_BUTTON_PIN;
extern const byte LEFT_BUTTON_PIN;
extern const byte RIGHT_BUTTON_PIN;

#endif
