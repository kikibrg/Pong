#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Paddle
{
    private:
        float spawnX;
        float spawnY;
    public:
        RectangleShape paddle;
        Paddle(int x, int y, int width, int height);
        void movePaddle(int direction);
        void drawPaddle(RenderWindow& window);
};

#endif
