//
//  Meeting.hpp
//  oving6_restart
//
//  Created by Mikal Stapnes on 19/02/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#ifndef Meeting_hpp
#define Meeting_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "some_classes.hpp"

enum Campus {
    TRH,
    GJO,
    AAL,
};

std::ostream& operator<<(std::ostream&, Campus campus_2);

class Meeting{
public:
    void addParticipant(const Person * p);
    Meeting(int day, int startTime, int endTime, Campus location, std::string subject, Person const * leader);
    ~Meeting();
    std::vector<std::string> getParticipantList();
    int day;
    int startTime;
    int endTime;
    Campus location;
    std::string subject;
    Person const * leader;
    std::vector<const Person *> participants;
    static std::vector<Meeting const *> meetings;
};

std::ostream& operator <<(std::ostream& os, Meeting m);

#endif /* Meeting_hpp */
