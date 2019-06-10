#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

// #include <GL/gl.h>
// #include <GL/glu.h>
// #include <GL/glut.h>
#include "../util/wo2glib.hpp"
#include "../util/wo2util.hpp"

class Keys{
    private:
        GLubyte key;

    public:
        vec2i mouseCoord;

        Keys(GLubyte, vec2i);
        void setCoord(GLint, GLint);
        vec2i getCoord(void);
        GLubyte getKey(void);
};

Keys::Keys(GLubyte key, vec2i mouseCoord){
    key = key;
    mouseCoord = mouseCoord;
}

void Keys::setCoord(GLint x, GLint y){
    mouseCoord.x = x;
    mouseCoord.y = y;
}

vec2i Keys::getCoord(void){
    return mouseCoord;
}

GLubyte Keys::getKey(void){
    return key;
}

#endif