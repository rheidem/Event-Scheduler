//
//  Scheduler.hpp
//  EventScheduler
//
//  Created by Ryan Heidema on 7/18/20.
//  Copyright © 2020 Ryan Heidema. All rights reserved.
//

#ifndef Scheduler_hpp
#define Scheduler_hpp

#include "Division.hpp"
#include "Rider.hpp"
#include "Time.hpp"
#include "RideTime.hpp"
#include <iostream>
#include <unordered_map>
#include <vector>

// ---------------------------------------------------------
//                     SCHEDULER CLASS
// ---------------------------------------------------------
class Scheduler {
private:
    std::vector<std::string> Coaches;
    std::vector<Division> Divisions;
    std::vector<Rider> Riders;
    
    // padding time represents the minimum number of minutes between a
    // coach's riders
    int padding;
    
    std::vector<std::vector<RideTime>> RideTimes;
    
public:
    
    // Reads input and fills vectors for Coaches, Divisions, and Riders
    Scheduler();
    
    //
    void CreateRideTimes();
    
    void genPerms(std::vector<RideTime> &path, size_t permLength, bool &done);
    
    bool promising(std::vector<RideTime> &path, size_t permLength);
    
    void SetRideTimes();
    
    void PrintRideTimes();
    
};

#endif /* Scheduler_hpp */
