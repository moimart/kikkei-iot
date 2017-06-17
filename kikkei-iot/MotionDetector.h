/* Copyright (c) 2017 Kikkei Labs UG */
/* Author: Moises Martinez <moises@kikkei.com> */

#ifndef __KL_MOTION_DETECTOR_H__
#define __KL_MOTION_DETECTOR_H__

#include "Arduino.h"
#include "Timer.h"
#include <ESP8266WiFi.h>

namespace kikkei
{
namespace iot
{
  class MotionDetector
  {
  public:
    MotionDetector(const TimeCounter* counter);
    void activate();
    void tick();
  private:
    void connectToWifi();
    int _pin_to_read { - 1 };

    Timer _led_timer;
    Timer _read_timer;

    unsigned int _count { 0 };
  };
}
}

#endif
