#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Player {
public:
    Player();
    ~Player();

    void handleInput();  // G�rer les entr�es du joueur (mouvement, saut)
    void update(float deltaTime, const std::vector<sf::RectangleShape>& platforms);  // Met � jour la position et la gestion des collisions
    void render(sf::RenderWindow& window);  // Affiche le joueur � l'�cran

    sf::RectangleShape getSprite() const;  // Retourne le sprite pour les collisions
    int getScore() const;  // Retourne le score du joueur
    int getLives() const;  // Retourne le nombre de vies restantes

private:
    sf::RectangleShape sprite;  // Repr�sentation visuelle du joueur
    sf::Vector2f position;  // Position actuelle du joueur
    sf::Vector2f velocity;  // Vitesse du joueur (affect�e par les mouvements et la gravit�)

    float speed;  // Vitesse de d�placement horizontal
    float jumpHeight;  // Hauteur de saut
    bool isJumping;  // Indique si le joueur est en train de sauter

    int score;  // Score du joueur
    int lives;  // Vies restantes

    void jump();  // Fait sauter le joueur
};
