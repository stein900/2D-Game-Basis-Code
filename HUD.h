#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class HUD {
public:
    HUD();
    ~HUD();

    void setFont(const sf::Font& font); // Définir la police d'écriture pour le HUD
    void update(int score, int lives);  // Mettre à jour le score et les vies
    void render(sf::RenderWindow& window); // Afficher le HUD

private:
    sf::Text scoreText;  // Texte pour afficher le score
    sf::Text livesText;  // Texte pour afficher les vies restantes

    int currentScore;    // Score actuel du joueur
    int currentLives;    // Vies restantes
};
