#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include <iostream>
#include "../type.hpp"

class Entity{
    protected:
        vec2f position;
        std::string name = "Unnamed";
    public:
        explicit Entity(vec2f);                         // |
        explicit Entity(int, int);                      // |
        explicit Entity(float, float);                  // |
        explicit Entity(double, double);                // |
                                                        // +--> Constructors
        explicit Entity(std::string, vec2f);            // |
        explicit Entity(std::string, int, int);         // |
        explicit Entity(std::string, float, float);     // |
        explicit Entity(std::string, double, double);   // |

        void render(void){
            std::cout << "Not-Implemented" << std::endl;
        }
};

class AlienShip: public Entity{
    using Entity::Entity;
    public:
        void render(void);
};

#endif