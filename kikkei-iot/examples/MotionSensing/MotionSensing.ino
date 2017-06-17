/*
   Copyright (c) 2017 Kikkei Labs UG
   Author: Moises Martinez <moises@kikkei.com>
*/

#include <MotionDetector.h>
#include <SetupAP.h>
#include <Settings.h>

kikkei::iot::TimeCounter timer;
kikkei::iot::MotionDetector motion_detector(&timer);
kikkei::iot::SetupAP setup_ap;
kikkei::iot::Settings wifi_settings;

void setup()
{
  EEPROM.begin(512);
  Serial.begin(115200);
  Serial.println("Starting....");
  wifi_settings.saveWiFi("xxxx","xxxx");

  if (true) //device setup
  {
    motion_detector.activate();
  }
  else
  {
    setup_ap.activate();
  }
}


void loop()
{
  timer.update();

  if (true)
    motion_detector.tick();
  else
    setup_ap.tick();
}
