#include "TextureManager.h"

string TextureManager::imageDir="images/";
string TextureManager::imageExtension=".png";
unordered_map<string, sf::Texture> TextureManager::textures;

void TextureManager::LoadTexture(string fileName) {
    textures[fileName].loadFromFile(imageDir+fileName+imageExtension);
}

sf::Texture &TextureManager::GetTexture(string textureName) {
    if(textures.find(textureName)==textures.end())
        LoadTexture(textureName);
    return textures[textureName];
}

void TextureManager::SetImageDirectory(const string& _imageDir) {
    imageDir=_imageDir;
}

void TextureManager::SetImageExtension(const string& _imageExtension) {
    imageExtension=_imageExtension;
}
void TextureManager::Clear() {
    textures.clear();
}
