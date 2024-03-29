#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include <iostream>
#include "../lib/wowotek/type.hpp"

class Entity
{
    protected:
        vec2f position;
        vec2f velocity;
        vec2f acceleration;

        std::string name = "Unnamed";

        float r, g, b;
    public:
        explicit Entity(vec2f);                         // |
        explicit Entity(float, float);                  // |
                                                        // +--> Constructors
        explicit Entity(std::string, vec2f);            // |
        explicit Entity(std::string, float, float);     // |

        void render(void);
        void update(float h);
};

#endif

