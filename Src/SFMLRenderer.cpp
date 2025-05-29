#include "SFMLRenderer.h"

static const float SCALE = 30.f; // Convertir metros a píxeles

void SFMLRenderer::run(b2World* world, b2Body* ball, b2Body* triangle) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pelota Conectada por Hilo");

    sf::CircleShape ballVisual(15.f);
    ballVisual.setFillColor(sf::Color::Green);
    ballVisual.setOrigin(15.f, 15.f);

    sf::ConvexShape triangleVisual;
    triangleVisual.setPointCount(3);
    triangleVisual.setPoint(0, sf::Vector2f(0.f, -15.f));  // Vértice superior
    triangleVisual.setPoint(1, sf::Vector2f(-15.f, 15.f)); // Vértice inferior izquierdo
    triangleVisual.setPoint(2, sf::Vector2f(15.f, 15.f));  // Vértice inferior derecho
    triangleVisual.setFillColor(sf::Color::Blue);
    triangleVisual.setOrigin(0.f, 0.f);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds();
        world->Step(deltaTime, 8, 3);

        ballVisual.setPosition(ball->GetPosition().x * SCALE, ball->GetPosition().y * SCALE);
        triangleVisual.setPosition(triangle->GetPosition().x * SCALE, triangle->GetPosition().y * SCALE);

        sf::VertexArray line(sf::Lines, 2);
        line[0].position = sf::Vector2f(triangle->GetPosition().x * SCALE, triangle->GetPosition().y * SCALE);
        line[0].color = sf::Color::White;
        line[1].position = sf::Vector2f(ball->GetPosition().x * SCALE, ball->GetPosition().y * SCALE - 15.f);
        line[1].color = sf::Color::White;

        window.clear();
        window.draw(line);
        window.draw(triangleVisual);
        window.draw(ballVisual);
        window.display();
    }
}


