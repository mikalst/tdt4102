//
//  game_objects.cpp
//  cb_reborn
//
//  Created by Mikal Stapnes on 21/02/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#include "game_objects.hpp"
#include "cannonball.hpp"

#include <cmath>

// implement all (member) functions in this file

bool hitTarget(const Cannonball& c, const Target& t) {
    return c.shape.getGlobalBounds().intersects(t.shape.getGlobalBounds());
}

// TARGET
Target::Target(double size, double position) {
    this->position = position;
    this->size = size;
    shape = sf::RectangleShape(sf::Vector2f(size, size));
    sf::Color shapeColor(0, 255, 255, 255);
    shape.setFillColor(shapeColor);
    shape.setPosition(static_cast<float>(position), 0.0);
}

void Target::update() {
    // Updates the target
    return;
}

void Target::draw(sf::RenderWindow& w) {
    // Updates then draws
    w.draw(this->shape);
}

// CANNON
Cannon::Cannon() {
    shape = sf::RectangleShape(sf::Vector2f(width, length));
    sf::Color shapeColor(255, 0, 255, 255);
    shape.setFillColor(shapeColor);
    shape.setPosition(0, 0);
    shape.setOrigin(0, 0);
}

void Cannon::update() {
    // Updates the object
    shape.setRotation(theta - 90);
}

void Cannon::draw(sf::RenderWindow& w) {
    // Updates then draws
    
    w.draw(shape);
}

void Cannon::incrementAngle(double dtheta) {
    theta += dtheta;
}

void Cannon::decrementAngle(double dtheta) {
    theta -= dtheta;
}
void Cannon::incrementVelocity(double dvel) {
    this->velocity = this->velocity - dvel;
}
void Cannon::decrementVelocity(double dvel) {
    this->velocity = this->velocity + dvel;
}

Cannonball Cannon::shoot() {
    Cannonball cannon_shot(this->theta, this->velocity, this->getTipX(), this->getTipY());
    return cannon_shot;
}


// CANNONBALL
Cannonball::Cannonball(double angle, double initial_velocity, double startPosX, double startPosY){
    this->startVelX = -cos(degToRad(angle))*initial_velocity;
    this->startVelY = -sin(degToRad(angle))*initial_velocity;
    this->startPosX = startPosX + 20;
    this->startPosY = startPosY + 20;
    this->shape = sf::CircleShape(this->size);
    this->shape.setOrigin(startPosX, startPosY);
    sf::Color shapeColor(0, 0, 255, 255);
    this->shape.setFillColor(shapeColor);
}

void Cannonball::update() {
    this->shape.setOrigin(getPosX(), getPosY());
}

void Cannonball::draw(sf::RenderWindow& w) {
    w.draw(this->shape);
}

double Cannonball::getPosX() const {
    return (this->startVelX)*getAirTime();
}

double Cannonball::getPosY() const {
    return (this->startVelY)*getAirTime()+4.96*getAirTime()*getAirTime();
}

bool Cannonball::hasLanded() const {
    return getPosY() + size < 0 and getPosX() > 300;
}

double Cannonball::getAirTime() const {
    return SPEED_FACTOR*clock.getElapsedTime().asSeconds();
}

double Cannon::getTipX() const {
    return length*cos(degToRad(theta));
}

double Cannon::getTipY() const {
    return length*sin(degToRad(theta));
}

bool Cannonball::hitTarget(Target t) {
    return this->shape.getGlobalBounds().intersects(t.shape.getGlobalBounds());
}
