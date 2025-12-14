/*
Ultrasonic distance meter with 3-level visual distance indicator.
Only runs while button is pressed. Visual indication is as follows:
Red: Close
Green: Medium
Blue: Far

HC-SR04 ultrasonic distance meter is connected on the following pins:
Trigger: D5
Echo: D4 via 1k resistor for protection

RGB LED is external:
Red is connected to pin D9
Green is connected to pin D10
Blue is connected to pin D11

Button is external, and is connected to pin D2.
*/

#include <HCSR04.h>

#define LED_R 9
#define LED_G 10
#define LED_B 11
#define BUTTON_PIN 2

byte triggerPin = 5;
byte echoPin = 4;

int buttonState;

void setup() {
  // set up the LED pins
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  // set up the button pin
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // enable the internal pullup resistor

  // set up the HC-SR04
  HCSR04.begin(triggerPin, echoPin);

  // set up the serial port
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  buttonState = digitalRead(BUTTON_PIN);

  if(buttonState == LOW)  // button is pressed
  {
    double* distances = HCSR04.measureDistanceMm();

    Serial.print(distances[0]);
    Serial.println(" mm");

    if(distances[0] > 100.0)
    {
      digitalWrite(LED_R, LOW);  // turn the red LED off
      digitalWrite(LED_G, LOW);  // turn the green LED off
      digitalWrite(LED_B, HIGH);  // turn the blue LED on
    }
    else if(distances[0] > 50.0 && distances[0] <= 100.0)
    {
      digitalWrite(LED_R, LOW);  // turn the red LED off
      digitalWrite(LED_G, HIGH);  // turn the green LED on
      digitalWrite(LED_B, LOW);  // turn the blue LED off
    }
    else  // distances[0] <= 50.0
    {
      digitalWrite(LED_R, HIGH);  // turn the red LED on
      digitalWrite(LED_G, LOW);  // turn the green LED off
      digitalWrite(LED_B, LOW);  // turn the blue LED off
    }
  }
  else  // button is not pressed - ensure all LEDs are off
  {
    digitalWrite(LED_R, LOW);  // turn the red LED off
    digitalWrite(LED_G, LOW);  // turn the green LED off
    digitalWrite(LED_B, LOW);  // turn the blue LED off
  }
  delay(250);   // wait for 250ms
}
