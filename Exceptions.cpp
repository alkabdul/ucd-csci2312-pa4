//
//  Exceptions.cpp
//  PA4
//
//  Created by Abdulrahman Alkaabi on 4/13/16.
//  Copyright © 2016 Abdulrahman Alkaabi. All rights reserved.
//

#include <stdio.h>
#include "Exceptions.h"

using namespace Gaming;
DimensionEx::DimensionEx(unsigned expWidth, unsigned expHeight, unsigned width, unsigned height){
    __exp_width = expWidth;
    __exp_height = expHeight;
    __width = width;
    __height = height;
    __name = "DimensionsEx";
    
    
}




InsufficientDimensionsEx::InsufficientDimensionsEx(unsigned minWidth, unsigned minHeight, unsigned width, unsigned height) : DimensionEx(minWidth, minHeight,  width,  height){
   
    __exp_width= minWidth;
    __exp_height = minHeight;
    __width = width;
    __height = height;
    __name = "InsufficientDimensionsEx";
    
    
}
 void InsufficientDimensionsEx:: __print_args(std::ostream &os)const{
    
    
  //  os << getExpWidth()<<std::endl;
    

    
}

std::ostream& Gaming:: operator<<(std::ostream &os, const GamingException &ex){
    
    os << ex.__name << std::endl;
    return os;
}


OutOfBoundsEx::OutOfBoundsEx(unsigned maxWidth, unsigned maxHeight, unsigned width, unsigned height): DimensionEx(maxWidth, maxHeight,  width,  height) {
    
    __exp_width= maxWidth;
    __exp_height = maxHeight;
    __width = width;
    __height = height;
    __name = "OutOfBoundsEx";

}

void OutOfBoundsEx::  __print_args(std::ostream &os) const{
    
    
    std:: cout << __exp_width << " , " << __exp_height << " , " << __width << " , " << __height <<std::endl;
    
    
}



PositionEx::PositionEx(unsigned x, unsigned y){
    __x = x;
    __y = y;
    __name ="PositionEx";
    
    
}
void PositionEx::__print_args(std::ostream &os)const{
    
    std::cout<< __x << " , " << __y <<std::endl;
    
    
    
}

PositionNonemptyEx::PositionNonemptyEx(unsigned x, unsigned y):PositionEx(x,y){
__name ="PositionNonemptyEx";
    
    
    
}
PositionEmptyEx::PositionEmptyEx(unsigned x , unsigned y):PositionEx(x,y){
    
    __name = "PositionEmptyEx";
    
    
}











