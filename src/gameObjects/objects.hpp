#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include <iostream>
#include "../utils/type.hpp"

class Entity{
    protected:
        vec2f position;
        std::string name = "Unnamed";
    public:
        explicit Entity(vec2f);                         // |
        explicit Entity(float, float);                  // |
                                                        // +--> Constructors
        explicit Entity(std::string, vec2f);            // |
        explicit Entity(std::string, float, float);     // |

        void render(void){
            std::cout << "Not-Implemented" << std::endl;
        }
};

class AlienShip: public Entity{
    using Entity::Entity;

    private:
        void renderShip(void);
        
    public:
        void render(void);
};

#endif