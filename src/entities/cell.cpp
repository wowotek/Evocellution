#include "cell.hpp"
#include "../lib/wowotek/glHelper.hpp"

Cell::Cell( float x, float y,
            float initMass, float initLipids,
            float initNitrates): Entity(x, y)
{
    isDead = false;
    age = 0;

    mass = initMass;
    lipids = initLipids;
    nitrates = initNitrates;
}

void Cell::update(void)
{   
    mass = lipids * 2;
    diameter = (mass * 5) + 120;
    lipids -= 0.000001;
}

void Cell::render(void)
{
    glColor3f(1, 0, 0);
    circle(position.x, position.y, diameter/2);
}