#include "entity.hpp"



Entity::Entity(vec2f initPos)
{
    position = initPos;
}

Entity::Entity(float x, float y)
{
    position = vec2f(x, y);
}

Entity::Entity(std::string name, vec2f initPos)
{
    position = initPos;
}

Entity::Entity(std::string name, float x, float y)
{
    name = name;
    position = vec2f(x, y);
}

void Entity::update(float h)
{
    position += velocity * h; // euler method
}

void Entity::render(void){
    std::cout << "Not Rendered Yet" << std::endl;
}