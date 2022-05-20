#include "World.h"

World::World(void) {}

World::~World()
{
    std::size_t s = objects.size();
    for (std::size_t i = 0; i < s; ++i)
    {
        delete objects[i];
    }
    camera.~Camera();
}