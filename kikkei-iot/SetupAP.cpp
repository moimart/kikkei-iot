/* Copyright (c) 2017 Kikkei Labs UG */
/* Author: Moises Martinez <moises@kikkei.com> */

#include "SetupAP.h"

kikkei::iot::SetupAP::SetupAP()
: _server(80)
{
}

void kikkei::iot::SetupAP::activate()
{
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP("KL_Sec", "kikkei");

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  _server.on("/", std::bind(&kikkei::iot::SetupAP::handleRoot,this));
  _server.begin();
  Serial.println("HTTP server started");
}

void kikkei::iot::SetupAP::tick()
{
  _server.handleClient();
}

void kikkei::iot::SetupAP::handleRoot()
{
  _server.send(200, "text/html", "<h1>You are connected</h1>");
}
