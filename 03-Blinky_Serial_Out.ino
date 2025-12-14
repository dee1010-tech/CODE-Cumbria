/*
Turns an LED on for one second, then off for one second, repeatedly.
LED is external, and is connected to pin D9.
The state of the LED can be seen in the Serial Monitor (Tools --> Serial Monitor)
*/

// define a macro for the LED pin number so the code is easier to understand
#define LED_R 9

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_R, OUTPUT);

  // initialise the serial port
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_R, HIGH);  // turn the LED on (HIGH is the voltage level)
  Serial.println("LED: ON");  // print the text 'LED: ON' to the serial monitor followed by a new line (ln)
  delay(1000);                // wait for a second
  digitalWrite(LED_R, LOW);   // turn the LED off by making the voltage LOW
  Serial.println("LED: OFF"); // print the text 'LED: OFF' to the serial monitor followed by a new line (ln)
  delay(1000);                // wait for a second
}
