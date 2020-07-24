//
//  Time.cpp
//  EventScheduler
//
//  Created by Ryan Heidema on 7/17/20.
//  Copyright © 2020 Ryan Heidema. All rights reserved.
//

#include "Time.hpp"

Time::Time(int hour_in, int minute_in)
: hour(hour_in), minute(minute_in) {}

void Time::addTime(int hour_in, int minute_in) {
    
    int totalMin = minute_in + minute;
    hour += totalMin / 60;
    minute = totalMin % 60;
    
    int totalHour = hour_in + hour;
    hour = totalHour % 24;
    
}
