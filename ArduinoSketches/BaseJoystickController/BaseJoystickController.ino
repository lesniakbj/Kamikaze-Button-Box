/**
 * NOTE:
 *  This Joystick Example also Modified the Arduino Device defenitions in:
 *    C:\Program Files (x86)\Arduino\hardware\arduino\avr\boards.txt
 *  
 *  This was done in order to get Windows to display the device with a different name
 *  instead of the usual "Arduino Leonardo".
 */

#include <AStar32U4.h>
#include <Joystick.h>
#include "libraries/ControllerDefines.h"
#include "libraries/ControllerFunctions.h"

void setup() {
  // Setup the pins for the Digitial Pins
  for(uint8_t d = 0; d < TOTAL_BUTTONS; d++) {
    pinMode(digitalPins[d], INPUT);

    // Use the Internal Pull Up Resistors
    digitalWrite(digitalPins[d], HIGH);
  }
  
  // Setup pins for the Axis controls
  for(uint8_t a = 0; a < TOTAL_AXIS_PINS; a++) {
    pinMode(analogPins[a], INPUT);
  }

  // Setup Joystick
  Joystick.begin();
  Joystick.setXAxisRange(0, MAX_ANALOG_RESOLUTION);
  Joystick.setYAxisRange(0, MAX_ANALOG_RESOLUTION);
  Joystick.setZAxisRange(0, MAX_ANALOG_RESOLUTION);
  Joystick.setRxAxisRange(0, MAX_ANALOG_RESOLUTION);
  Joystick.setRyAxisRange(0, MAX_ANALOG_RESOLUTION);
  Joystick.setRzAxisRange(0, MAX_ANALOG_RESOLUTION);
}

void loop() {
  // Read all Digital Pin states and update the controller
  for(uint8_t d = 0; d < TOTAL_BUTTONS_EXT; d++) {
    updateDigitalPinState(d, digitalPins, digitalPinStates);
  }

  // Read the Analog Pins and update the controller 
  for(uint8_t a = 0; a < TOTAL_AXIS_PINS; a++) {
    updateAnalogPinStates(a, analogPins, analogPinVals);
  }

  // Delay before polling buttons again
  delay(50);
}
