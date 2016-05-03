#include "Game.h"
#include "Advantage.h"

const char Gaming::Advantage::ADVANTAGE_ID = 'D';
const double Gaming::Advantage::ADVANTAGE_MULT_FACTOR = 2.0;

Gaming::Advantage::Advantage(const Gaming::Game &g, const Position &p, double capacity) : Resource(g,p,capacity*ADVANTAGE_MULT_FACTOR)
{
}

Gaming::Advantage::~Advantage() {}

void Gaming::Advantage::print(std::ostream &os) const {
    os << ADVANTAGE_ID;
}

double Gaming::Advantage::getCapacity() const {
    return Resource::getCapacity();
}

double Gaming::Advantage::consume() {
    return Resource::consume();
}
