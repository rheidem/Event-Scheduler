//
//  Scheduler.cpp
//  EventScheduler
//
//  Created by Ryan Heidema on 7/18/20.
//  Copyright © 2020 Ryan Heidema. All rights reserved.
//

#include "Scheduler.hpp"
#include "Division.hpp"
#include "Rider.hpp"
#include "Time.hpp"
#include "RideTime.hpp"
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>

using namespace std;

Scheduler::Scheduler() {
    // Read in first line of input and reserve data for properties
    string junk;;
    size_t num_coaches;
    size_t num_divisions;
    size_t num_riders;
    
    // Read in and resize vectors
    cin >> num_coaches >> junk;
    Coaches.reserve(num_coaches);
    
    cin >> num_divisions;
    Divisions.reserve(num_divisions);
    
    cin >> junk >> num_riders;
    Riders.reserve(num_riders);
    
    // Read in padding
    cin >> junk >> padding >> junk >> junk >> junk;
    getline(cin, junk);
    // Read in coach names
    string coach_name;
    for(size_t i = 0; i < num_coaches; i++) {
        getline(cin, coach_name);
        Coaches.push_back(coach_name);
    }
    
    // Read in Divisions
    cin >> junk;
    for(size_t i = 0; i < num_divisions; i++) {
        Divisions.emplace_back(Division());
    }
    
    // Read in Riders
    cin >> junk;
    size_t no_coach = num_coaches;
    for(size_t i = 0; i < num_riders; i++) {
        string Name;
        string coach_name;
        string division;
        
        size_t Coach_ID = 0;
        size_t Division_ID = 0;
        
        // Rider's name
        string s1, s2;
        cin >> s1;
        if(s1.at(s1.length() - 1) == ',') {
            Name = s1.substr(0, s1.length() - 1);
        }
        else {
            cin >> s2;
            Name = s1 + " " + s2.substr(0, s2.length() - 1);
        }
        
        // Rider's Coach
        cin >> s1;
        if(s1.at(s1.length() - 1) == ',') {
            coach_name = s1.substr(0, s1.length() - 1);
        }
        else {
            cin >> s2;
            coach_name = s1 + " " + s2.substr(0, s2.length() - 1);
        }
        
        if(coach_name == "No Coach") {
            Coach_ID = no_coach;
            ++no_coach;
        }
        
        for(size_t i = 0; i < num_coaches; i++) {
            if(Coaches[i] == coach_name) {
                Coach_ID = i;
            }
        }
        
        // Rider's division
        getline(cin, division);
        division = division.substr(1 , string::npos);
        for(size_t i = 0; i < num_divisions; i++) {
            if(Divisions[i].get_Name() == division) {
                Division_ID = i;
            }
        }
        
        Divisions[Division_ID].Riders.push_back(i);
        Divisions[Division_ID].Selected_Riders.push_back({false, false, false});
        
        Riders.emplace_back(Rider(Name, Division_ID, i, Coach_ID));
    }
}

bool RideTimeComp(RideTime &a, RideTime &b) {
    if(a.get_Time().get_hour() == b.get_Time().get_hour()) {
        return (a.get_Time().get_minute() < b.get_Time().get_minute());
    }
    else {
        return (a.get_Time().get_hour() < b.get_Time().get_hour());
    }
}

