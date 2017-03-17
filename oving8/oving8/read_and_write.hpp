//
//  read_and_write.hpp
//  oving8
//
//  Created by Mikal Stapnes on 03/03/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#ifndef read_and_write_hpp
#define read_and_write_hpp

#include <stdio.h>
#include <string>

void write_to_file ();

std::string strip( const std::string &s );

void read_from_file_write_to_another ();

void statistics_from_file_characters();

void statistics_from_file_words();

#endif /* read_and_write_hpp */
