#include <iostream>
#include "glHelper.hpp"

#include "control.cpp"
#include "render.cpp"

#define WIDTH  1280
#define HEIGHT 720

int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    initGLWindow(
        WIDTH, HEIGHT,
        2880, 540, "Kumahasia",
        GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE
    );
    init();
    

    glutMainLoop();
}

void init(void){
    // Canvas -----
    glutDisplayFunc(renderDisplay);
    // ------------

    // Controls ---
    ControlHandler controlHandler;

    glutIgnoreKeyRepeat(1);
    glutKeyboardFunc        (controlHandler.keyboardDownEvent);
    glutKeyboardUpFunc      (controlHandler.keyboardUpEvent);
    glutMouseFunc           (controlHandler.mouseClickEvent);
    glutPassiveMotionFunc   (controlHandler.mouseMoveEvent);
    glutMotionFunc          (controlHandler.mouseDragEvent);
    // ------------

    updateScreen(120/1000);
    gluOrtho2D(0, WIDTH, HEIGHT, 0);
}