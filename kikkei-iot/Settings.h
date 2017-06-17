/* Copyright (c) 2017 Kikkei Labs UG */
/* Author: Moises Martinez <moises@kikkei.com> */

#ifndef __KL_SETTINGS_H__
#define __KL_SETTINGS_H__

#include "Arduino.h"
#include <EEPROM.h>

namespace kikkei
{
namespace iot
{
  class Settings
  {
  public:
    Settings();
    void saveWiFi(const char* ssid, const char* passwd);

    const char* getSSID();
    const char* getPassword();
  private:
    bool _enabled { false };
    char _ssid[33];
    char _passwd[64];

    int _addr_enabled;
    int _addr_ssid;
    int _addr_passwd;
  };
}
}

#endif
