//
// Copyright (c) 2020 Fw-Box (https://fw-box.com)
// Author: Hartman Hsieh
//
// Description :
//   None
//
// Connections :
//
// Required Library :
//

#include "FwBox.h"


#define DEVICE_TYPE 19
#define FIRMWARE_VERSION "1.1"


//
// Global variable
//

void setup()
{
  Serial.begin(9600);

  //
  // Blink the LED when updating firmware.
  //
  //FwBoxIns.setGpioStatusLed(22); // TTGO T7 Mini32
  FwBoxIns.setGpioStatusLed(2); // AI-Thinker NodeMCU-32S

  //
  // Initialize the fw-box core (early stage)
  //
  fbEarlyBegin(DEVICE_TYPE, FIRMWARE_VERSION);

  //
  // Initialize the fw-box core
  //
  fbBegin(DEVICE_TYPE, FIRMWARE_VERSION);

  //
  // Setup MQTT subscribe callback
  //
  //setRcvValueCallback(onReceiveValue);
00
} // void setup()

void loop()
{

  //FwBoxIns.setValue(VAL_INDEX_LED, !digitalRead(LED_BUILTIN)); // This value is reverse

  //
  // Run the handle
  //
  fbHandle();

} // END OF "void loop()"
/*
void onReceiveValue(int valueIndex, String* payload)
{
  DBG_PRINT("onReceiveValue valueIndex = ");
  DBG_PRINTLN(valueIndex);
  DBG_PRINT("onReceiveValue *payload = ");
  DBG_PRINTLN(*payload);

  if(valueIndex == VAL_INDEX_LED) {
    if(payload->equals("ON") == true)
    {
      digitalWrite(LED_BUILTIN, LOW); // This value is reverse
    }
    else
    {
      digitalWrite(LED_BUILTIN, HIGH); // This value is reverse
    }
  }
}*/
