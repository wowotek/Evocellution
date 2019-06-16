#include <iostream>

#include "lib/wowotek/glHelper.hpp"
#include "game/control.hpp"
#include "game/render.hpp"

#define WIDTH  1280
#define HEIGHT 720

void init(void){
    // Canvas -----
    glutDisplayFunc(renderDisplay);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    // ------------

    // Controls ---
    glutIgnoreKeyRepeat(1);
    glutKeyboardFunc     (keyboardDownEvent);
    glutKeyboardUpFunc   (keyboardUpEvent);
    glutMouseFunc        (mouseClickEvent);
    glutPassiveMotionFunc(mouseMoveEvent);
    glutMotionFunc       (mouseDragEvent);
    // ------------

    updateScreen(120/1000);
    gluOrtho2D(0, WIDTH, HEIGHT, 0);
}

int main(int argc, char * argv[]){
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(2220, 200);
    glutCreateWindow("Kumahasia");

    init();
    
    glutMainLoop();
}

