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
#include "Exceptions.h"

using namespace Gaming;
using namespace std;

PositionRandomizer Game::__posRandomizer= PositionRandomizer();





const unsigned int Game::NUM_INIT_AGENT_FACTOR = 4;
const unsigned int Game::NUM_INIT_RESOURCE_FACTOR = 2;
const unsigned int Game::MIN_WIDTH = 3;
const unsigned int Game::MIN_HEIGHT = 3;
const double Game::STARTING_AGENT_ENERGY = 20;
const double Game::STARTING_RESOURCE_CAPACITY = 10;


//Default Constructor
Game::Game(){
    
    __width = MIN_WIDTH;
    __height = MIN_HEIGHT;
    __verbose = false;
    __status = NOT_STARTED;
    __round = 0;
    for (int i = 0; i< __height * __width; i++) {
        __grid.push_back(nullptr);
    }

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
        if (__grid.at(i) !=nullptr) {
            
            if( (__grid.at(i)->getType()  == STRATEGIC)|| (__grid.at(i)->getType()  == SIMPLE)) {
                
                ++numAgents;
            }

        }
       
    }
    
    return numAgents;
}

unsigned int Game:: getNumResources() const{
    
    
    int numResources = 0;
    for (int i =0; i< __grid.size(); i++) {
        if (__grid.at(i) != nullptr) {
            if((__grid.at(i)->getType()  == ADVANTAGE)|| (__grid.at(i)->getType())  == FOOD){
            
                ++numResources;
            }

        }
        
    }
    cout<<"Agents"<<getNumAgents()<<endl;
    cout<<"Pieces"<<getNumPieces()<<endl;

    
    return getNumPieces()-getNumAgents();

    
    
}

