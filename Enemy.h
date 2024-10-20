#pragma once
#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy();
    ~Enemy();

    void update(float deltaTime); // Mise à jour de la position de l'ennemi
    void render(sf::RenderWindow& window); // Affiche l'ennemi à l'écran
    void setPosition(const sf::Vector2f& position); // Définit la position de départ de l'ennemi
    void patrol(); // Comportement de patrouille

    sf::RectangleShape getSprite() const; // Retourne le sprite pour les collisions
    bool checkCollision(const sf::RectangleShape& player); // Vérifie la collision avec le joueur

private:
    sf::RectangleShape sprite; // Représentation visuelle de l'ennemi
    sf::Vector2f position; // Position actuelle de l'ennemi
    sf::Vector2f velocity; // Vitesse de déplacement de l'ennemi
    bool isMovingLeft; // Direction actuelle de déplacement de l'ennemi
    float patrolDistance; // Distance maximale de patrouille
    sf::Vector2f startPosition; // Position de départ de l'ennemi (pour la patrouille)

    void move(float deltaTime); // Déplace l'ennemi selon sa direction
};
