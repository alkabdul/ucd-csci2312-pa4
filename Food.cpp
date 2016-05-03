#include "Game.h"
#include "Food.h"

const char Gaming::Food::FOOD_ID = 'F';

Gaming::Food::Food(const Gaming::Game &g, const Gaming::Position &p, double capacity) : Resource(g,p,capacity){}

Gaming::Food::~Food() {}

void Gaming::Food::print(std::ostream &os) const {
    os << FOOD_ID;
}
