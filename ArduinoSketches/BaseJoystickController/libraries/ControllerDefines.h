#ifndef _H_JOYSTICK_DEFINES_H_

#define _H_JOYSTICK_DEFINES_H_
    #define DEFAULT_STATE 0

    #define MAX_ANALOG_RESOLUTION 1024
    
    #define TOTAL_AXIS_PINS 3
    #define TOTAL_ANALOG_OTHER 3
    #define TOTAL_ANALOG_PINS TOTAL_AXIS_PINS + TOTAL_ANALOG_OTHER

    #define X_AXIS_PIN A0
    #define Y_AXIS_PIN A1
    #define Z_AXIS_PIN A2
    #define X_ROTATION_PIN A3
    #define Y_ROTATION_PIN A4
    #define Z_ROTATION_PIN A5

    #define TOTAL_BUTTONS_EXT 6
    #define TOTAL_SWITCH_EXT 6
    #define TOTAL_BUTTONS TOTAL_BUTTONS_EXT + TOTAL_SWITCH_EXT

    #define EXT_BUTTON_ONE_PIN 0
    #define EXT_BUTTON_TWO_PIN 1
    #define EXT_BUTTON_THREE_PIN 2
    #define EXT_BUTTON_FOUR_PIN 3
    #define EXT_BUTTON_FIVE_PIN 4
    #define EXT_BUTTON_SIX_PIN 5

    #define EXT_SWITCH_ONE_PIN 6
    #define EXT_SWITCH_TWO_PIN 7
    #define EXT_SWITCH_THREE_PIN 8
    #define EXT_SWITCH_FOUR_PIN 9
    #define EXT_SWITCH_FIVE_PIN 10
    #define EXT_SWITCH_SIX_PIN 11

    #define TOTAL_HATS 0

    // Initialize the Joystick with the features we have
    Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
                        TOTAL_BUTTONS, TOTAL_HATS,
                        true, true, true,       // X, Y and Z axis
                        true, true, true,       // X, Y, or Z Rotation Axis
                        false, false,           // No Rudder or Throttle
                        false, false, false);   // No Accelerator, Brake, or Steering


    // Initialize AStar32U4 Analog Pins and States (for Axis Control)
    uint8_t analogPins[TOTAL_ANALOG_PINS] = {
        uint8_t(X_AXIS_PIN),
        uint8_t(Y_AXIS_PIN),
        uint8_t(Z_AXIS_PIN),
        uint8_t(X_ROTATION_PIN),
        uint8_t(Y_ROTATION_PIN),
        uint8_t(Z_ROTATION_PIN)
    };
    int analogPinVals[TOTAL_ANALOG_PINS] = {DEFAULT_STATE};

    // Initialize AStar32U4 Digial Pins (External Buttons and Switches) and States
    uint8_t digitalPins[TOTAL_BUTTONS] = {
        uint8_t(EXT_BUTTON_ONE_PIN),
        uint8_t(EXT_BUTTON_TWO_PIN),
        uint8_t(EXT_BUTTON_THREE_PIN),
        uint8_t(EXT_BUTTON_FOUR_PIN),
        uint8_t(EXT_BUTTON_FIVE_PIN),
        uint8_t(EXT_BUTTON_SIX_PIN),
        uint8_t(EXT_SWITCH_ONE_PIN),
        uint8_t(EXT_SWITCH_TWO_PIN),
        uint8_t(EXT_SWITCH_THREE_PIN),
        uint8_t(EXT_SWITCH_FOUR_PIN),
        uint8_t(EXT_SWITCH_FIVE_PIN),
        uint8_t(EXT_SWITCH_SIX_PIN)
    };
    uint8_t digitalPinStates[TOTAL_BUTTONS] = {DEFAULT_STATE};
#endif