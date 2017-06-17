/* Copyright (c) 2017 Kikkei Labs UG */
/* Author: Moises Martinez <moises@kikkei.com> */

#ifndef __KL_SETUP_AP_H__
#define __KL_SETUP_AP_H__

#include "Arduino.h"
#include "Timer.h"
#include <ESP8266WebServer.h>

namespace kikkei
{
namespace iot
{
  class SetupAP
  {
  public:
    SetupAP();
    void activate();

    void handleRoot();
    void tick();
  private:
    ESP8266WebServer _server;
  };
}
}

#endif
