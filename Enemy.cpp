#include "Enemy.h"

Enemy::Enemy()
    : isMovingLeft(true), patrolDistance(100.0f), velocity(100.0f, 0.0f) {
    // Initialisation du sprite de l'ennemi
    sprite.setSize(sf::Vector2f(50.0f, 50.0f)); // Taille de l'ennemi
    sprite.setFillColor(sf::Color::Red); // Couleur de l'ennemi
}

Enemy::~Enemy() {
    // Destruction si nécessaire
}

void Enemy::setPosition(const sf::Vector2f& pos) {
    position = pos;
    startPosition = pos;
    sprite.setPosition(position);
}

void Enemy::update(float deltaTime) {
    // Faire patrouiller l'ennemi
    patrol();
    move(deltaTime);
    sprite.setPosition(position);
}

void Enemy::patrol() {
    // Si l'ennemi a atteint la distance maximale de patrouille, il change de direction
    if (isMovingLeft && position.x <= startPosition.x - patrolDistance) {
        isMovingLeft = false;
    }
    else if (!isMovingLeft && position.x >= startPosition.x + patrolDistance) {
        isMovingLeft = true;
    }

    // Définir la direction de la vitesse en fonction de la direction
    velocity.x = isMovingLeft ? -100.0f : 100.0f;
}

void Enemy::move(float deltaTime) {
    // Mettre à jour la position en fonction de la vitesse
    position += velocity * deltaTime;
}

void Enemy::render(sf::RenderWindow& window) {
    // Affichage de l'ennemi à l'écran
    window.draw(sprite);
}

sf::RectangleShape Enemy::getSprite() const {
    return sprite;
}

bool Enemy::checkCollision(const sf::RectangleShape& player) {
    // Vérifie si l'ennemi entre en collision avec le joueur
    return sprite.getGlobalBounds().intersects(player.getGlobalBounds());
}
