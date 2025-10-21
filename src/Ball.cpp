#include <iostream>
#include "Ball.hpp"

Ball::Ball(int x, int y, int radius)
{
    spawnX = x;
    spawnY = y;

    ball = sf::CircleShape(radius);
    ball.setPosition(sf::Vector2f(x, y));

    velocity = sf::Vector2f(4.0f, 2.0f);
    speed = 1.0f;
}

void Ball::moveBall()
{
    ball.setPosition(ball.getPosition().x + velocity.x * speed, ball.getPosition().y + velocity.y * speed);
}

void Ball::drawBall(RenderWindow& window)
{
    window.draw(ball);
}
