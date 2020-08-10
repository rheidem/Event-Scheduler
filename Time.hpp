//
//  Time.hpp
//  EventScheduler
//
//  Created by Ryan Heidema on 7/17/20.
//  Copyright © 2020 Ryan Heidema. All rights reserved.
//

#ifndef Time_hpp
#define Time_hpp

#include <iostream>


// ---------------------------------------------------------
//                        TIME CLASS
// ---------------------------------------------------------
class Time {
private:
    int hour;
    int minute;
    
public:
    Time(int hour_in, int minute_in);
    
    int get_hour() { return hour; }
    int get_minute() { return minute; }
    
    void set_hour(int hour_in) { hour = hour_in; }
    void set_minute(int minute_in) { minute = minute_in; }
    
    void addTime(int hour_in, int minute_in);
    
};

#endif /* Time_hpp */
