//
//  Rider.hpp
//  EventScheduler
//
//  Created by Ryan Heidema on 7/14/20.
//  Copyright © 2020 Ryan Heidema. All rights reserved.
//

#ifndef Rider_hpp
#define Rider_hpp

#include <iostream>
#include "RideTime.hpp"

// ---------------------------------------------------------
//                       RIDER CLASS
// ---------------------------------------------------------
class Rider {
private:
    std::string Name;
    
    // Each Rider will have an ID to not confuse identical names, as well as
    // an ID of their Division and Coach for easy lookup in the corresponding vectors
    size_t Division_ID;
    size_t ID;
    size_t Coach_ID;
    
public:
    Rider(std::string Name_in, size_t Division_ID_in, size_t ID_in, size_t Coach_ID_in);
    
    std::string get_name() { return Name; }
    size_t get_Division_ID() { return Division_ID; }
    size_t get_ID() { return ID; }
    size_t get_Coach_ID() { return Coach_ID; }
    
};


#endif /* Rider_hpp */
