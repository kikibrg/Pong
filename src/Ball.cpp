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

void Ball::resetBall()
{
    ball.setPosition(sf::Vector2f(spawnX, spawnY));
    velocity = sf::Vector2f(4.0f, 2.0f);
    speed = 1.0f;
}

void Ball::collisionHandle(Paddle& paddle1, Paddle& paddle2)
{
    if (ball.getPosition().y + ball.getRadius() >= 600 || ball.getPosition().y + ball.getRadius() <= 0)
    {
        velocity.y = -velocity.y;
        speed += 0.03f;
    }

    if (ball.getGlobalBounds().intersects(paddle1.paddle.getGlobalBounds()) || ball.getGlobalBounds().intersects(paddle2.paddle.getGlobalBounds()))
    {
        velocity.x = -velocity.x;
        speed += 0.03f;
    }

    if (ball.getPosition().x + ball.getRadius() > 800)
    {
        resetBall();
    }
    else if (ball.getPosition().x + ball.getRadius() < 0)
    {
        resetBall();
    }
}
