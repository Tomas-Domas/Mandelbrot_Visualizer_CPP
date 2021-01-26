#include <SFML/Graphics.hpp>
#include <cmath>
#include "MandelbrotRender.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;
    sf::RenderWindow window(sf::VideoMode(1024,1024),
                            "tutorial", sf::Style::Close, settings);
//    MandelbrotRender mandel(window.getSize(), 0.1, );
    while(window.isOpen()){
        window.clear();
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        sf::Vector2<int> mouse = sf::Mouse::getPosition(window);


        sf::CircleShape shape(event.type);
        float r = sqrt((mouse.x-(window.getSize().x*0.5))*(mouse.x-(window.getSize().x*0.5)) + (mouse.y-(window.getSize().y*0.5))*(mouse.y-(window.getSize().y*0.5)));
        shape.setRadius(r);
        shape.setOrigin(shape.getRadius() - window.getSize().x*0.5, shape.getRadius() - window.getSize().y*0.5);
        shape.setFillColor(Shader::linearShading(r));
        window.draw(shape);
//        mandel.drawRender(window);
        window.display();
    }

    return 0;
}