Game::Game(unsigned width, unsigned height, bool manual){
    
    __width = width;
    __height = height;
    if (__width < MIN_WIDTH || __height < MIN_HEIGHT) {
        throw InsufficientDimensionsEx(MIN_WIDTH, MIN_HEIGHT, __width, __height);
    }
    
    __verbose = false;
    __status = NOT_STARTED;
    __round = 0;
    for (int i = 0; i< __height * __width; i++) {
        __grid.push_back(nullptr);
    }
    if (manual == false){
        
        populate();
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

//void Game::addSimple(const Position &position){
//    
//    
//    
//    
//}

void Game:: populate(){
    
    __numInitAgents = (__width * __height) / NUM_INIT_AGENT_FACTOR;
    __numInitResources = (__width * __height) / NUM_INIT_RESOURCE_FACTOR;
    unsigned int numStrategic = __numInitAgents / 2;
    unsigned int numSimple = __numInitAgents - numStrategic;
    unsigned int numAdvantages = __numInitResources / 4;
    unsigned int numFoods = __numInitResources - numAdvantages;
    // simple pseudo-random number generator
    // sufficient for our casual purposes
    std::default_random_engine gen;
    std::uniform_int_distribution<int> d(0, __width * __height);
    
    cout << "Advantages number before pop"<< numAdvantages <<endl;
    cout << "Food number before pop"<< numFoods <<endl;

    // populate Strategic agents
    while (numStrategic > 0) {
        int i = d(gen); // random index in the grid vector
        if (__grid[i] == nullptr) { // is position empty
            Position pos(i / __width, i % __width);
            __grid[i] = new Strategic(*this, pos, Game::STARTING_AGENT_ENERGY);
            numStrategic --;
        }
        
    }
    
    //counter for loop

    int numPieces = 0;
    
    for (int i =0; i< __grid.size(); i++) {
        if( __grid.at(i) != nullptr){
            
            ++numPieces;
        }
        
        
    }
    cout<<"Num strategic"<<numPieces<<endl;
    // populate Simple agents
    // ...
    
    while (numSimple > 0) {
        int i = d(gen); // random index in the grid vector
        if (__grid[i] == nullptr) { // is position empty
            Position pos(i / __width, i % __width);
            __grid[i] = new Simple(*this, pos, Game::STARTING_AGENT_ENERGY);
            numSimple--;
        }
        
    }
    numPieces = 0;

    //counter for loop

    for (int i =0; i< __grid.size(); i++) {
        if( __grid.at(i) != nullptr){
            
            ++numPieces;
        }
        
        
    }
    cout<<"Num simple"<<numPieces<<endl;

    cout<<"Numberof Food"<<numFoods<<endl;
    //populate food resources
    while (numFoods > 0) {
        int i = d(gen); // random index in the grid vector
        if (__grid[i] == nullptr) { // is position empty
            Position pos(i / __width, i % __width);
            __grid[i] = new Food(*this, pos, Game::STARTING_RESOURCE_CAPACITY);
            --numFoods ;
        }
    }
    numPieces = 0;

    //counter for loop

    for (int i =0; i< __grid.size(); i++) {
        if( __grid.at(i) != nullptr){
            
            ++numPieces;
        }
        
        
    }

    cout<<"Num Food"<<numPieces<<endl;

    
    //Populate Advantage resources
    
    while (numAdvantages> 0) {
        int i = d(gen); // random index in the grid vector
        if (__grid[i] == nullptr) { // is position empty
            Position pos(i / __width, i % __width);
            __grid[i] = new Advantage(*this, pos, Game::STARTING_RESOURCE_CAPACITY);
            numAdvantages --;
        }
    }
    
    numPieces = 0;
//counter for loop
    for (int i =0; i< __grid.size(); i++) {
        if( __grid.at(i) != nullptr){
            
            ++numPieces;
        }
        
        
    }

    cout<<"Num Advantages"<<numPieces<<endl;

    
    
    
    
}

void Game::addSimple(unsigned x, unsigned y){
    
    
    int indexPos= (x*__width)+y;
   
    __grid[indexPos] = new Simple(*this, Position(x,y), STARTING_AGENT_ENERGY);
;

    
}
void Game::addStrategic(unsigned x, unsigned y, Strategy *s ){
    
    
    if (x >= __height || y >= __width) {
        throw OutOfBoundsEx(__width, __height, x, y);
    }
    
    


    if (__grid.at(y+x*__width) != nullptr) {
        throw PositionNonemptyEx(x, y);
    }

    int indexPos= (x*__height)+y;
    
    
    __grid[indexPos] = new Strategic(*this, Position(x, y), STARTING_AGENT_ENERGY, s);

    
}

void Game::addStrategic(const Position &position, Strategy *s){
    int x = position.x;
    int y = position.y;
    if (x >= __height || y >= __width) {
        throw OutOfBoundsEx(__width, __height, x, y);
    }
    if (__grid.at(y+x*__width) != nullptr) {
        throw PositionNonemptyEx(x, y);
    }
    
    int indexPos= (x*__height)+y;
    
    
    __grid[indexPos] =  new Strategic(*this, Position(x, y), STARTING_AGENT_ENERGY, s);;
    
    
}

    
    
    




void Game::addFood(unsigned x, unsigned y){
    
    if (__grid.at(y+x*__width) != nullptr) {
        throw PositionNonemptyEx(x, y);
    }

    int indexPos= (x*__height)+y;
    
    __grid[indexPos] =    new Food(*this, Position(x, y), STARTING_RESOURCE_CAPACITY);


}

void Game:: addAdvantage(unsigned x, unsigned y){
    
    
    if (x >= __height || y >= __width) {
        throw OutOfBoundsEx(__width, __height, x, y);
    }

    
    
    int indexPos= (x*__height)+y;
    
    __grid[indexPos] =new Advantage(*this, Position(x, y), STARTING_RESOURCE_CAPACITY);
    
}
std::ostream& Gaming::operator<<(std::ostream &os, const Game &game){
    
    
    
    return os;
}


