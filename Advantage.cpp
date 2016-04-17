//
//  Advantage.cpp
//  PA4
//
//  Created by Abdulrahman Alkaabi on 4/13/16.
//  Copyright © 2016 Abdulrahman Alkaabi. All rights reserved.
//

#include <stdio.h>
#include "Advantage.h"

using namespace Gaming;

const char Advantage::ADVANTAGE_ID = 'D';
const double Advantage::ADVANTAGE_MULT_FACTOR = 2.0;


Advantage::Advantage(const Game &g, const Position &p, double capacity):Resource(g, p, capacity){
    
    
    __capacity *= ADVANTAGE_MULT_FACTOR;


}

Advantage::~Advantage(){
    
    
    
}
double Advantage:: consume(){
    
    
    
    return 0.0;
}

double Advantage:: getCapacity() const{
    
    return __capacity;
    
}


void Advantage::print(std::ostream &os)const{
    
    std::cout<<"ADVANTAGE!!!!!"<<std::endl;
    
}



PieceType Piece::getType() const{
    
    
    return PieceType::ADVANTAGE;
}

std::ostream& Gaming::operator<<(std::ostream &os, const Piece &piece)
{
    
    os << piece.getType() <<piece.__id;
    
    return os;
}




