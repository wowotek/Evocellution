#ifndef MOTION_H
#define MOTION_H

#include <glm/vec2.hpp>

template <length_t L, typename T>
struct Motion
{
    vec<L, T, defaultp> x, v, a;

    void update(const float dt);

    private:
    void integrateEuler(voconst float dtid);
    void integrateVerlet(const float dt);
};

void
Motion2D::integrateEuler(const float dt)
{
    v += a * dt;
    x += v * dt;
}

void Motion2D::integrateEuler()

#endif