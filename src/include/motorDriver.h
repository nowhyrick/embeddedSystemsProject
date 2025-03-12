/*--------------------------------------------------------------------
Name: Noah Whyrick
Date: 03/12/2025
Course: CSCE 336 Embedded Systems (Spring 2025)
File: motorDriver.h
HW/Lab: Project
Purp: Library header file for controlling the DC motors
Doc: I helped no one and no people helped me.

Academic Integrity Statement: I certify that, while others may have
assisted me in brain storming, debugging and validating this program,
the program itself is my own work. I understand that submitting code
which is the work of other individuals is a violation of the honor
code. I also understand that if I knowingly give my original work to
another individual is also a violation of the honor code.
--------------------------------------------------------------------*/

#ifndef MOTOR_DRIVER
#define MOTOR_DRIVER

#include <Arduino.h>

/**
 * Namespace for the motor controller library
 */
namespace MotorDriver
{
    /**
     * Initializes the motors and timer0 to control them
     * 
     * FOR USE DURING SETUP
     */
    void initMotorDriver();

    /**
     * Turns the robot left by timerValue
     */
    void turnLeft(int timerValue);

    /**
     * Turns the robot right by timerValue
     */
    void turnRight(int timerValue);

    /**
     * Sets the overall motion of the robot to forward or backward
     */
    void setMotion(bool forward, bool backward);
}

#endif