#ifndef _H_JOYSTICK_FUNCTIONS_H_
#define _H_JOYSTICK_FUNCTIONS_H_
    // Checks the Digital Pin for a value to be used as a Button value. Only updates the state if it
    // has been found to have changed. Will update the Joystick Button based on which pin it is currently
    // looking at
    void updateDigitalPinState(uint8_t pinIndex, uint8_t digitalPins[], uint8_t digitalPinStates[]) {
        uint8_t digitalPin = digitalPins[pinIndex];

        // When using the Internal Pull Up Resistors, logic for Digital Pins is inverted
        uint8_t currentState = digitalRead(digitalPin) == HIGH ? 0 : 1;

        if(currentState != digitalPinStates[pinIndex]) {
            Joystick.setButton(pinIndex, currentState);
            digitalPinStates[pinIndex] = currentState;
        }
    }

    // Checks the Analog Pin for a value to be used as the Axis value. Only updates the state if it
    // has been found to have changed. Will update the Joystick Axis based on which pin it is currently
    // looking at
    void updateAnalogPinStates(uint8_t pinIndex, uint8_t analogPins[], int analogPinVals[]) {
        uint8_t analogPin = analogPins[pinIndex];
        int lastAnalogPinVal = analogPinVals[pinIndex];

        // The trick when using multiple analog sensors is to read them twice, with a small delay after each read (10ms is good)
        // then discard the first reading. This is because the ADC multiplexer needs switching time and the voltage needs 
        // time to stabilize after switching.
        int currentAnalogVal = analogRead(analogPin);
        delay(10);
        currentAnalogVal = analogRead(analogPin);
        delay(10);

        if(currentAnalogVal <= lastAnalogPinVal - 5 || currentAnalogVal >= lastAnalogPinVal + 5) {
            switch(analogPin) {
                case X_AXIS_PIN:
                    Joystick.setXAxis(currentAnalogVal);
                    break;
                case Y_AXIS_PIN:
                    Joystick.setYAxis(currentAnalogVal);
                    break;
                case Z_AXIS_PIN:
                    Joystick.setZAxis(currentAnalogVal);
                    break;
                case X_ROTATION_PIN:
                    Joystick.setRxAxis(currentAnalogVal);
                    break;
                case Y_ROTATION_PIN:
                    Joystick.setRyAxis(currentAnalogVal);
                    break;
                case Z_ROTATION_PIN:
                    Joystick.setRzAxis(currentAnalogVal);
                    break;
            }
            analogPinVals[pinIndex] = currentAnalogVal;
        }
    }
#endif