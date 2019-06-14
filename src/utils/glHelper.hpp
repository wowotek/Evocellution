#ifndef GLHELPER_HPP
#define GLHELPER_HPP

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

#include "type.cpp"

void initGLWindow();

void point(GLfloat, GLfloat);

void line(GLfloat, GLfloat, GLfloat, GLfloat);

void rect(GLfloat, GLfloat, GLfloat, GLfloat, GLenum);
void rect(GLfloat, GLfloat, GLfloat, GLfloat);
void rect(vec2f, vec2f, GLenum);
void rect(vec2f, vec2f);

void poly(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLenum);
void poly(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
void poly(vec2f, GLfloat, GLfloat, GLfloat);

void circle(GLfloat, GLfloat, GLfloat, GLenum);
void circle(vec2f, GLfloat, GLenum);
void circle(GLfloat, GLfloat, GLfloat);
void circle(vec2f, GLfloat);

GLuint loadTexture(const char*, GLint, GLint);


#endif