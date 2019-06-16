#include "render.hpp"

#include "../entities/cell.hpp"

Cell c1(50, 50, 10, 10, 10);

void renderDisplay(void)
{
    c1.render();

    glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
    glutPostRedisplay();
}

void updateScreen(int time)
{
    c1.update();

    glutPostRedisplay();
    glutTimerFunc(time, updateScreen, time);
}