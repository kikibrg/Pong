#include <iostream>
#include <SFML/Graphics.hpp>
#include "Paddle.hpp"

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Pong");
    window.setFramerateLimit(60);

    Paddle paddle1(40, 265, 15, 70);
    Paddle paddle2(745, 265, 15, 70);

    while(window.isOpen() && !Keyboard::isKeyPressed(Keyboard::Escape)) {

        Event event;
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed)
                window.close();
        }

        if(Keyboard::isKeyPressed(Keyboard::Z))
            paddle1.movePaddle(-1);
        if(Keyboard::isKeyPressed(Keyboard::S))
            paddle1.movePaddle(1);
        if(Keyboard::isKeyPressed(Keyboard::Up))
            paddle2.movePaddle(-1);
        if(Keyboard::isKeyPressed(Keyboard::Down))
            paddle2.movePaddle(1);

        window.clear();
        
        paddle1.drawPaddle(window);
        paddle2.drawPaddle(window);
        
        window.display();
    }
    return 0;
}
