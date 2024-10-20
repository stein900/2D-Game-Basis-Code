#pragma once
#include <SFML/Graphics.hpp>

class Physics {
public:
    static void applyGravity(sf::Vector2f& velocity, float deltaTime);  // Applique la gravit� au joueur
    static bool checkCollision(const sf::RectangleShape& player, const sf::RectangleShape& platform);  // V�rifie la collision entre le joueur et une plateforme
    static void resolveCollision(sf::RectangleShape& player, const sf::RectangleShape& platform);  // R�sout la collision pour ajuster la position du joueur
};
