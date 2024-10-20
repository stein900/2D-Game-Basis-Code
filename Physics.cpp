#include "Physics.h"

const float GRAVITY = 980.0f; // Constante pour la gravit� (pixels par seconde^2)

void Physics::applyGravity(sf::Vector2f& velocity, float deltaTime) {
    // Appliquer la gravit� � la vitesse verticale du joueur
    velocity.y += GRAVITY * deltaTime;
}

bool Physics::checkCollision(const sf::RectangleShape& player, const sf::RectangleShape& platform) {
    // V�rifier si les bounding boxes du joueur et de la plateforme se chevauchent
    return player.getGlobalBounds().intersects(platform.getGlobalBounds());
}

void Physics::resolveCollision(sf::RectangleShape& player, const sf::RectangleShape& platform) {
    // R�cup�rer les bounding boxes du joueur et de la plateforme
    sf::FloatRect playerBounds = player.getGlobalBounds();
    sf::FloatRect platformBounds = platform.getGlobalBounds();

    // Calculer les positions relatives des objets
    float playerBottom = playerBounds.top + playerBounds.height;
    float platformTop = platformBounds.top;

    // Si le joueur tombe sur la plateforme
    if (playerBottom > platformTop && playerBounds.top < platformTop) {
        player.setPosition(playerBounds.left, platformTop - playerBounds.height);  // Ajuste la position pour �viter que le joueur ne traverse la plateforme
    }
}
