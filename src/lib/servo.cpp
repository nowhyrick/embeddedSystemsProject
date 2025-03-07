/*--------------------------------------------------------------------
Name: Noah Whyrick
Date: 02/28/2025
Course: CSCE 336 Embedded Systems (Spring 2025)
File: servo.cpp
HW/Lab: Lab 3/Project
Purp: Implements the servo.h library header
Doc: Received help from Dr. Falkinburg

Academic Integrity Statement: I certify that, while others may have
assisted me in brain storming, debugging and validating this program,
the program itself is my own work. I understand that submitting code
which is the work of other individuals is a violation of the honor
code. I also understand that if I knowingly give my original work to
another individual is also a violation of the honor code.
--------------------------------------------------------------------*/

#include <Arduino.h>
#include "include/servo.h"

/**
 * Initializes the servo unit
 */
void ServoUnit::initServo()
{
    Serial.println("Initializing servo unit");

    TCCR2A = counter2MaskA; // Set to phase-correct PWM 
    TCCR2B = counter2MaskB; // Set output compare and prescalar of 1024
    OCR2A = 255; // Top of timer 2
    OCR2B = 8; // Controls direction of servo
    TCNT2 = 0; // Clear timer
    DDRD |= (1 << PD3); // OCR2B set to output

    Serial.println("Initializing startup sequence");
    // Run initialize sequence: left -> center -> right
    turnLeft(); // Left
    turnRight(); // Center
    Serial.println("Done");
    Serial.println("Servo initialization complete");
}

/**
 * Rotates the servo left by 90 degrees
 */
void ServoUnit::turnLeft()
{
    Serial.println("Turning Left");
    OCR2B = 7;
    _delay_ms(1000);
}

/**
 * Rotates the servo right by 90 degrees
 */
void ServoUnit::turnRight()
{
    Serial.println("Turning Right");
    OCR2B = 35;
    _delay_ms(1000);
}