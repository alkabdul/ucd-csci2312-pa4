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

Resource::Resource(const Game &g, const Position &p, double capacity):Piece(g ,p){
    
    
    __capacity = capacity;
    
}