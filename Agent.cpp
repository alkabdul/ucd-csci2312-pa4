//
//  Agent.cpp
//  PA4
//
//  Created by Abdulrahman Alkaabi on 4/13/16.
//  Copyright © 2016 Abdulrahman Alkaabi. All rights reserved.
//

#include <stdio.h>
#include "Agent.h"

using namespace Gaming;

Agent::Agent(const Game &g, const Position &p, double energy):Piece(g,p){
    
    
    __energy = energy;
    
    
}

