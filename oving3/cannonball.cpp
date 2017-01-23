#include "cannonball.h"

double Cannonball::acclY(){
    double acclConst = -9.81;
    return acclConst;
}

double Cannonball::velY(double initVelocityY, double timeVar){
    double currentVelocityY = initVelocityY - acclY()*timeVar;
    return currentVelocityY;
}

double Cannonball::posX(double initPosition, double initVelocityX, double timeVar){
    double currentPositionX = initPosition + initVelocityX * timeVar;
    return currentPositionX;
}

double Cannonball::posY(double initPosition, double initVelocityY, double timeVar){
    double currentPositionY = initPosition + initVelocityY * timeVar + 1/2*acclY()*timeVar*timeVar;
    return currentPositionY;
} 

void Cannonball::printTime(double timeVar){
    int hours = (int) timeVar%3600;
    int minutes = (int) timeVar%60 - hours*60;
    int seconds = (int) timeVar - hours*3600 - minutes*60; 
    std::cout << hours << " Timer, " << minutes << " minutter og " << seconds << " sekunder." << std::endl; 
}

double Cannonball::flightTime(double initVelocityY){
    double flightTime = -2 * initVelocityY/(acclY());
    return flightTime;
}

