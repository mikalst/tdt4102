#ifndef CANNONBALL_H 
#define CANNONBALL_H

// Regner ut akselerasjon i y-retning
double acclY();

// Regner ut farten i y-retning
double velY(double initVelocityY, double time);

// Regner ut posisjon i x-retning
double varPosX(double initPosition, double initVelocityX, double timeVar);

// Regner ut posisjon i y-retning
double posY(double initPosition, double initVelocityY, double time); 

// Skriver tiden til skjerm
void printTime(double time);

// Har valgt å returnere double
double flightTime(double initVelocityY);

#endif

