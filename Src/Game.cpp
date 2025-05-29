#include "Game.h"

Game::Game() {
    // Configuración del mundo con gravedad
    b2Vec2 gravity(0.f, 9.8f);
    world = new b2World(gravity);

    // Crear el triángulo estático
    b2BodyDef triangleDef;
    triangleDef.type = b2_staticBody;
    triangleDef.position.Set(10.f, 5.f); // Centro del triángulo
    triangle = world->CreateBody(&triangleDef);

    b2PolygonShape triangleShape;
    b2Vec2 vertices[3];
    vertices[0].Set(0.f, 0.9f);    // Vértice superior
    vertices[1].Set(-0.5f, -0.9f); // Vértice inferior izquierdo
    vertices[2].Set(0.5f, -0.9f);  // Vértice inferior derecho
    triangleShape.Set(vertices, 3);
    triangle->CreateFixture(&triangleShape, 0.f);

    // Crear la pelota dinámica
    b2BodyDef ballDef;
    ballDef.type = b2_dynamicBody;
    ballDef.position.Set(1.f, 1.f); // Posición inicial (bajo el triángulo)
    ball = world->CreateBody(&ballDef);

    b2CircleShape ballShape;
    ballShape.m_radius = 0.5f;

    b2FixtureDef ballFixture;
    ballFixture.shape = &ballShape;
    ballFixture.density = 1.f;
    ballFixture.restitution = 0.8f; // Elasticidad para rebote
    ball->CreateFixture(&ballFixture);

    // Conectar la pelota al triángulo con un revolute joint (hilo)
    b2RevoluteJointDef revoluteDef;
    revoluteDef.bodyA = triangle;
    revoluteDef.bodyB = ball;
    revoluteDef.localAnchorA.Set(0.f, 2.f);   // Centro del triángulo
    revoluteDef.localAnchorB.Set(0.f, -1.9f); // Parte superior de la pelota
    world->CreateJoint(&revoluteDef);
}

Game::~Game() {
    delete world; // Limpieza
}

void Game::start() {
    renderer.run(world, ball, triangle);
}
