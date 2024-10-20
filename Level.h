#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Level {
public:
    Level();
    ~Level();

    void loadFromFile(const std::string& filename); // Charge le niveau depuis un fichier
    void render(sf::RenderWindow& window); // Affiche le niveau à l'écran

    const std::vector<sf::RectangleShape>& getPlatforms() const; // Retourne les plateformes pour les collisions

private:
    std::vector<sf::RectangleShape> platforms; // Liste des plateformes du niveau
    sf::Texture backgroundTexture; // Texture du fond du niveau
    sf::Sprite backgroundSprite; // Sprite pour afficher le fond du niveau
};
