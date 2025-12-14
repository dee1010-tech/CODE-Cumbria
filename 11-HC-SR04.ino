/*
HC-SR04 ultrasonic distance meter. Reports distance in mm.
Ultrasonic distance meter is connected on the following pins:
Trigger: D5
Echo: D4 via 1k resistor for protection
*/

// include library for the HC-SR04
#include <HCSR04.h>

// also possible to use variables to name pin numbers --> best practice to use 'const' if you use this method
const byte triggerPin = 5;
const byte echoPin = 4;

void setup() {
  // set up the HC-SR04
  HCSR04.begin(triggerPin, echoPin);

  // set up the serial port
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  double* distances = HCSR04.measureDistanceMm();   // declare a variable called 'distances' which points
                                                    // to the array where the measured distance is stored
  Serial.print(distances[0]);   // print the measured distance
  Serial.println(" mm");        // print the units then a new line

  delay(250);   // delay 250ms
}
