#pragma once
#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy();
    ~Enemy();

    void update(float deltaTime); // Mise � jour de la position de l'ennemi
    void render(sf::RenderWindow& window); // Affiche l'ennemi � l'�cran
    void setPosition(const sf::Vector2f& position); // D�finit la position de d�part de l'ennemi
    void patrol(); // Comportement de patrouille

    sf::RectangleShape getSprite() const; // Retourne le sprite pour les collisions
    bool checkCollision(const sf::RectangleShape& player); // V�rifie la collision avec le joueur

private:
    sf::RectangleShape sprite; // Repr�sentation visuelle de l'ennemi
    sf::Vector2f position; // Position actuelle de l'ennemi
    sf::Vector2f velocity; // Vitesse de d�placement de l'ennemi
    bool isMovingLeft; // Direction actuelle de d�placement de l'ennemi
    float patrolDistance; // Distance maximale de patrouille
    sf::Vector2f startPosition; // Position de d�part de l'ennemi (pour la patrouille)

    void move(float deltaTime); // D�place l'ennemi selon sa direction
};
