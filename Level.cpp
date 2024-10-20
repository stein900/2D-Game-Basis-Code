#include "Level.h"
#include <fstream>
#include <sstream>
#include <iostream>

Level::Level() {
    // Initialisation de la texture de fond (optionnel)
    if (!backgroundTexture.loadFromFile("background.png")) {
        std::cerr << "Erreur lors du chargement de la texture de fond\n";
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setOrigin(0, 100);
}

Level::~Level() {
    // Destruction des objets si nécessaire
}

void Level::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier de niveau: " << filename << std::endl;
        return;
    }

    std::string line;
    int row = 0;
    const int tileSize = 50; // Taille d'une "tuile" (plateforme)

    // Lecture ligne par ligne du fichier de niveau
    while (std::getline(file, line)) {
        for (int col = 0; col < line.length(); ++col) {
            if (line[col] == '1') { // '1' représente une plateforme dans le fichier texte
                sf::RectangleShape platform;
                platform.setSize(sf::Vector2f(tileSize, tileSize));
                platform.setPosition(col * tileSize, row * tileSize);
                platform.setFillColor(sf::Color::Blue); // Couleur des plateformes (modifiable)
                platforms.push_back(platform);
            }
        }
        ++row;
    }

    file.close();
}

void Level::render(sf::RenderWindow& window) {
    // Rendu du fond du niveau
    window.draw(backgroundSprite);

    // Rendu des plateformes
    for (const auto& platform : platforms) {
        window.draw(platform);
    }
}

const std::vector<sf::RectangleShape>& Level::getPlatforms() const {
    return platforms;
}
