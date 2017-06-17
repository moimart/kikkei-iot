/* Copyright (c) 2017 Kikkei Labs UG */
/* Author: Moises Martinez <moises@kikkei.com> */

#include "MotionDetector.h"
#include "Settings.h"

kikkei::iot::MotionDetector::MotionDetector(const kikkei::iot::TimeCounter* counter)
: _led_timer(1000,counter)
, _read_timer(5000,counter)
{

}

void kikkei::iot::MotionDetector::activate()
{
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  delay(2000);
}

void kikkei::iot::MotionDetector::tick()
{
  int val[2];

  bool led_on = _led_timer.tick();

  if (!_read_timer.tick())
  {
    val[0] = digitalRead(5);
    val[1] = digitalRead(4);

    if (val[0] || val[1])
    {
      _read_timer.activate();
      Serial.print("\nInitiating detection");
    }

    if (val[0])
      _pin_to_read = 4;

    if (val[1])
      _pin_to_read = 5;
  }
  else
  {
      val[0] = digitalRead(_pin_to_read);

      if (val[0])
      {
        Serial.print("\nMoving: ");
        Serial.println(_count++);
        _led_timer.activate();
        digitalWrite(LED_BUILTIN, LOW);
        connectToWifi();
      }
  }

  delay(1);
  digitalWrite(LED_BUILTIN,(led_on) ? LOW : HIGH);
}

void kikkei::iot::MotionDetector::connectToWifi()
{
  Settings settings;
  Serial.print("Connecting to Wifi with SSID ");
  Serial.println(settings.getSSID());

  WiFi.begin(settings.getSSID(),settings.getPassword());

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected!");
  delay(2000);
  Serial.println("disconnecting");
  WiFi.disconnect();
}
