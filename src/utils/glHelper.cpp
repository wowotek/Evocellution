#include "glHelper.hpp"

#include <iostream>

void initGLWindow(  GLint width, GLint height,
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
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

void rect(GLfloat x, GLfloat y, GLfloat width, GLfloat height, GLenum SHAPE_MODE) {
    glBegin(SHAPE_MODE);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
    glEnd();
}

void rect(GLfloat x, GLfloat y, GLfloat width, GLfloat height){
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
    glEnd();
}

void rect(vec2f pos, vec2f size, GLenum SHAPE_MODE){
    rect(pos.x, pos.y, size.x, size.y, SHAPE_MODE);
}

void rect(vec2f pos, vec2f size){
    rect(pos.x, pos.y, size.x, size.y);
}

void circle(GLfloat x, GLfloat y, GLfloat size, GLfloat sides, GLfloat rotation, GLenum SHAPE_MODE){
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
    poly(x, y, size, sides, rotation, GL_TRIANGLE_FAN);
}

void poly(vec2f pos, GLfloat size, GLfloat sides, GLfloat rotation){
    poly(pos.x, pos.y, size, sides, rotation, GL_TRIANGLE_FAN);
}

void circle(GLfloat x, GLfloat y, GLfloat radius, GLenum SHAPE_MODE) {
    poly(x, y, radius, 720.0, 0.0, SHAPE_MODE);
}

void circle(vec2f pos, GLfloat radius, GLenum SHAPE_MODE){
    poly(pos.x, pos.y, radius, 720.0, 0.0, SHAPE_MODE);
}

void circle(GLfloat x, GLfloat y, GLfloat radius) {
    poly(x, y, radius, 720.0, 0.0);
}

void circle(vec2f pos, GLfloat radius){
    poly(pos.x, pos.y, radius, 720.0, 0.0);
}

//--------------------------------------------- TEXTURING
GLuint loadTexture(const char * filename, int width, int height){
    FILE * file = fopen( filename, "rb" );

    if (file == NULL){
        return 0;
    } else {
        GLuint texture;
        unsigned char * data;
        data = (unsigned char *)malloc( width * height * 3 );
        //int size = fseek(file,);
        fread( data, width * height * 3, 1, file );
        fclose( file );

        for(int i = 0; i < width * height ; ++i){
            int index = i*3;
            unsigned char B,R;
            B = data[index];
            R = data[index+2];

            data[index] = R;
            data[index+2] = B;
        }
        
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);


        glTexParameterf  (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameterf  (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
        glTexParameterf  (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data);
        free(data);

        return texture;
    }
}