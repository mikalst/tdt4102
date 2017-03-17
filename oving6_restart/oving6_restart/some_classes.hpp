//
//  some_classes.hpp
//  oving6
//
//  Created by Mikal Stapnes on 13/02/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#ifndef some_classes_hpp
#define some_classes_hpp

#include <stdio.h>
#include <string>



class Car {
public:
    bool hasFreeSeats() const;
    void reserveFreeSeat();
    Car(int free_seats);
private:
    int free_seats;
};

class Person {
public:
    Person(std::string in_name, std::string in_email, Car* car);
    // Initializes Person with a car.
    
    Person(std::string in_name, std::string in_email);
    // Initializes Person without a car.
    
    bool hasAvailableSeats();
    // Return true if Person has a car AND that car has available seats.
    
    void setName(std::string in_name);
    void setEmail(std::string in_email);
    std::string getName() const;
    std::string getEmail() const;
    
    friend std::ostream& operator<<(std::ostream& os, Person const & p);
    friend bool operator==(Person const & p_1, Person const & p_2);
    friend bool operator<(Person const & p_1, Person const & p_2);
private:
    std::string name;
    std::string email;
    Car* car;
};

#endif /* some_classes_hpp */
