#include <AStar32U4.h>
#include <Joystick.h>

#define TOTAL_BUTTONS 3
#define TOTAL_HATS 0

// Initialize the Joystick with the features we have
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
                    TOTAL_BUTTONS, TOTAL_HATS,
                    false, false, false,  // No X, Y or Z Axis
                    false, false, false,  // No X, Y, or Z Rotation Axis
                    false, false,         // No Rudder or Throttle
                    false, false, false); // No Accelerator, Brake, or Steering


// Initialize AStar32U4 Buttons and States
Pushbutton buttons[TOTAL_BUTTONS] = {
  Pushbutton(A_STAR_32U4_BUTTON_A),
  Pushbutton(A_STAR_32U4_BUTTON_B),
  Pushbutton(A_STAR_32U4_BUTTON_C)
};
uint8_t buttonStates[TOTAL_BUTTONS] = {0};

// ===============================
//        LOCAL FUNCTIONS
// ===============================

// Checks to see if a button is currently being pressed, and changes the state of the 
// button pressed if it has changed from the last time that we polled. This allows buttons
// to be pressed momentarily, or held down
void checkButtonState(uint8_t buttonNumber, Pushbutton button, uint8_t *lastButtonState) {
  uint8_t currentState = button.isPressed();
  if(currentState != lastButtonState) {
    Joystick.setButton(buttonNumber, currentState);
    *lastButtonState = currentState;
  }
}

// ===============================
//    GLOBAL (ENTRY) FUNCTIONS
// ===============================
void setup() {
  Joystick.begin();
}

void loop() {
  // Read all button states and update the controller
  for(uint8_t i = 0; i < TOTAL_BUTTONS; i++) {
    checkButtonState(i, buttons[i], &buttonStates[i]);
  }

  // Delay before polling buttons again
  delay(50);
}
