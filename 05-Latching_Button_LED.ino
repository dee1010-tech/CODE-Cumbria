/*
Toggles an LED on and off every time a momentary button is pressed.
LED is external, and is connected to pin D9.
Button is external, and is connected to pin D2.
*/

// define macros for pin numbers so the code is easier to understand
#define LED_R 9
#define BUTTON_PIN 2

// global variable to store the button state
int newButtonState = 0;  //must be int because digitalRead() function returns an int!
int oldButtonState = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialise the LED pins
  pinMode(LED_R, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // enable the internal pullup resistor for this pin --> press the button to pull the pin to 0V (active low)

  // initialise the serial port
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  
  newButtonState = digitalRead(BUTTON_PIN);  // read and store the current state of the button
  Serial.print("newButtonState = ");
  Serial.println(newButtonState);

  if(newButtonState != oldButtonState)  // button has changed state
  {
    oldButtonState = newButtonState;  // update the button state so the change can be detected next time

    if(newButtonState == LOW)
    {
      digitalWrite(LED_R, !digitalRead(LED_R));  // invert the state of the LED pin
      Serial.println("LED STATE INVERTED");
    }
  }

  delay(250);                 // wait for 250ms
}
