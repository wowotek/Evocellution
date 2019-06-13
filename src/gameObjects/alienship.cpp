#include "objects.hpp"
#include "../glHelper.hpp"

void AlienShip::render(void){
    glPushMatrix();

    rect(10, 10, 100, 100);

    glPopMatrix();
}