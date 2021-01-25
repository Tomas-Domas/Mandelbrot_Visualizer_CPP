//
// Created by Isaac Fuenmayor on 12/7/20.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
using std::unordered_map;
using std::string;

class TextureManager {
    static unordered_map<string,sf::Texture> textures;
    static string imageDir;
    static string imageExtension;
    static void LoadTexture(string fileName);
public:
    static void SetImageDirectory(const string& _imageDir);
    static void SetImageExtension(const string& _imageExtension);
    static sf::Texture& GetTexture(string textureName);
    static void Clear(); //Call this once, at the end of main()
};
