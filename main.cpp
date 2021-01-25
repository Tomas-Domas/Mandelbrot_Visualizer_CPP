#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;
    sf::RenderWindow window(sf::VideoMode(512,512), "tutorial", sf::Style::Close, settings);

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
        shape.setRadius(sqrt((mouse.x-(window.getSize().x*0.5))*(mouse.x-(window.getSize().x*0.5)) + (mouse.y-(window.getSize().y*0.5))*(mouse.y-(window.getSize().y*0.5))));
        shape.setFillColor(sf::Color(100, 250, 50));
        shape.setOrigin(shape.getRadius() - window.getSize().x*0.5, shape.getRadius() - window.getSize().y*0.5);

        window.draw(shape);
        window.display();

    }


    return 0;
}