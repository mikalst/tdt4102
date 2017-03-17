#include "Some_classes.hpp"
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
    return this->name;
}
std::string Person::getEmail() const{
    return this->email;
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

std::ostream& operator<<(std::ostream& os, Person const & p) {
    std::string name = p.getName();
    std::string email = p.getEmail();
    os << "Navn: " << name << ", Email: " << email << std::endl;
    return os;
}

bool operator<(Person const & p_1, Person const & p_2) {
    std::string name_1 = p_1.getName();
    std::string name_2 = p_2.getName();
    std::transform(name_1.begin(), name_1.end(), name_1.begin(), ::toupper);
    std::transform(name_2.begin(), name_2.end(), name_2.begin(), ::toupper);
    name_2.append(1, '0');
    for (int x = 0; x < name_1.length(); x++) {
        if (name_2[x] < name_1[x]) {
            return false;
        }
    }
    return true;
}
bool operator==(Person const & p_1, Person const & p_2) {
    std::string name_1 = p_1.getName();
    std::string name_2 = p_2.getName();

    if (name_1 == name_2) {
        return true;
    }
    return false;
}

