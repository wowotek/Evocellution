#ifndef CELL_HPP
#define CELL_HPP

#include "entity.hpp"

class Cell: public Entity
{
    private:
        float age;
        float mass;
        float diameter;

        float lipids;
        float nitrates;

        bool isDead;

        void getRadius(void);
    public:
        Cell(float, float, float, float, float);

        void render(void);
        void update(void);
};

#endif // CELL_HPP