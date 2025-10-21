#include <iostream>
#include "Paddle.hpp"

Paddle::Paddle(int x, int y, int width, int height)
{
    spawnX = x;
    spawnY = y;
    
    paddle.setSize(sf::Vector2f(width, height));
    paddle.setPosition(x, y);
}

void Paddle::movePaddle(int direction)
{
    float move_speed = direction == 1 ? 5.0f : -5.0f;

    if (paddle.getPosition().y + move_speed >= 0 && paddle.getPosition().y + move_speed <= 530)
    {
        paddle.setPosition(paddle.getPosition().x, paddle.getPosition().y + move_speed);
    }
}


void Paddle::drawPaddle(sf::RenderWindow& window)
{
    window.draw(paddle);
}