void Scheduler::CreateRideTimes() {
    // Get the number of days in the show
    size_t num_days = 0;
    
    for(size_t i = 0; i < Divisions.size(); ++i) {
        for(size_t j = 0; j < Divisions[i].Event_Days.size(); ++j) {
            if(Divisions[i].Event_Days[j] > static_cast<int>(num_days)) {
                num_days = static_cast<size_t>(Divisions[i].Event_Days[j]);
            }
        }
    }
    
    // Resize the outer RideTimes vector
    RideTimes.resize(num_days);
    
    // Create the vector of ride times for each day
    for(size_t i = 0; i < Divisions.size(); ++i) {
        for(size_t j = 0; j < Divisions[i].Event_Days.size(); ++j) {
            for(size_t k = 0; k < Divisions[i].Riders.size(); ++k) {
                
                // Get the start time of the event
                Time t = Divisions[i].Event_Times[j];
                
                // If dressage, 5 min between riders
                size_t addTime;
                if(j == 0) {
                    addTime = 5 * k;
                }
                // If stadium or XC, 2 min between riders
                else {
                    addTime = 2 * k;
                }
                
                // Add this time to the start of the division
                size_t hour, min;
                hour = addTime / 60;
                min = addTime % 60;
                
                t.addTime(static_cast<int>(hour), static_cast<int>(min));
                
                RideTimes[static_cast<size_t>(Divisions[i].Event_Days[j] - 1)].emplace_back(RideTime(t,i,j));
            }
        }
    }
    
    // Sort each day of ride times by start time
    for(size_t i = 0; i < RideTimes.size(); ++i) {
        sort(RideTimes[i].begin(), RideTimes[i].end(), RideTimeComp);
    }
}

bool withinTime(Time t1, Time t2, int padding) {
    int t1min = (t1.get_hour() * 60) + t1.get_minute();
    int t2min = (t2.get_hour() * 60) + t2.get_minute();
    if((t1min - t2min) < padding) {
        return true;
    }
    return false;
}

bool Scheduler::promising(std::vector<RideTime> &path, size_t permLength) {
    if(permLength == 0 || permLength == 1) {
        return true;
    }
    permLength--;
    size_t i = 1;
    while(withinTime(path[permLength].get_Time(), path[permLength - i].get_Time(), padding)) {
        // if previous ride time is within padding time and
        if(Riders[path[permLength].get_Rider_ID()].get_Coach_ID() == Riders[path[permLength - i].get_Rider_ID()].get_Coach_ID()) {
            return false;
        }
        if(i == permLength) { // if you get to the end, then there is no conflict
            return true;
        }
        i++;
    }
    return true;
}

void Scheduler::genPerms(std::vector<RideTime> &path, size_t permLength, bool &done) {
    if (promising(path, permLength)) {
        if(permLength == path.size()) {
            // this is an acceptable solution, return and get out
            done = true;
            return;
        }
        else {
            Division &div = Divisions[path[permLength].get_Division_ID()];
            for(size_t j = 0; j < div.Riders.size(); j++) {
                if(div.Selected_Riders[j][path[permLength].get_Event_Number()] == false) {
                    path[permLength].set_Rider_ID(div.Riders[j]);
                    div.Selected_Riders[j][path[permLength].get_Event_Number()] = true;

                    genPerms(path, permLength + 1, done);
                    if(done == true) {
                        return;
                    }
                    path[permLength].set_Rider_ID(std::numeric_limits<size_t>::max());
                    div.Selected_Riders[j][path[permLength].get_Event_Number()] = false;
                }
            }
        }
    }
}

void Scheduler::SetRideTimes() {
    for(size_t i = 0; i < RideTimes.size(); ++i) {
        bool b = false;
        genPerms(RideTimes[i], 0, b);
    }
}

void Scheduler::PrintRideTimes() {
    for(size_t i = 0; i < RideTimes.size(); ++i) {
        cout << "DAY " << (i + 1) << ":\n";
        cout << "-------------------------------------\n";
        for(size_t j = 0; j < RideTimes[i].size(); ++j) {
            cout <<  "Rider: " << Riders[RideTimes[i][j].get_Rider_ID()].get_name() << "\n";
            cout <<  "Division: " << Divisions[RideTimes[i][j].get_Division_ID()].get_Name() << "\n";
            if(Riders[RideTimes[i][j].get_Rider_ID()].get_Coach_ID() < Coaches.size()) {
                cout << "Coach: " << Coaches[Riders[RideTimes[i][j].get_Rider_ID()].get_Coach_ID()] << "\n";
            }
            else {
                cout << "Coach: No Coach\n";
            }
            Time t = RideTimes[i][j].get_Time();
            cout << "Time: " << t.get_hour() << ":";
            if((t.get_minute() / 10) == 0) {
                cout << "0" << t.get_minute() << "\n";
            }
            else {
                cout << t.get_minute() << "\n";
            }
            cout << "\n";
        }
    }
}
