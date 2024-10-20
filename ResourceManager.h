#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>

class ResourceManager {
public:
    ResourceManager();
    ~ResourceManager();

    sf::Texture& getTexture(const std::string& filename);  // Charger ou obtenir une texture
    sf::Font& getFont(const std::string& filename);        // Charger ou obtenir une police
    sf::SoundBuffer& getSoundBuffer(const std::string& filename); // Charger ou obtenir un son

private:
    std::map<std::string, sf::Texture> textures;   // Cache pour les textures
    std::map<std::string, sf::Font> fonts;         // Cache pour les polices
    std::map<std::string, sf::SoundBuffer> sounds; // Cache pour les sons
};
