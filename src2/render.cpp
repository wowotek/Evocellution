#ifndef RENDER_HPP
#define RENDER_HPP

#include <iostream>
#include "util/wo2glib.hpp"
#include "util/wo2util.hpp"
#include "keyboard.cpp"

void renderDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);

    rect(100, 100, 200, 200);

    glutSwapBuffers();
}

void updateScreen(GLint refreshRate){
    glutPostRedisplay();
    glutTimerFunc(refreshRate, updateScreen, refreshRate);
    for(size_t i=0; i<keyPresses.size(); i++){
        std::cout << keyPresses[i].getKey() << " << ";
    }
    std::cout << std::endl; fflush(stdout);
}

#endif