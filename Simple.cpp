//
//  Simple.cpp
//  PA4
//
//  Created by Abdulrahman Alkaabi on 4/13/16.
//  Copyright © 2016 Abdulrahman Alkaabi. All rights reserved.
//

#include <stdio.h>
#include "Simple.h"

using namespace Gaming;
const char Simple::SIMPLE_ID = 'S';


Simple::Simple(const Game &g, const Position &p, double energy):Agent(g,p, energy){
    
    setPosition(p);
    setTurned(false);
    
}

Simple::~Simple(){
    
    
}

void Simple:: print(std::ostream &os) const{
    
    
    std::cout << "SIMPLE###########"<<std::endl;
    
}

ActionType Simple::takeTurn(const Surroundings &s) const{
    
    
    ActionType temp = NW;
    return temp;
    
    
}

PieceType Piece::getType() const{
    
    
    return PieceType::SIMPLE;
}

std::ostream& Gaming::operator<<(std::ostream &os, const Piece &piece)
{
    
    os << piece.getType() <<piece.__id;
    
    return os;
}




