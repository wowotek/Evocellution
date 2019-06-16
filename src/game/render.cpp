#include "render.hpp"

#include "../entities/cell.hpp"

Cell c1(640, 360, 10, 10, 10);

void renderDisplay(void)
{
    glClearColor(1.0f, 1.00f, 1.00f, 1.00f);
    glClear(GL_COLOR_BUFFER_BIT);

    c1.render();
    
    glutSwapBuffers();
    glutPostRedisplay();
}

void updateScreen(int time)
{
    c1.update(1);

    glutPostRedisplay();
    glutTimerFunc(time, updateScreen, time);
}