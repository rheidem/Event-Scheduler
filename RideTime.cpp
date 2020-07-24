//
//  RideTime.cpp
//  EventScheduler
//
//  Created by Ryan Heidema on 7/19/20.
//  Copyright © 2020 Ryan Heidema. All rights reserved.
//

#include "RideTime.hpp"
#include "Time.hpp"

RideTime::RideTime(class Time Time_in, size_t Division_ID_in, size_t Event_Number_in)
: Time(Time_in), Division_ID(Division_ID_in), Event_Number(Event_Number_in) {}
