//
//  Resource.cpp
//  PA4
//
//  Created by Abdulrahman Alkaabi on 4/13/16.
//  Copyright © 2016 Abdulrahman Alkaabi. All rights reserved.
//

#include <stdio.h>
#include "Resource.h"

using namespace Gaming;

const double Resource::RESOURCE_SPOIL_FACTOR = 1.2;


Resource::Resource(const Game &g, const Position &p, double capacity):Piece(g ,p){
    
    
    __capacity = capacity;
    
}

Resource::~Resource(){
    
    
    
}


void Resource::age(){
    
    
    __capacity /= RESOURCE_SPOIL_FACTOR;
    
}
double Resource::consume(){
    
    
    
    Piece::finish();
    return 0.0;
    
}
Piece& Resource::operator*(Piece &other){
    
    
    
    return other;
}

Piece& Resource:: interact(Agent *){
    
    return *this;
    
    
}

Piece& Resource:: interact(Resource *){
    
    return *this;
    
}
ActionType Resource::takeTurn(const Surroundings &s) const{
    
    ActionType temp = SW;
    return temp;
    
}



