#include "objects.hpp"

Entity::Entity(vec2f initPos){
    position = initPos;
}

Entity::Entity(int x, int y){
    position = vec2f((float)(x * 1.0), (float)(y * 1.0));
}

Entity::Entity(float x, float y){
    position = vec2f(x, y);
}

Entity::Entity(double x, double y){
    position = vec2f((float)x, (float)y);
}

Entity::Entity(std::string name, vec2f initPos){
    position = initPos;
}

Entity::Entity(std::string name, int x, int y){
    name = name;
    position = vec2f((float)(x * 1.0), (float)(y * 1.0));
}

Entity::Entity(std::string name, float x, float y){
    name = name;
    position = vec2f(x, y);
}

Entity::Entity(std::string name, double x, double y){
    name = name;
    position = vec2f((float)x, (float)y);
}