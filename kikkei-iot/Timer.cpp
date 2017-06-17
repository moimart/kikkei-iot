/* Copyright (c) 2017 Kikkei Labs UG */
/* Author: Moises Martinez <moises@kikkei.com> */

#include "Timer.h"

kikkei::iot::TimeCounter* kikkei::iot::TimeCounter::getGlobal()
{
    static TimeCounter* _tc = NULL;

    if (_tc == NULL)
      _tc = new TimeCounter();

    return _tc;
}

void kikkei::iot::TimeCounter::update()
{
  unsigned long _v = millis();
  _dt = _v - _pt;
  _pt = _v;
}

unsigned long kikkei::iot::TimeCounter::dt() const
{
  return _dt;
}

kikkei::iot::Timer::Timer(unsigned long limit, const TimeCounter* counter)
: _limit(limit)
, _counter(counter)
{
}

bool kikkei::iot::Timer::tick()
{
    if (!_flag)
      return false;

    _timer += _counter->dt();

    if (_timer >= _limit)
    {
        _flag = false;
        _timer = 0;
        return false;
    }

    return true;
}

bool kikkei::iot::Timer::flag() const
{
  return _flag;
}

void kikkei::iot::Timer::activate()
{
  _flag = true;
  _timer = 0;
}
