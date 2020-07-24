//
//  RideTime.hpp
//  EventScheduler
//
//  Created by Ryan Heidema on 7/19/20.
//  Copyright © 2020 Ryan Heidema. All rights reserved.
//

#ifndef RideTime_hpp
#define RideTime_hpp

#include <iostream>
#include <limits>
#include "Time.hpp"

class RideTime {
private:
    Time Time;
    size_t Division_ID;
    size_t Rider_ID = std::numeric_limits<size_t>::max();
    size_t Event_Number;
    
public:
    RideTime(class Time Time_in, size_t Division_ID_in, size_t Event_Number_in);
    
    class Time get_Time() { return Time; }
    size_t get_Division_ID() { return Division_ID; }
    size_t get_Rider_ID() { return Rider_ID; }
    size_t get_Event_Number() { return Event_Number; }
    
    void set_Rider_ID(size_t Rider_ID_in) { Rider_ID = Rider_ID_in; }
    
};

#endif /* RideTime_hpp */
