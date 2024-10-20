#include "ResourceManager.h"
#include <iostream>

ResourceManager::ResourceManager() {
    // Constructeur
}

ResourceManager::~ResourceManager() {
    // Destructeur - Les ressources seront automatiquement libérées
}

sf::Texture& ResourceManager::getTexture(const std::string& filename) {
    // Si la texture est déjà chargée, on la retourne
    if (textures.find(filename) != textures.end()) {
        return textures[filename];
    }

    // Sinon, on charge la texture et on la stocke dans le cache
    sf::Texture texture;
    if (!texture.loadFromFile(filename)) {
        std::cerr << "Erreur: impossible de charger la texture " << filename << std::endl;
    }

    textures[filename] = texture;
    return textures[filename];
}

sf::Font& ResourceManager::getFont(const std::string& filename) {
    // Si la police est déjà chargée, on la retourne
    if (fonts.find(filename) != fonts.end()) {
        return fonts[filename];
    }

    // Sinon, on charge la police et on la stocke dans le cache
    sf::Font font;
    if (!font.loadFromFile(filename)) {
        std::cerr << "Erreur: impossible de charger la police " << filename << std::endl;
    }

    fonts[filename] = font;
    return fonts[filename];
}

sf::SoundBuffer& ResourceManager::getSoundBuffer(const std::string& filename) {
    // Si le son est déjà chargé, on le retourne
    if (sounds.find(filename) != sounds.end()) {
        return sounds[filename];
    }

    // Sinon, on charge le son et on le stocke dans le cache
    sf::SoundBuffer soundBuffer;
    if (!soundBuffer.loadFromFile(filename)) {
        std::cerr << "Erreur: impossible de charger le son " << filename << std::endl;
    }

    sounds[filename] = soundBuffer;
    return sounds[filename];
}
