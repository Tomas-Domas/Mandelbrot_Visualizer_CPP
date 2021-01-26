#pragma once
#include <SFML/Graphics.hpp>
#include "ComplexNumber.h"
#include "Shader.h"
using sf::Texture;
using sf::Sprite;
using sf::Vector2u;
using sf::Uint8;
using sf::Color;

class MandelbrotRender {
    Vector2u size;
    long double scale;    ///units per pixel
    ComplexNumber origin;
    Texture texture;
    Sprite sprite;
    bool rendered;
public:
    MandelbrotRender(Vector2u _size, long double _scale=.001, ComplexNumber _origin={0,0});
    void drawRender(sf::RenderWindow& window);
    //TODO:
//    void zoom(double factor);
    void saveImage();
};