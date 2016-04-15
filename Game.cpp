//
//  Game.cpp
//  PA4
//
//  Created by Abdulrahman Alkaabi on 4/13/16.
//  Copyright © 2016 Abdulrahman Alkaabi. All rights reserved.
//

#include <stdio.h>
#include "Game.h"
#include "Advantage.h"
#include "Agent.h"
#include "AggressiveAgentStrategy.h"
#include "Food.h"
#include "Resource.h"
#include "Simple.h"
#include "Strategic.h"
using namespace Gaming;

//const char Advantage::ADVANTAGE_ID = 'D';
//const double Advantage::ADVANTAGE_MULT_FACTOR = 2.0;
//const double Agent::AGENT_FATIGUE_RATE = 0.3;
////const double AggressiveAgentStrategy::DEFAULT_AGGRESSION_THRESHOLD = Game::STARTING_AGENT_ENERGY * 0.75;
//const char Food::FOOD_ID = 'F';
//const unsigned int Game::NUM_INIT_AGENT_FACTOR = 4;
//const unsigned int Game::NUM_INIT_RESOURCE_FACTOR = 2;
const unsigned int Game::MIN_WIDTH = 3;
const unsigned int Game::MIN_HEIGHT = 3;
//const double Game::STARTING_AGENT_ENERGY = 20;
//const double Game::STARTING_RESOURCE_CAPACITY = 10;
//const double Resource::RESOURCE_SPOIL_FACTOR = 1.2;
//const char Simple::SIMPLE_ID = 'S';
//const char Strategic::STRATEGIC_ID = 'T';


//Default Constructor
Game::Game(){
    
    __width = MIN_WIDTH;
    __height = MIN_HEIGHT;
    //__numInitAgents
    
}

unsigned int Game:: getNumPieces() const{
    
    
//    for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
//        std::cout << ' ' << *it;
    
   int numPieces =0;
//    for (std::vector<Piece *>::iterator it = __grid.begin(); it != __grid.end(); ++it) {
//        
//        if (*it != nullptr){
//            ++numPieces;
//        }
//        
//        
//    }
    
    for (int i =0; i< __grid.size(); i++) {
        if( __grid.at(i) != nullptr){
            
            ++numPieces;
        }

        
    }
    
    return numPieces;
}

Game::Game(unsigned width, unsigned height, bool manual){
    
    __width = width;
    __height = height;
    if (__width < MIN_WIDTH || __height < MIN_HEIGHT) {
        throw InsufficientDimensionsEx(MIN_WIDTH, MIN_HEIGHT, __width, __height);
    }
    
    
    
}


//Distructor


Game::~Game(){
    
    
    
    
}




