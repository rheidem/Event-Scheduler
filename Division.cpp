//
//  Division.cpp
//  EventScheduler
//
//  Created by Ryan Heidema on 7/15/20.
//  Copyright © 2020 Ryan Heidema. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "Division.hpp"
#include "Time.hpp"

using namespace std;

Division::Division() {
    // Reserve vectors for day and time info, there are 3 events in eventing
    Event_Days.reserve(3);
    Event_Times.reserve(3);
    
    // Read in name
    string s1, s2;
    cin >> s1;
    if(s1.at(s1.length() - 1) == ',') {
        Name = s1.substr(0, s1.length() - 1);
    }
    else {
        cin >> s2;
        Name = s1 + " " + s2.substr(0, s2.length() - 1);
    }
    
    // Read in days and times
    int day;
    int hour;
    int minute;
    
    char junk;
    
    for(size_t i = 0; i < 3; i++) {
        
        // read in day, hour, minute
        cin >> day >> hour >> junk >> minute;
        
        Event_Days.push_back(day);
        Event_Times.emplace_back(Time(hour, minute));
        
        // read in parentheses to junk
        if(i != 2) {
            cin >> junk;
        }
    }
}
