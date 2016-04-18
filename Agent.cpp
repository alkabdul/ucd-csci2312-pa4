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

const double Agent::AGENT_FATIGUE_RATE = 0.3;

Agent::Agent(const Game &g, const Position &p, double energy):Piece(g,p){
    
    
    __energy = energy;
    
    
}
void Agent::age(){
    
    
    __energy -= AGENT_FATIGUE_RATE;
    
    
}
Piece& Agent::interact(Agent *){
    
    Agent *a = this;
    
    return *this;
    
    
}

Piece& Agent::interact(Resource *){
    
    
    return *this;
    
}
Agent::~Agent(){
    
    
}

Piece& Agent::operator*(Piece &other){
    
    
    return other;
}
