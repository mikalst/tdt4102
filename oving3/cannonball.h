#ifndef CANNONBALL_H 
#define CANNONBALL_H

class Cannonball {
    public:
        double acclY();
        double velY(double initVelocityY, double timeVar);
        double posX(double initPosition, double initVelocityX, double timeVar);
        double posY(double initPosition, double initVelocityY, double timeVar); 
        void printTime(double timeVar);
        double flightTime(double initVelocityY);
};
#endif

