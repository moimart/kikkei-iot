#include "Settings.h"

kikkei::iot::Settings::Settings()
{
  _ssid[0] = '\0';
  _passwd[0] = '\0';

  _addr_enabled = 0;
  _addr_ssid = 1;
  _addr_passwd = 34;

  byte buf = EEPROM.read(_addr_enabled);

  if (buf == 1)
    _enabled = true;

  for (int i = 0; i < 33; i++)
  {
    byte buf = EEPROM.read(_addr_ssid + i);
    _ssid[i] = (char)buf;
  }

  for (int i = 0; i < 64; i++)
  {
    byte buf = EEPROM.read(_addr_passwd + i);
    _passwd[i] = (char)buf;
  }

  delay(500);
}

void kikkei::iot::Settings::saveWiFi(const char* ssid, const char* passwd)
{
  int i = 0;
  do
  {
    EEPROM.write(_addr_ssid + i,(byte)ssid[i]);
  }
  while (ssid[i++] != '\0');

  i = 0;
  do
  {
    EEPROM.write(_addr_passwd + i,(byte)passwd[i]);
  }
  while (passwd[i++] != '\0');

  delay(500);
}

const char* kikkei::iot::Settings::getSSID()
{
  return _ssid;
}

const char* kikkei::iot::Settings::getPassword()
{
  return _passwd;
}
