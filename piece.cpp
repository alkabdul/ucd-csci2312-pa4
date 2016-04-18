//
//  piece.cpp
//  PA4
//
//  Created by Abdulrahman Alkaabi on 4/13/16.
//  Copyright © 2016 Abdulrahman Alkaabi. All rights reserved.
//

#include <stdio.h>
#include "Piece.h"

using namespace Gaming;

unsigned int Piece:: __idGen = 0;

Piece::Piece(const Game &g, const Position &p):__game(g), __position(p){
    
    __finished = false;
    __turned = false;
    __id = __idGen++;
    
}
 Piece::~Piece(){
    
    
}

std::ostream& Gaming:: operator<<(std::ostream &os, const Piece &piece){
    
    piece.print(os);
    return os;
    
}