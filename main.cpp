#include <SFML/Graphics.hpp>
#include <cmath>
#include "MandelbrotRender.h"

int main()
{
    const unsigned int len = 512;
    sf::Uint8* pixels = new sf::Uint8[len*len*4];

    sf::RenderWindow window(sf::VideoMode(1000,1000),"tutorial", sf::Style::Close);
    MandelbrotRender mandel(window.getSize(), 0.01, ComplexNumber(-0.5,0));

    while(window.isOpen()){
//        window.clear(sf::Color::Black);
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    mandel.zoom(window);
                    break;
                case sf::Event::KeyPressed:
                    mandel.saveImage();
                    break;
            }
        }

        mandel.drawRender(window);

        window.display();
    }

    return 0;
}