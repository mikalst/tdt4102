//
//  some_classes.cpp
//  oving6
//
//  Created by Mikal Stapnes on 13/02/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#include "some_classes.hpp"

#include <set>
#include <algorithm>
#include <string>
#include <iostream>

// Car declaration
bool Car::hasFreeSeats() const{
    if (free_seats > 0) {
        return true;
    }
    return false;
}
void Car::reserveFreeSeat() {
    free_seats -= 1;
}
Car::Car(int free_seats) {
    this->free_seats = free_seats;
}


// Person declaration
void Person::setName(std::string in_name) {
    this->name = in_name;
}
void Person::setEmail(std::string in_email) {
    this->name = in_email;
}
std::string Person::getName() const{
    return name;
}
std::string Person::getEmail() const{
    return email;
}
Person::Person(std::string in_name, std::string in_email) {
    this->name = in_name;
    this->email = in_email;
    this->car = nullptr;
}
Person::Person(std::string in_name, std::string in_email, Car* car) : Person(in_name, in_email) {
    this->car = car;
}
bool Person::hasAvailableSeats() {
    if (this->car != nullptr and this->car->hasFreeSeats()) {
        return true;
    }
    return false;
}
/*
std::ostream& operator<<(std::ostream& os, Person& p) {
    return os << p.getName() << p.getEmail();
}*/
