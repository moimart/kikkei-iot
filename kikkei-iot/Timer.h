/* Copyright (c) 2017 Kikkei Labs UG */
/* Author: Moises Martinez <moises@kikkei.com> */

#ifndef __KL_TIMER_H__
#define __KL_TIMER_H__

#include "Arduino.h"

namespace kikkei
{
namespace iot
{
  class TimeCounter
  {
    public:
      static TimeCounter* getGlobal();

      void update();
      unsigned long dt() const;
    private:
      unsigned long _pt { 0 };
      unsigned long _dt { 0 };
  };

  class Timer
  {
  public:
    Timer(unsigned long limit, const TimeCounter* counter);
    bool tick();
    bool flag() const;
    void activate();
  private:
    unsigned long _timer { 0 };
    bool _flag { false };
    unsigned long _limit;
    const TimeCounter* _counter;
  };
}
}

#endif
