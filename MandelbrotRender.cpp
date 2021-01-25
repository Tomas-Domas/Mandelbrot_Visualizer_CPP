//
// Created by Isaac Fuenmayor on 1/25/21.
//
#include "MandelbrotRender.h"

MandelbrotRender::MandelbrotRender(Vector2u _size, long double _scale, ComplexNumber _origin)
:size(_size), scale(_scale), origin(_origin),texture(),sprite(texture) {}

void MandelbrotRender::drawRender(sf::RenderWindow& window) {
    unsigned int len = size.x*size.y*4;
    Uint8* pixelArr = new Uint8[len];
    ComplexNumber point(origin.a-(size.x*scale),origin.b-(size.y*scale)-scale);
    Color color;
    for(unsigned int i=0; i<len; i+=4, point.a+=scale){
        if(i%(4*size.x)==0)
            point.b+=scale;
        color=Shader::linearShading(point.getNumEscapeSteps());
        pixelArr[i]  =color.r;
        pixelArr[i+1]=color.g;
        pixelArr[i+2]=color.b;
        pixelArr[i+3]=color.a;
    }
    texture.update(pixelArr);
    window.draw(sprite);
    delete[] pixelArr;
}
