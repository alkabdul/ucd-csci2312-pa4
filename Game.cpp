//
//  Game.cpp
//  PA4
//
//  Created by Abdulrahman Alkaabi on 4/13/16.
//  Copyright © 2016 Abdulrahman Alkaabi. All rights reserved.
//

#include <stdio.h>
#include <map>
#include "Game.h"
#include "Advantage.h"
#include "Agent.h"
#include "AggressiveAgentStrategy.h"
#include "Food.h"
#include "Resource.h"
#include "Simple.h"
#include "Strategic.h"
#include "Piece.h"
using namespace Gaming;





//const char Advantage::ADVANTAGE_ID = 'D';
//const double Advantage::ADVANTAGE_MULT_FACTOR = 2.0;
//const double Agent::AGENT_FATIGUE_RATE = 0.3;
//const double AggressiveAgentStrategy::DEFAULT_AGGRESSION_THRESHOLD = Game::STARTING_AGENT_ENERGY * 0.75;
//const char Food::FOOD_ID = 'F';
//const unsigned int Game::NUM_INIT_AGENT_FACTOR = 4;
//const unsigned int Game::NUM_INIT_RESOURCE_FACTOR = 2;
const unsigned int Game::MIN_WIDTH = 3;
const unsigned int Game::MIN_HEIGHT = 3;
const double Game::STARTING_AGENT_ENERGY = 20;
const double Game::STARTING_RESOURCE_CAPACITY = 10;
//const double Resource::RESOURCE_SPOIL_FACTOR = 1.2;
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

unsigned int Game:: getNumAgents() const{
    int numAgents = 0;
    for (int i =0; i< __grid.size(); i++) {
        if( typeid(__grid.at(i))  == typeid(Agent)){
            
            ++numAgents;
        }

    }
    
    return numAgents;
}

unsigned int Game:: getNumResources() const{
    
    
    int numResources = 0;
    for (int i =0; i< __grid.size(); i++) {
        if( typeid(__grid.at(i))  == typeid(Resource)){
            
            ++numResources;
        }
        
    }
    
    return numResources;

    
    
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
Game::Game(const Game &another){
    __grid = another.__grid;
    __width = another.__width;
    __height = another.__height;
    __numInitAgents = another.__numInitAgents;
    __numInitResources = another.__numInitResources;
    __status = another.__status;
    __verbose = another.__verbose;
    __posRandomizer = another.__posRandomizer;
    
    
    
    
    
}
    
    
    
    

//
//Game& Game::operator=(const Game &other) {
//    
//    
//    
//    return *this;
//    
//}

void Game::addSimple(const Position &position){
    
    
    
    
}

void Game::addSimple(unsigned x, unsigned y){
    
    int indexPos= (x*__height)+y;
    Simple mySimple = Simple(*this, Position(x,y), STARTING_AGENT_ENERGY);
   
    __grid.insert(__grid.begin()+indexPos, &mySimple);

    
}
void Game::addStrategic(unsigned x, unsigned y, Strategy *s ){
    
    int indexPos= (x*__height)+y;
    Strategic myStrategic = Strategic(*this, Position(x, y), STARTING_AGENT_ENERGY);
    
    
    __grid.insert(__grid.begin()+indexPos, &myStrategic);

    
}

void Game::addFood(unsigned x, unsigned y){
    
    int indexPos= (x*__height)+y;
    Food myFood = Food(*this, Position(x, y), STARTING_RESOURCE_CAPACITY);
    
    __grid.insert(__grid.begin()+indexPos, &myFood);

}

void Game:: addAdvantage(unsigned x, unsigned y){
    
    int indexPos= (x*__height)+y;
    Advantage myAdvantage = Advantage(*this, Position(x, y), STARTING_RESOURCE_CAPACITY);
    
    __grid.insert(__grid.begin()+indexPos, &myAdvantage);

    
}


