#ifndef GLHELPER_HPP
#define GLHELPER_HPP

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

#include "type.hpp"

//--------------------------------------------- INTERNAL DEFINITION
#define DEFAULT_POINT_SIZE 1
#define DEFAULT_WINDOW_POS_X 0
#define DEFAULT_WINDOW_POS_Y 0

//--------------------------------------------- INITIALIZER HELPER
void initGLWindow(GLint width, GLint height,
            GLint posX, GLint posY,
            const char * window_name, 
            GLenum display_mode_switches)
{
    glutInitDisplayMode(display_mode_switches);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(posX, posY);
    glutCreateWindow(window_name);
}

//--------------------------------------------- PRIMITIVE 2D SHAPE
void point(GLfloat x ,GLfloat y)
{
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
}

void line(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
    glBegin(GL_LINES);
        glVertex2f(x1, y1); glVertex2f(x2, y2);
    glEnd();
}

void rect(GLfloat x, GLfloat y, GLfloat width, GLfloat height, GLenum SHAPE_MODE) {
    glBegin(mode);
        glVertex2f(x, y); glVertex2f(x + width, y);
        glVertex2f(x + width, y + height); glVertex2f(x, y + height);
    glEnd();
}

void rect(GLfloat x, GLfloat y, GLfloat width, GLfloat height){
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); glVertex2f(x + width, y);
        glVertex2f(x + width, y + height); glVertex2f(x, y + height);
    glEnd();
}

void rect(vec2f pos, vec2f size){
    rect(pos.x, pos.y, size.x, size.y);
}

void rect(vec2f pos, vec2f size, GLenum SHAPE_MODE){

}

void polym(GLfloat x, GLfloat y, GLfloat size, GLfloat sides, GLfloat rotation, GLenum SHAPE_MODE){
    GLfloat angleIncrement = (360.0f / sides) * M_PI / 180.0f;
    glBegin(SHAPE_MODE);
        GLfloat angle = 0.0f - rotation;
        for (size_t _k = 0; _k < sides; ++_k) {
            glVertex2f(x + (size * cos(angle)), y + (size * sin(angle)));
            angle += angleIncrement;
        }
    glEnd();
}

void poly(GLfloat x, GLfloat y, GLfloat size, GLfloat sides, GLfloat rotation) {
    polym(x, y, size, sides, rotation, GL_TRIANGLE_FAN);
}

void circlem(GLfloat x, GLfloat y, GLfloat radius, GLenum SHAPE_MODE) {
    polym(x, y, radius, 720, 0, SHAPE_MODE);
}

void circle(GLfloat x, GLfloat y, GLfloat radius) {
    poly(x, y, radius, 720, 0);
}

//--------------------------------------------- Events

#endif