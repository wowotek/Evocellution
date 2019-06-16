#include "cell.hpp"
#include "../lib/wowotek/glHelper.hpp"

#include <math.h>

Cell::Cell( float x, float y,
            float initMass, float initLipids,
            float initNitrates): Entity(x, y)
{
    isDead = false;
    age = 0;

    mass = initMass;
    nitrates = initNitrates;

    acceleration = vec2f(0.000005f, 0.000005f);
}

void Cell::update(float dt)
{
    if(mass < 0.5){isDead = true; return;}

    mass -= 0.000005f;
    diameter = (mass * 1*2) + 200;

    std::cout << "Position: " << position << " ";
    std::cout << "Velocity: " << velocity << " ";
    std::cout << "Acceleration: " << acceleration << " ";
    std::cout << std::endl;

    fflush(stdout);

    // velocity = intergal of a ?
    position += velocity * dt;

} 

void Cell::render(void)
{
    if(!isDead)
    {
        glColor4f(r, g, b, 1);
        circle(position.x, position.y, diameter/2, GL_LINE_LOOP);

        glColor4f(r, g, b, 0.5);
        circle(position.x, position.y, diameter/2);

    }
}