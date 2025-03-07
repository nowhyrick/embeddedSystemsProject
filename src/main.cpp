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

// Register definitions
#define PINB_Reg (*((volatile uint8_t *) 0x23))
#define DDRB_Reg (*((volatile uint8_t *) 0x24))
#define PORTB_Reg (*((volatile uint8_t *) 0x25))

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
  Serial.println("Startup complete");
}

/**
 * Initializes and tests the onboard LED
 */
void initLED()
{
  Serial.println("Testing onboard LED");
  DDRB_Reg |= (1 << ONBOARD_LED); // Set to output
  PORTB_Reg &= ~(1 << ONBOARD_LED); // Turn off
  delay(400);
  PORTB_Reg |= (1 << ONBOARD_LED); // Turn on
  delay(400);
  PORTB_Reg &= ~(1 << ONBOARD_LED); // Turn off
  Serial.println("Done");
}

void loop() 
{
  // General control method for controlling the servo and ultrasonic sensor
  ServoUnit::turnLeft();
  ServoUnit::turnRight();
}