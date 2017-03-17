//
//  read_and_write.cpp
//  oving8
//
//  Created by Mikal Stapnes on 03/03/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#include "read_and_write.hpp"

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

typedef std::map<std::string, int> StrIntMap;

void countLines(std::istream& in, int* numberOfWords) {
    int number_of_lines = 0;
    std::string line;
    
    while (std::getline(in, line))
        ++number_of_lines;
    *numberOfWords = number_of_lines;
}

void countWords(std::istream& in, StrIntMap& words) {
    std::string s;
    
    while (in >> s) {
        s = strip(s);
        ++words[s];
    }
    return;
}

void write_to_file() {
    
    std::fstream outfile;
    outfile.open("realtest.txt", std::fstream::out);
    
    std::cout << "Write as many words as you want, when you are done write stop" << std::endl;
    std::string current_input;
    std::string stop_input = "stop";
    std::string total_input = "";
    while (current_input != stop_input) {
        std::cin >> current_input;
        if (current_input != stop_input) {
            total_input += current_input + "\n";
        }
    }
    
    outfile.write( total_input.c_str(), sizeof(char)*total_input.size());
    outfile.close();
    
    return;
}

void read_from_file_write_to_another () {
    std::ifstream infile("first.txt");
    std::string in_str;
    std::string out_str = "";
    int n = 0;
    while (std::getline(infile, in_str))
    {
        out_str += std::to_string(n) + " " + in_str;
        out_str.push_back('\n');
        n++;
    }
    infile.close();
    std::fstream outfile;
    outfile.open("copy.txt", std::fstream::out);
    outfile.write( out_str.c_str(), sizeof(char)*out_str.size());
    outfile.close();
}

void statistics_from_file_characters() {
    // Open file
    std::ifstream file;
    file.open("bible.txt", std::ios::in);
    
    // Create array of integers to store the statistics
    // Presuming that all characters are ASCII
    int character_count[128] = {0};
    
    // Count total characers
    int total_characters = 0;
    
    // Create temp string to store the lines
    std::string line_string;
    
    // Iterate lines in file
    while (std::getline(file, line_string)) {
        char* c_line_string = new char[line_string.length() + 1];
        strcpy(c_line_string, line_string.c_str());
        
        // Iterate over characters in line
        for (int x = 0; x < line_string.size(); x++) {
            int character = static_cast<int>(*(c_line_string + x));
            *(character_count + character) += 1;
            total_characters++;
        }
        
    }
    
    // Start outputting statistics
    
    std::cout << "Character statistics: " << std::endl;
    std::cout << "Total number of characters: " << total_characters << std::endl;
    
    // Counter for outputting in a nice 4x format
    int n = 0;
    
    for (int x = 0; x<128; x++) {
        // Fetch value from table
        int active_ascii_value_count = *(character_count + x);
        
        
        
        if (active_ascii_value_count != 0) {
            n++;
            std::cout << static_cast<char>(x) << ": " << active_ascii_value_count << "  ";
            if (n%4 == 0) {
                std::cout << std::endl;
            }
        }
    }
    
    return;
}

// trim from both ends
std::string strip( const std::string &s ) {
    std::string result;
    result.reserve( s.length() );
    
    std::remove_copy_if( s.begin(),
                        s.end(),
                        std::back_inserter( result ),
                        std::not1( std::ptr_fun( isalpha ) ) );
    
    return result;
}


void statistics_from_file_words() {
    // Open file
    /*
    int number_of_lines = 0;
    int* ptr_nol = &number_of_lines;
    std::ifstream oldfile;
    oldfile.open("bible.txt", std::ios::in);
    countLines(oldfile, ptr_nol);
    oldfile.close();
     */
    
    std::ifstream file;
    file.open("bible.txt", std::ios::in);
    
    StrIntMap w;
    
    
    
    //countLines(file, ptr_nol);
    
    std::string longest_word;
    
    countWords(file, w);
    
    for (StrIntMap::iterator p = w.begin(); p != w.end(); ++p) {
        std::cout << p->first << ": " << p->second << std::endl;
    }
    
    for (StrIntMap::iterator p = w.begin(); p != w.end(); ++p) {
        if (p->first.size() > longest_word.size()) {
            longest_word = p->first;
        }
    }
    
    std::cout << w.size() << " unique words on " << 31102 << " lines." << std::endl;
    std::cout << "The longest word is: " << longest_word << std::endl;
    
    return;
}

