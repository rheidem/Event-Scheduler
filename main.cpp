//
//  main.cpp
//  EventScheduler
//
//  Created by Ryan Heidema on 7/13/20.
//  Copyright © 2020 Ryan Heidema. All rights reserved.
//

#include <iostream>
#include "Scheduler.hpp"
#include "xcode_redirect.hpp"

using namespace std;

int main(int argc, char * argv[]) {
    ios_base::sync_with_stdio(false);
    xcode_redirect(argc, argv);
    
    Scheduler s = Scheduler();
    s.CreateRideTimes();
    s.SetRideTimes();
    s.PrintRideTimes();
    
    return 0;
}
