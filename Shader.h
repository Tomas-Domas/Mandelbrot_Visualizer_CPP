#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

class Shader{
public:

    static sf::Color linearShading(short numSteps);
    static sf::Color logarithmicShading(short numSteps);

    static sf::Color HSVtoRGB(float H, float S, float V);

};