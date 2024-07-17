#include "led_controller.h"

LedController led_controller;
int mcp_cs_pin = 10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  Serial.println("LED Cube test");
  led_controller.begin(mcp_cs_pin);
}

void loop() {
  // put your main code here, to run repeatedly


  led_controller.run_loop();

}
