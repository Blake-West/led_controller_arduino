#include <Adafruit_MCP23X17.h>
#include "pitches.h"
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
    void play_music();
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
    const int _speaker_pin = 9;

    const int _4x4_grid_column_pins[4][4] = {
        {11, 10, 9, 8},
        {9, 8, 15, 13},
        {0, 1, 2, 3},
        {4, 5, 6, 7}
    };
    Adafruit_MCP23X17 mcp;

    const int R = 0;
    const int E_ms = 150;
    const int Q_ms = 300;
    const int DQ_ms = 450;
    const int W_ms = 600;
    const int wait_5 = 750;

    static const int music_notes = 132;
    const int _music [music_notes * 2] = {
        NOTE_G3, Q_ms,
        NOTE_F3, E_ms,
        NOTE_DS3, Q_ms,
        NOTE_DS3, E_ms,
        NOTE_DS3, Q_ms,
        NOTE_F3, E_ms,
        NOTE_G3, Q_ms,
        NOTE_G3, E_ms,
        NOTE_G3, E_ms,
        NOTE_F3, E_ms,
        NOTE_DS3, E_ms, //
        NOTE_F3, E_ms,
        NOTE_G3, E_ms,
        NOTE_F3, Q_ms,
        NOTE_DS3, E_ms,
        NOTE_D3, E_ms,
        NOTE_DS3, W_ms,
        NOTE_F3, E_ms,
        NOTE_G3, Q_ms,
        NOTE_G3, E_ms,
        NOTE_G3, Q_ms,
        NOTE_GS3, E_ms,
        NOTE_AS4, Q_ms,
        NOTE_AS4, E_ms,
        NOTE_AS4, Q_ms,
        NOTE_AS4, E_ms, //
        NOTE_F3, E_ms,
        NOTE_F3, E_ms,
        NOTE_F3, Q_ms,
        NOTE_F3, E_ms,
        NOTE_F3, W_ms,
        NOTE_AS4, E_ms,
        NOTE_C4 -1, Q_ms,
        NOTE_GS3, E_ms,
        NOTE_C4 -1, Q_ms,
        NOTE_GS3, E_ms,
        NOTE_DS4, W_ms,
        R, E_ms,
        NOTE_C4 -1, E_ms, //

        NOTE_AS4, Q_ms,
        NOTE_C4 -1, E_ms,
        NOTE_AS4, Q_ms,
        NOTE_G3, E_ms,
        NOTE_AS4, Q_ms,
        R, E_ms,
        NOTE_G3, Q_ms,
        NOTE_F3, E_ms,
        NOTE_DS3, Q_ms,
        NOTE_DS3, E_ms,
        NOTE_DS3, Q_ms,
        NOTE_F3, E_ms,
        NOTE_G3, Q_ms,
        NOTE_G3, E_ms,
        NOTE_G3, E_ms,
        NOTE_F3, E_ms,
        NOTE_DS3, E_ms,//
        NOTE_F3, E_ms,
        NOTE_G3, E_ms,
        NOTE_F3, E_ms,
        NOTE_DS3, Q_ms,
        NOTE_D3, E_ms,
        NOTE_DS3, E_ms,
        R, E_ms,
        NOTE_F3, E_ms,
        NOTE_G3, Q_ms,
        NOTE_F3, E_ms,
        NOTE_DS3, Q_ms,// Chorus
        NOTE_DS3, E_ms,
        NOTE_DS3, Q_ms,
        NOTE_F3, E_ms,
        NOTE_G3, Q_ms,
        NOTE_G3, E_ms,
        NOTE_G3, E_ms,
        NOTE_F3, E_ms,
        NOTE_DS3, E_ms,
        NOTE_F3, E_ms,
        NOTE_G3, E_ms,
        NOTE_F3, E_ms,
        NOTE_DS3, Q_ms,
        NOTE_D3, E_ms,
        NOTE_DS3, W_ms,
        NOTE_F3, E_ms,
        NOTE_G3, E_ms,
        NOTE_G3, E_ms,
        NOTE_G3, E_ms,
        NOTE_G3, E_ms,
        NOTE_G3, E_ms,
        NOTE_GS3, E_ms,

        NOTE_AS4, E_ms,
        NOTE_AS4, E_ms,
        NOTE_AS4, E_ms,
        NOTE_AS4, E_ms,
        NOTE_AS4, E_ms,
        NOTE_AS4, E_ms,
        NOTE_AS4, E_ms,
        NOTE_F3, E_ms,
        NOTE_F3, E_ms,
        NOTE_F3, Q_ms,
        NOTE_F3, E_ms,
        NOTE_F3, W_ms,
        NOTE_AS4, E_ms,
        NOTE_C4 -1, Q_ms,
        NOTE_GS3, E_ms,
        NOTE_C4 -1, Q_ms,
        NOTE_GS3, E_ms,//
        NOTE_C4 -1, E_ms,
        NOTE_DS4, DQ_ms,
        R, E_ms,
        NOTE_C4 -1, E_ms,
        NOTE_AS4, E_ms,
        NOTE_C4 -1, E_ms,
        NOTE_AS4, E_ms,
        NOTE_G3, E_ms,
        NOTE_AS4, DQ_ms,
        NOTE_G3, Q_ms,
        NOTE_F3, E_ms,
        NOTE_DS3, Q_ms,
        NOTE_DS3, E_ms,
        NOTE_DS3, Q_ms,
        NOTE_F3, E_ms,//
        NOTE_G3, Q_ms,
        NOTE_G3, E_ms,
        NOTE_G3, E_ms,
        NOTE_F3, E_ms,
        NOTE_DS3, E_ms,
        NOTE_F3, E_ms,
        NOTE_G3, E_ms,
        NOTE_F3, E_ms,
        NOTE_DS3, Q_ms,
        NOTE_D3, E_ms,
        NOTE_DS3, W_ms};

};