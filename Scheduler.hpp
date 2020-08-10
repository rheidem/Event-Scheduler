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
    
    // Helper function to read in the Riders
    void ReadRiders(size_t num_coaches, size_t num_divisions, size_t num_riders);
    
    // Initialize vector of RideTimes and leave Rider_ID as infinity (not yet
    // assigned)
    void CreateRideTimes();
    
    // Use backtracking to determine RideTimes so that no coach has conflicts,
    // immediately exit recursion as soon as solution is found
    void genPerms(std::vector<RideTime> &path, size_t permLength, bool &done);
    
    // Looks at the last 'padding' minutes from most recent RideTime and ensures
    // no coaching conflicts
    bool promising(std::vector<RideTime> &path, size_t permLength);
    
    // Calls genPerms for each day of RideTimes, as days won't overlap
    void SetRideTimes();
    
    // Prints RideTimes based on predetermined output pattern
    void PrintRideTimes();
    
};

#endif /* Scheduler_hpp */
