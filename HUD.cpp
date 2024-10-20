#include "HUD.h"
#include <sstream>

HUD::HUD() : currentScore(0), currentLives(3) {
    // Initialisation des textes (les polices seront assignées ultérieurement)
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10.0f, 10.0f); // Position en haut à gauche de l'écran

    livesText.setCharacterSize(24);
    livesText.setFillColor(sf::Color::White);
    livesText.setPosition(10.0f, 50.0f); // Position en dessous du score
}

HUD::~HUD() {
    // Destruction des éléments si nécessaire
}

void HUD::setFont(const sf::Font& font) {
    // Assigner la police aux textes
    scoreText.setFont(font);
    livesText.setFont(font);
}

void HUD::update(int score, int lives) {
    // Mettre à jour les valeurs du score et des vies
    currentScore = score;
    currentLives = lives;

    // Conversion des valeurs en texte affichable
    std::stringstream ss;
    ss << "Score: " << currentScore;
    scoreText.setString(ss.str());

    ss.str(""); // Réinitialiser le flux
    ss << "Lives: " << currentLives;
    livesText.setString(ss.str());
}

void HUD::render(sf::RenderWindow& window) {
    // Afficher le texte à l'écran
    window.draw(scoreText);
    window.draw(livesText);
}
