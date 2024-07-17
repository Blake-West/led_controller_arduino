#include <Adafruit_MCP23X17.h>

#define LED_PIN 0     // MCP23XXX pin LED is attached to

// only used for SPI
#define CS_PIN 6

#define NUM_LAYER_PINS 4
#define NUM_MCP_GPIO_PINS 16

class LedController {
  public:
    LedController();
    LedController(int mcp_cs_pin, int copi_pin = 11, int cipo_pin = 12, int sck_pin = 13);
    void begin(int mcp_cs_pin);
    void run_loop();
  private:
    void _initialize_cube_pins();
    void _initialize_mcp(int mcp_pin);
    void _test_cube();

    int _mcp_cs_pin;
    int _copi_pin;
    int _cipo_pin;
    int _sck_pin;

    const int _layer_pins[NUM_LAYER_PINS] = {7,6,5,4};
    const int _column_pins[NUM_MCP_GPIO_PINS] = 
        //{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        
        // {11,10,9,8, 3,1,2,0,15,14,13,12, 4,6,5,7,};
        {11,10,9,8,15,13,14,12, 0,1,2,3,4,5,6,7};

    const int _reset_pin = 2;

    const int _4x4_grid_column_pins[4][4] = {
        {11, 10, 9, 8},
        {9, 8, 15, 13},
        {0, 1, 2, 3},
        {4, 5, 6, 7}
    };
    Adafruit_MCP23X17 mcp;
};