//
//  main.cpp
//  oving6_restart
//
//  Created by Mikal Stapnes on 19/02/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#include <iostream>
#include "Meeting.hpp"

int main(int argc, const char * argv[]) {
    Person const mikal("Mikal", "some@mail.com");
    Person const per("Per Persson", "per@gmail.com");
    Person const anne("Anne Sladre", "ansla@gmail.com");
    
    Person const * p_mikal = &mikal;
    Person const * p_per = &per;
    Person const * p_anne = &anne;
    
    Meeting my_meeting(0, 0000, 2000, TRH, "Something", p_mikal);
    
    my_meeting.addParticipant(p_per);
    my_meeting.addParticipant(p_anne);
    
    std::cout<< my_meeting;
    
    return 0;
}
