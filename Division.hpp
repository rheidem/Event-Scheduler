//
//  Division.hpp
//  EventScheduler
//
//  Created by Ryan Heidema on 7/15/20.
//  Copyright © 2020 Ryan Heidema. All rights reserved.
//

#ifndef Division_hpp
#define Division_hpp

#include <iostream>
#include <vector>
#include "Time.hpp"

class Division {
private:
    std::string Name;
    std::vector<int> Event_Days;
    std::vector<Time> Event_Times;
    
    std::vector<size_t> Riders;
    std::vector<std::vector<bool>> Selected_Riders;
    friend class Scheduler;
    
public:
    Division();
    
    std::string get_Name() { return Name; }
    
};


#endif /* Division_hpp */
