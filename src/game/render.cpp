#include "render.hpp"

void renderDisplay(void){
    glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
    glutPostRedisplay();
}

void updateScreen(int time){
    glutPostRedisplay();
    glutTimerFunc(time, updateScreen, time);
}