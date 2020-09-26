/*
 *  This header file stores symbols that concerns 
 *  the configuration of the system.
 *
 */
#ifndef __CONFIG__
#define __CONFIG__

#include "enumstate.h"

// General
#define MAX_TASKS 5
const unsigned long long PERIOD = 100;
#define NOSUGAR -1

// LEDS
#define N_LED    3 
#define LED1_PIN 11
#define LED2_PIN 12
#define LED3_PIN 6

// BUTTON
#define BUTTON 3
#define BOUNCING 100


// PIR
#define PIR 2
#define CALIBRATION_TIME 10

// DIST
#define TRIG_PIN 8
#define ECHO_PIN 7

// POT
#define POT_PIN A0
#define POT_MIN 0
#define POT_MAX 2
 
//        const
// distance
#define DIST1 30  // Engagement distance
#define DIST2 10  // Take coffee
// time
#define DT1   1000 // Min engagement time
#define DT2a  5000 // Max time with no engagement (PIR)
#define DT2b  5000 // Max time with no presence
#define DT3   3000 // Coffee making process duration 
#define DT4   5000 // Max time to remove coffee
// coffe
#define NMAX  5
#define NC    2

#endif
