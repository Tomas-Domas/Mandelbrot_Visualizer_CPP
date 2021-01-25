#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

class Shader{
public:

    static sf::Color linearShading(short numSteps){
        if (numSteps != -1)
            return sf::Color(sf::Color::Black);
        return sf::Color((numSteps*20)%255,0,0);
    }

    static sf::Color RGB(unsigned short h, float s, float v) {
        float c = v*s;
        float x = c * (1 - abs((h/60)%2 - 1));
        float m = v-c;

        std::vector<int> rgb(3);

        switch()
        rgb = {0,0,0};
    }

};