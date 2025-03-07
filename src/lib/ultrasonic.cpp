/*--------------------------------------------------------------------
Name: Noah Whyrick
Date: 02/27/2025
Course: CSCE 336 Embedded Systems (Spring 2025)
File: ultrasonic.cpp
HW/Lab: Lab 3/Project
Purp: Library implementation of ultrasonic.h
Doc: I helped no one and no people helped me.

Academic Integrity Statement: I certify that, while others may have
assisted me in brain storming, debugging and validating this program,
the program itself is my own work. I understand that submitting code
which is the work of other individuals is a violation of the honor
code. I also understand that if I knowingly give my original work to
another individual is also a violation of the honor code.
--------------------------------------------------------------------*/

#include <Arduino.h>
#include "include/ultrasonic.h"

const byte portcMask =
(
    (1 << PORTC1) |
    (1 << PORTC0)
);

/**
 * Initializes the ultrasonic sensor
 */
void Ultrasonic::initUltraSonic()
{
    Serial.println("Initializing ultrasonic sensor unit");

    DDRC |= (1 << DDC1);  // Set output on A1 for trigger
    DDRC &= ~(1 << DDC0); // Set input on A0 for echo

    // Enable pull-up resistors (mask definition in header file)
    PORTC |= portcMask;

    Serial.println("Initializing startup sequence");
    Serial.println("Sending pulse");
    sendPulse();
    Serial.println("Done");
    int timing = readTiming();
    if (timing != 0)
    {
        Serial.print("Timing received: ");
        Serial.println(timing);
    }
    else
    {
        Serial.println("ERROR: no timing received");
    }

    Serial.println("Startup sequence complete");
    Serial.println("Ultrasonic sensor unit initialization complete");
}

/**
 * Sends a pulse out over the ultrasonic sensor
 */
void Ultrasonic::sendPulse()
{
    // TODO: implement
}

/**
 * Reads the timing for Timer 1 input capture unit and returns it
 */
int Ultrasonic::readTiming()
{
    // TODO: implement
}