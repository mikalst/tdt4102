//
//  Meeting.cpp
//  oving6_restart
//
//  Created by Mikal Stapnes on 19/02/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#include "Meeting.hpp"
#include <ostream>
#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, Campus campus_1) {
    std::string campus_names[3] = {"Trondheim", "Gjoevik", "Aalesund"};
    os << campus_names[campus_1];
    return os;
}

void Meeting::addParticipant(const Person * p) {
    bool inserted = false;
    if (this->participants.size() == 0) {
        this->participants.push_back(p);
        return;
    }
    for (int x = 0; x < this->participants.size(); x++) {
        if (p < this->participants.at(x)) {
            this->participants.insert(participants.begin()+x, p);
            return;
        }
    }
    this->participants.push_back(p);
}

std::vector<const Meeting *> Meeting::meetings;

Meeting::Meeting(int day, int startTime, int endTime, Campus location, std::string subject, Person const * leader) {
    // Construct the meeting
    this->day = day;
    this->startTime = startTime;
    this->endTime = endTime;
    this->location = location;
    this->subject = subject;
    this->leader = leader;
    this->addParticipant(leader);
    
    // Add meeting to static meetings.
    meetings.push_back(this);
}

Meeting::~Meeting() {
    /* int position_in_meetings = find(meetings.begin(), meetings.end(), this) - meetings.begin();
    meetings.erase(meetings.begin() + position_in_meetings); */
    // Denne destruktøren gir meg bad access, what do?
    
    /* 
     
    Jeg vet jeg kjører destruktøren til Meeting to ganger, som gjør at den prøver å slette samme element i meetings to ganger
     og dermed gir meg BAD ACCESS, men greier ikke intuitivt å se hvor jeg har gjort feil.
    */
    std::cout << "I can run";
}

std::vector<std::string> Meeting::getParticipantList(){
    std::vector<std::string> names_of_participants;
    int num_participants = participants.size();
    for (int x = 0; x < num_participants; x++) {
        Person const * current_person = participants.at(x);
        names_of_participants.push_back(current_person->getName());
    }
    return names_of_participants;
}

std::ostream& operator <<(std::ostream& os, Meeting m) {
    os << "Dag: " << m.day << ", Tid: " << m.startTime << " - " << m.endTime << ", Sted: " << m.location << ", Emne: " << m.subject << ", Leder: " << (m.leader)->getName() <<  ", Deltagere: " << std::endl;
    std::vector<std::string> names_of_participants = m.getParticipantList();
    for (int x = 0; x < names_of_participants.size(); x++) {
        os << names_of_participants.at(x) << std::endl;
    }
    return os;
}
