#include <SFML/Graphics.hpp>
#include <cmath>
#include "MandelbrotRender.h"

int main()
{
    const unsigned int len = 512;
    sf::Uint8* pixels = new sf::Uint8[len*len*4];

    sf::RenderWindow window(sf::VideoMode(512,512),"tutorial", sf::Style::Close);
    MandelbrotRender mandel(window.getSize(), 0.005, ComplexNumber(-0.25,0));

    while(window.isOpen()){
//        window.clear(sf::Color::Black);
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    mandel.drawRender(window);
                    break;
            }
        }

//        sf::Texture texture;
//        texture.create(len, len);
//        for(unsigned int i=0; i<len*len*4; i++){
//            pixels[i] = 50;
//        }
//        texture.update(pixels);
//        sf::Sprite sprite;
//        sprite.setTexture(texture);
//        window.draw(sprite);

//        sf::Vector2<int> mouse = sf::Mouse::getPosition(window);
//        sf::CircleShape shape(event.type);
//        float r = sqrt((mouse.x-(window.getSize().x*0.5))*(mouse.x-(window.getSize().x*0.5)) + (mouse.y-(window.getSize().y*0.5))*(mouse.y-(window.getSize().y*0.5)));
//        shape.setRadius(r);
//        shape.setOrigin(shape.getRadius() - window.getSize().x*0.5, shape.getRadius() - window.getSize().y*0.5);
//        shape.setFillColor(Shader::linearShading(r));
//        window.draw(shape);

        window.display();
    }

    return 0;
}