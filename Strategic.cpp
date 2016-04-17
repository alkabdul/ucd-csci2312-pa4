//
//  Strategic.cpp
//  PA4
//
//  Created by Abdulrahman Alkaabi on 4/13/16.
//  Copyright © 2016 Abdulrahman Alkaabi. All rights reserved.
//

#include <stdio.h>
#include "Strategic.h"
using namespace Gaming;
const char Strategic::STRATEGIC_ID = 'T';


Strategic::Strategic (const Game &g, const Position &p, double energy, Strategy *s):Agent(g, p, energy){
    
    
    setPosition(p);
    setTurned(false);

    
    
}

Strategic::~Strategic(){
    
    
    
}

void Strategic:: print(std::ostream &os) const{
    
    
    std::cout<<"STRATEGIC@@@@@@@@@@@@@"<<std::endl;
    
}

ActionType Strategic:: takeTurn(const Surroundings &s) const{
    
    
    ActionType temp = SE;
    return temp;
    
}


PieceType Piece::getType() const{
    
    
    return PieceType::STRATEGIC;
}
std::ostream& Gaming::operator<<(std::ostream &os, const Piece &piece)
{
    
    os << piece.getType() <<piece.__id;
    
    return os;
}





