/*
  AntiKeyRepetition Library - Blink

 The circuit:
 * Key(Button) pin to digital pin 12
*/

// Include the library code:
#include <AntiKeyRepetition.h>

// Initialize the library by associating arduino digital pin 12.
AntiKeyRepetition key(12);

// Set the state of a bool variable storage led (low by default).
boolean led = LOW;

void setup() {
  // Initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // Start the serial debug output.
  Serial.begin(9600);
}

void loop() {
  // Call the getAccessState() function.
  // The return value of this function is boolean type,
  // and if TRUE, it means that the key has a valid trigger.
  // (including a full bounce and press, the value is set to
  // TRUE after pressing)
  if(key.getAccessState() == 1) {
    // Reverses the value of the led variable.
    led = !led;
    // Call the delAccess() function.
    // This function resets the return value of
    // the getAccessState() function to FALSE.
    key.delAccess();
  }

  // Set the status of the LED.
  digitalWrite(LED_BUILTIN, led);
  // Output the current LED status in the serial debugger.
  Serial.print("LED = ");
  Serial.println(led);
}
