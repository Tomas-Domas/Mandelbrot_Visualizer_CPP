#include "MandelbrotRender.h"
#include <fstream>

MandelbrotRender::MandelbrotRender(Vector2u _size, long double _scale, ComplexNumber _origin)
:size(_size), scale(_scale), origin(_origin), rendered(false) {
    texture.create(size.x,size.y);
}

void MandelbrotRender::drawRender(sf::RenderWindow& window) {
    if(rendered){
        window.draw(sprite);
        return;
    }
    unsigned int len = size.x*size.y*4;
    Uint8* pixelArr = new Uint8[len];
    ComplexNumber point(origin.a-(size.x*.5*scale),origin.b-(size.y*.5*scale)-scale);
    Color color;
    for(unsigned int i=0; i<len; i+=4, point.a+=scale){
        if(i%(4*size.x)==0) {
            point.a = origin.a-(size.x*.5*scale);
            point.b += scale;
        }
//        color=Shader::linearShading(point.getNumEscapeSteps());
        color=Shader::logarithmicShading(point.getNumEscapeSteps());
        pixelArr[i]   = color.r;
        pixelArr[i+1] = color.g;
        pixelArr[i+2] = color.b;
        pixelArr[i+3] = 255;
    }
    texture.update(pixelArr);
    sprite.setTexture(texture);
//    window.draw(sprite);
    delete[] pixelArr;
    rendered=true;
}

void MandelbrotRender::saveImage() { //TODO: Finish putting the image in a file, and have a list or something
    unsigned int len = size.x*size.y*4;
    Uint8* pixelArr = new Uint8[len];
    ComplexNumber point(origin.a-(size.x*.5*scale),origin.b-(size.y*.5*scale)-scale);
    Color color;
    for(unsigned int i=0; i<len; i+=4, point.a+=scale){
        if(i%(4*size.x)==0) {
            point.a = origin.a-(size.x*.5*scale);
            point.b += scale;
        }
//        color=Shader::linearShading(point.getNumEscapeSteps());
        color=Shader::logarithmicShading(point.getNumEscapeSteps());
        pixelArr[i]  =color.r;
        pixelArr[i+1]=color.g;
        pixelArr[i+2]=color.b;
        pixelArr[i+3]=255;
    }
    sf::Image img;
    img.create(size.x,size.y,pixelArr);
    img.saveToFile("FIXME.png");//FIXME
    delete[] pixelArr;
}

void MandelbrotRender::zoom() {
    scale*=.4;
    rendered = false;
    ComplexNumber::MAX_ITERATIONS *= 1.2;
}

void MandelbrotRender::zoom(sf::RenderWindow& window) {
    sf::Vector2i mousePos(sf::Mouse::getPosition(window));
    origin.a+=(mousePos.x - size.y*.5)*scale;
    origin.b+=(mousePos.y - size.y*.5)*scale;

    zoom();
}
