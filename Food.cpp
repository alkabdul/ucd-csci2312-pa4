//
//  Food.cpp
//  PA4
//
//  Created by Abdulrahman Alkaabi on 4/13/16.
//  Copyright © 2016 Abdulrahman Alkaabi. All rights reserved.
//

#include <stdio.h>
#include "Food.h"

using namespace Gaming;

const char Food::FOOD_ID = 'F';


Food::Food(const Game &g, const Position &p, double capacity):Resource(g,p,capacity){
    
    
    
}

Food::~Food(){
    
    
    
}

void Food::print(std::ostream &os) const{
    
    std::cout<<"FOOD$$$$$$$$$$$"<<std::endl;
    
    
}




PieceType Piece::getType() const{
    
    
    return PieceType::FOOD;
}
std::ostream& Gaming::operator<<(std::ostream &os, const Piece &piece)
{
    
    os << piece.getType() <<piece.__id;
    
    return os;
}





