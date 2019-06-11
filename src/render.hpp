#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "control.hpp"

void renderDisplay(){
    
}

void updateScreen(int time){
    glutPostRedisplay();
    glutTimerFunc(time, updateScreen, time);
}