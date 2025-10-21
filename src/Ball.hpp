#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"

using namespace sf;

class Ball
{
    private:
        float spawnX;
        float spawnY;
        CircleShape ball;
        sf::Vector2f velocity;
        float speed;
    public:
        Ball(int x, int y, int radius);
        void moveBall();
        void drawBall(RenderWindow& window);
        void resetBall();
        void collisionHandle(Paddle& paddle1, Paddle& paddle2);
};

#endif
