/*--------------------------------------------------------------------
Name: Noah Whyrick
Date: 02/28/2025
Course: CSCE 336 Embedded Systems (Spring 2025)
File: main.cpp
HW/Lab: Lab 3/Project
Purp: Main entry point for the program
Doc: I helped no one and no people helped me.

Academic Integrity Statement: I certify that, while others may have
assisted me in brain storming, debugging and validating this program,
the program itself is my own work. I understand that submitting code
which is the work of other individuals is a violation of the honor
code. I also understand that if I knowingly give my original work to
another individual is also a violation of the honor code.
--------------------------------------------------------------------*/

#include <Arduino.h>
#include "include/servo.h"
#include "include/ultrasonic.h"

// Pin definitions
#define ONBOARD_LED 5

void initLED();

void setup() 
{
  // Debug: check if available (i.e. plugged in to laptop)
  Serial.begin(9200);
  Serial.println("Beginning startup sequence.");
  // Initialize and test onboard LED to test basic functionality
  initLED();
  // Initialize servo unit
  ServoUnit::initServo();
  Ultrasonic::initUltraSonic();
  Serial.println("Startup complete");
}

/**
 * Initializes and tests the onboard LED
 */
void initLED()
{
  Serial.println("Testing onboard LED");
  DDRD |= (1 << PD4); // Red LED
  DDRD |= (1 << PD5); // Green LED
  DDRB |= (1 << ONBOARD_LED); // Set to output
  PORTB &= ~(1 << ONBOARD_LED); // Turn off
  delay(400);
  PORTB |= (1 << ONBOARD_LED); // Turn on
  delay(400);
  PORTB &= ~(1 << ONBOARD_LED); // Turn off
  Serial.println("Done");
}

void loop() 
{ 
  ServoUnit::turn(21); // Ensure we start at the center

  double value = Ultrasonic::readTiming();
  double distance = (0.000001 * value) * 13543; // distance = time * velocity
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" in");
  if (distance <= 12)
  {
    PORTD |= (1 << PD4); // Set red LED high
    PORTD |= (1 << PD5); // Set green LED high
    _delay_ms(1000);
    PORTD &= ~(1 << PD4); // Set red LED low
    PORTD &= ~(1 << PD5); // Set green LED low
  }

  //ServoUnit::turn(37); // Left
  //value = Ultrasonic::readTiming();
  //distance = (0.000001 * value) * 13543;
  //if (distance <= 12)
  //{
  //  PORTD |= (1 << PD4); // Set red LED high
  //  _delay_ms(1000);
  //  PORTD &= ~(1 << PD4); // Set red LED low
  //}
//
  //ServoUnit::turn(7);
  //value = Ultrasonic::readTiming();
  //distance = (0.000001 * value) * 13543;
  //if (distance <= 12)
  //{
  //  PORTD |= (1 << PD5); // Set green LED high
  //  _delay_ms(1000);
  //  PORTD &= ~(1 << PD5); // Set green LED low
  //}
}//