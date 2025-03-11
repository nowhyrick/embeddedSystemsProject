/*--------------------------------------------------------------------
Name: Noah Whyrick
Date: 02/27/2025
Course: CSCE 336 Embedded Systems (Spring 2025)
File: ultrasonic.h
HW/Lab: Lab 3/Project
Purp: Library header file for controlling the ultrasonic sensor
Doc: I helped no one and no people helped me.

Academic Integrity Statement: I certify that, while others may have
assisted me in brain storming, debugging and validating this program,
the program itself is my own work. I understand that submitting code
which is the work of other individuals is a violation of the honor
code. I also understand that if I knowingly give my original work to
another individual is also a violation of the honor code.
--------------------------------------------------------------------*/

#ifndef ULTRASONIC
#define ULTRASONIC

#include <Arduino.h>

namespace Ultrasonic
{
    #define trigger 7 // Outputting on digital pin 7
    #define echo 0 // Echo on PB0 to use ICP1

    /**
    * Initializes the ultrasonic sensor
    * 
    * FOR USE DURING SETUP
    */
    void initUltraSonic();

    /**
     * Sends a pulse out over the ultrasonic sensor
     */
    void sendPulse();

    /**
     * Reads the timing from the Timer 1 input capture unit and returns it
     */
    double readTiming();
}

#endif