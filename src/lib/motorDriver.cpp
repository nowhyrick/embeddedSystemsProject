/*--------------------------------------------------------------------
Name: Noah Whyrick
Date: 03/12/2025
Course: CSCE 336 Embedded Systems (Spring 2025)
File: motorDriver.cpp
HW/Lab: Project
Purp: Implementation of motorDriver.h
Doc: I helped no one and no people helped me.

Academic Integrity Statement: I certify that, while others may have
assisted me in brain storming, debugging and validating this program,
the program itself is my own work. I understand that submitting code
which is the work of other individuals is a violation of the honor
code. I also understand that if I knowingly give my original work to
another individual is also a violation of the honor code.
--------------------------------------------------------------------*/

#include <Arduino.h>
#include "include/motorDriver.h"

/**
* Initializes the motors and timer0 to control them
* 
* FOR USE DURING SETUP
*/
void MotorDriver::initMotorDriver()
{
    // Set motion initially to not moving
    MotorDriver::setMotion(false, false);
}

/**
 * Turns the robot left by timerValue
 */
void MotorDriver::turnLeft(int timerValue)
{
    // Stop before turning
    MotorDriver::setMotion(false, false);
}

/**
* Turns the robot right by timerValue
*/
void MotorDriver::turnRight(int timerValue)
{
    // Stop before turning
    MotorDriver::setMotion(false, false);
}

/**
* Sets the overall motion of the robot to forward or backward
*/
void MotorDriver::setMotion(bool forward, bool backward)
{
    // Move forward
    if (forward)
    {
        // TODO: setup register values
    }
    // Move backward
    else if (backward)
    {
        // TODO: setup register values
    }
    // Stop
    else
    {
        // TODO: register values
    }
}