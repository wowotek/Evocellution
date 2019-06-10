#include "objects/entities.cpp"

#include "mouse.cpp"
#include "render.cpp"

#define WIDTH 1280
#define HEIGHT 720

void renderDisplay(void);
void init(void);
void updateScreen(GLint);
void keyboardEvent(unsigned char, int, int);
void mouseEvent(int, int, int, int);

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    initGLWindow(
        WIDTH, HEIGHT,
        2880, 540, "Kumahasia",
        GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE
    );
    init();

    glutMainLoop();
    return 0;
}

void init(void){
    glutDisplayFunc(renderDisplay);

    // Controls
    glutIgnoreKeyRepeat(1);
    glutKeyboardFunc(keyboardDownEvent);
    glutKeyboardUpFunc(keyboardUpEvent);
    glutMouseFunc(mouseClickEvent);
    glutPassiveMotionFunc(mouseMoveEvent);
    glutMotionFunc(mouseDragEvent);

    updateScreen(TO_FPS(120));

    glPointSize(10);
    gluOrtho2D(0, WIDTH, HEIGHT, 0);
}

