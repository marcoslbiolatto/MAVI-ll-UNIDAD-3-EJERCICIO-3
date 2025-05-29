#ifndef SFML_RENDERER_H
#define SFML_RENDERER_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class SFMLRenderer {
public:
    void run(b2World* world, b2Body* ball, b2Body* triangle);
};

#endif // SFML_RENDERER_H
