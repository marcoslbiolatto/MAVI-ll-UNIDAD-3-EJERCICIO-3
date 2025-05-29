#ifndef GAME_H
#define GAME_H

#include "SFMLRenderer.h"

class Game {
private:
    b2World* world;           // Mundo físico
    SFMLRenderer renderer;    // Renderizador
    b2Body* ball;             // Pelota dinámica
    b2Body* triangle;         // Triángulo estático

public:
    Game();  // Constructor
    ~Game(); // Destructor
    void start(); // Iniciar simulación y renderizado
};

#endif // GAME_H
