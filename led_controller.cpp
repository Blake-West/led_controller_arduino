#include "led_controller.h"



LedController::LedController() {
    this->_copi_pin = 11;
    this->_cipo_pin = 12;
    this->_sck_pin = 13;
};

LedController::LedController(int mcp_cs_pin, int copi_pin, int cipo_pin, int sck_pin) {

  this->_copi_pin = copi_pin;
  this->_mcp_cs_pin = mcp_cs_pin;
  this->_cipo_pin = cipo_pin;
  this->_sck_pin = sck_pin;
  
}

void LedController::begin(int mcp_cs_pin) {

  this->_initialize_mcp(mcp_cs_pin);
  this->_initialize_cube_pins();

  this->_test_cube();
}

void LedController::_test_cube() {
  int layer_pin = 0, column_pin = 0;

  for (int layer_index = 0; layer_index < NUM_LAYER_PINS; layer_index++) {
    layer_pin = this->_layer_pins[layer_index];
    digitalWrite(layer_pin, HIGH);

    for (int index = 0; index < NUM_MCP_GPIO_PINS; index = index + 1) {
      column_pin = this->_column_pins[index];

      Serial.print("blinking mcp column pin: " );
      Serial.println(column_pin);
      Serial.println(index);
      mcp.digitalWrite(column_pin, LOW);
      delay(50);
      mcp.digitalWrite(column_pin, HIGH);
      delay(50);
    }

    digitalWrite(layer_pin, LOW);
  }


  for (int x = 0; x < 4; ++x) {
    for (int y = 0; y < 4; ++y){
      mcp.digitalWrite(_4x4_grid_column_pins[x][y], LOW);
      delay(50);
      mcp.digitalWrite(_4x4_grid_column_pins[x][y], HIGH);
      delay(50);
    }
  }

}


void LedController::run_loop() {
  // Run our code that does stuff each loop;
  this->_test_cube();
};

void LedController::_initialize_cube_pins() {
  
  // Note the initialize_mcp should be called first

  // Initialize the arduino pins
  int led_layer_pin = 0;
  for (int index = 0; index < NUM_LAYER_PINS; ++index){
    // Get Layer pin from our exisisting pins defined in h
    led_layer_pin = this->_layer_pins[index];
    
    // set the arduino pins to output
    pinMode(led_layer_pin, OUTPUT);

    // Turn off the LED layers
    digitalWrite(led_layer_pin, LOW);
  }

  // Initialize

  int led_column_pin = 0;
  for (int index = 0; index < NUM_MCP_GPIO_PINS; index = index + 1) {
    led_column_pin = this->_column_pins[index];

    Serial.print("Setting mcp column pin: " );
    Serial.println(led_column_pin);
    mcp.pinMode(index, OUTPUT);
    mcp.digitalWrite(index, HIGH);
  }
}

void LedController::_initialize_mcp(int mcp_cs_pin) {
  pinMode(this->_reset_pin, OUTPUT);
  digitalWrite(this->_reset_pin, LOW);
  delay(100);
  digitalWrite(this->_reset_pin, HIGH);
  if (!(this->mcp.begin_SPI(mcp_cs_pin))) {
    while (1) {
      Serial.println("Error.");
    }
  }
}