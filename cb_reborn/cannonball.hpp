//
//  cannonball.hpp
//  cb_reborn
//
//  Created by Mikal Stapnes on 21/02/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#ifndef cannonball_hpp
#define cannonball_hpp

#include <stdio.h>

double acclY(); // Del 1

double velY(double initVelocityY, double time);//Del 1

double posX(double initPosition, double initVelocity, double time);//Del 1
double posY(double initPosition, double initVelocity, double time);//Del 1

void printTime(double time); //Del 1

double flightTime(double initVelocityY); //Del 1

void getUserInput(double *theta, double *absVelocity); //Del 2

double degToRad(double deg); //Del 2

double getVelocityX(double theta, double absVelocity); //Del 2
double getVelocityY(double theta, double absVelocity); //Del 2
void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY); //Del 2
double getDistanceTraveled(double velocityX, double velocityY);//Del 2

void playTargetPractice(); //Del 3

#endif /* cannonball_hpp */
