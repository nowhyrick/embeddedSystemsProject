/*--------------------------------------------------------------------
Name: Noah Whyrick
Date: 02/27/2025
Course: CSCE 336 Embedded Systems (Spring 2025)
File: servo.h
HW/Lab: Lab 3/Project
Purp: Library header file for controlling the robot servo
Doc: I helped no one and no people helped me.

Academic Integrity Statement: I certify that, while others may have
assisted me in brain storming, debugging and validating this program,
the program itself is my own work. I understand that submitting code
which is the work of other individuals is a violation of the honor
code. I also understand that if I knowingly give my original work to
another individual is also a violation of the honor code.
--------------------------------------------------------------------*/

#ifndef SERVOUNIT
#define SERVOUNIT

namespace ServoUnit
{
    // For use with TCCR2A (phase correct PWM)
    const byte counter2MaskA =
    {
        (1 << WGM20) |
        (1 << WGM21) |
        (1 << COM2B1) // Turns on and off output
    };

    // Phase correct PWM with prescalar of 1024
    const byte counter2MaskB =
    {
        (1 << WGM22) | 
        (1 << CS20) | 
        (1 << CS21) | 
        (1 << CS22)
    };

    /**
    * Function to initialize servo
    * 
    * FOR USE DURING SETUP
    */
    void initServo();

    /**
     * Rotates the servo left by 'degrees'
     */
    void turnLeft();

    /**
     * Rotates the servo right by 'degrees'
     */
    void turnRight();
}

#endif