#ifndef GAME_H
#define GAME_H

#include "SFMLRenderer.h"

class Game {
private:
    b2World* world;           // Mundo f�sico
    SFMLRenderer renderer;    // Renderizador
    b2Body* ball;             // Pelota din�mica
    b2Body* triangle;         // Tri�ngulo est�tico

public:
    Game();  // Constructor
    ~Game(); // Destructor
    void start(); // Iniciar simulaci�n y renderizado
};

#endif // GAME_H
