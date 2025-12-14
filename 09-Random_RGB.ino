/*
Generates a random number when a momentary button is pressed.
Random number is displayed in the Serial Monitor.
Button is external, and is connected to pin D2.
*/

// define macros for pin numbers so the code is easier to understand
#define BUTTON_PIN 2
#define LED_R 9
#define LED_G 10
#define LED_B 11

// global variable to store the button state
int buttonState;  //must be int because digitalRead() function returns an int!

// global variables to store the randomly generated numbers
int randNumber_R;
int randNumber_G;
int randNumber_B;

// the setup function runs once when you press reset or power the board
void setup() {
  // set up the LED pins
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

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
    randNumber_R = random(256); // generate random numbers from 0 - 255
    randNumber_G = random(256);
    randNumber_B = random(256);

    analogWrite(LED_R, randNumber_R);  // update PWM latches with random numbers
    analogWrite(LED_G, randNumber_G);
    analogWrite(LED_B, randNumber_B);

    Serial.print("HTML Colour Code = #");   // print the HTML colour code on the serial monitor
    Serial.print(randNumber_R < 16 ? "0" : "");
    Serial.print(randNumber_R, HEX);
    Serial.print(randNumber_G < 16 ? "0" : "");
    Serial.print(randNumber_G, HEX);
    Serial.print(randNumber_B < 16 ? "0" : "");
    Serial.println(randNumber_B, HEX);
  }
  else  // button has not been pressed --> default state
  {
    Serial.println("Button is not pressed.");
    digitalWrite(LED_R, LOW);  // turn the red LED off
    digitalWrite(LED_G, LOW);  // turn the green LED off
    digitalWrite(LED_B, LOW);  // turn the blue LED off
  }

  delay(1000);                 // wait for 500ms
}
