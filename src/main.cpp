#include <iostream>
#include "glHelper.hpp"

#include "gameObjects/entity.cpp"
#include "control.hpp"
#include "render.hpp"

#define WIDTH  1280
#define HEIGHT 720

void init(void);

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

    AlienShip x1(10, 10);
    x1.render();

    // Controls ---
    glutIgnoreKeyRepeat(1);
    glutKeyboardFunc        (keyboardDownEvent);
    glutKeyboardUpFunc      (keyboardUpEvent);
    glutMouseFunc           (mouseClickEvent);
    glutPassiveMotionFunc   (mouseMoveEvent);
    glutMotionFunc          (mouseDragEvent);
    // ------------

    updateScreen(120/1000);
    gluOrtho2D(0, WIDTH, HEIGHT, 0);
}

