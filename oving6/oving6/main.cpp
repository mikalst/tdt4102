//
//  main.cpp
//  oving6
//
//  Created by Mikal Stapnes on 13/02/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#include <iostream>
#include "some_classes.cpp"

int main(int argc, const char * argv[]) {
    Person mikal("Mikal Stapnes", "mstapnes@gmail.com");
    Person mikalia("Mikalia Stapnes", "mikalsen@gmail.com");
    bool isSamePerson = mikal==mikalia;
    const Person& firstPerson = mikal<mikalia;
    
    return 0;
}
