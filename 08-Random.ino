/*
Generates a random number when a momentary button is pressed.
Random number is displayed in the Serial Monitor.
Button is external, and is connected to pin D2.
*/

// define macros for pin numbers so the code is easier to understand
#define BUTTON_PIN 2

// global variable to store the button state
int buttonState;  //must be int because digitalRead() function returns an int!

// global variable to store the randomly generated number
int randNumber;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialise the button pin
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // enable the internal pullup resistor for this pin --> press the button to pull the pin to 0V (active low)

  // seed the random number generator
  randomSeed(analogRead(0));

  // initialise the serial port
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  
  buttonState = digitalRead(BUTTON_PIN);  // read and store the current state of the button
  Serial.print("buttonState=");
  Serial.println(buttonState);

  if(buttonState == LOW)  // low state means button has been pressed
  {
    randNumber = random(256); // generate a random number from 0 - 255

    Serial.print("Button is pressed! Random number: ");   // print the random number
    Serial.println(randNumber);
  }
  else  // button has not been pressed --> default state
  {
    Serial.println("Button is not pressed.");
  }

  delay(500);                 // wait for 500ms
}
