/*
Turns an LED on for one second, then off for one second, repeatedly.
LED is external, and is connected to pin D9.
*/

// define a macro for the LED pin number so the code is easier to understand
#define LED_R 9

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_R, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_R, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_R, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}