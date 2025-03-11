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

// Clears out the timer registers
void clearRegisters();

/**
 * Initializes the ultrasonic sensor
 */
void Ultrasonic::initUltraSonic()
{
    Serial.println("Initializing ultrasonic sensor unit");

    DDRD |= (1 << trigger); // Set PD7 for signal output
    PORTD |= (1 << trigger); // Enable pull up resistor
    DDRB &= ~(1 << echo); // Set PB0 for input to track echo in ICP1

    // CTC mode; ICR1 is top
    TCCR1B = (1 << ICES1) | (1 << CS10); //| (1 << WGM12) | (1 << WGM13);
    TCCR1A = 0; // Normal mode
    TCCR1C = 0;

    clearRegisters();

    Serial.println("Ultrasonic sensor unit initialization complete");
}

/**
 * Sends a pulse out over the ultrasonic sensor
 */
void Ultrasonic::sendPulse()
{
    Serial.println("Sending pulse");
    // Set high
    PORTD |= (1 << trigger);
    // Delay 10 microseconds
    _delay_us(10);
    // Set low
    PORTD &= ~(1 << trigger);
    Serial.println("Done");
}

/**
 * Reads the timing for Timer 1 input capture unit and returns it
 */
double Ultrasonic::readTiming()
{
    Ultrasonic::sendPulse();

    double timing = pulseIn(8, HIGH);
    Serial.print("Timing: ");
    Serial.println(timing);

    // Poll ICP1
    //while((TIFR1 & (1 << ICF1)) == 0);
    //Serial.println("Input Detected");
    //TIFR1 |= (1 << ICF1); // clear register flag
    //PORTD |= (1 << PD4); // Set red LED high
    //_delay_ms(1000);
    //PORTD &= ~(1 << PD4); // Set red LED low
    //Serial.print("Timing: ");
    //Serial.println(TCNT1L);
    //clearRegisters();
    //
    //return ICR1;

    return timing;
}

// Clears out the timer registers
void clearRegisters()
{
  //Set counter to zero, high byte first
  TCNT1H = 0;
  TCNT1L = 0;  
  // Clear ICR1, high byte first
  ICR1H = 0;
  ICR1L = 0;
}