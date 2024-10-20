#include "Player.h"
#include "Physics.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player()
    : speed(200.0f), jumpHeight(400.0f), isJumping(false), score(0), lives(3) {
    // Initialisation du sprite du joueur
    sprite.setSize(sf::Vector2f(50.0f, 100.0f));  // Taille du joueur
    sprite.setFillColor(sf::Color::Green);  // Couleur verte pour le joueur
    position = sf::Vector2f(100.0f, 300.0f);  // Position initiale
    velocity = sf::Vector2f(0.0f, 0.0f);  // Vitesse initiale
    sprite.setPosition(position);
}

Player::~Player() {
    // Destruction si n�cessaire
}

void Player::handleInput() {
    // R�initialiser la vitesse horizontale
    velocity.x = 0;

    // Mouvement � gauche
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity.x = -speed;
    }

    // Mouvement � droite
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity.x = speed;
    }

    // Sauter si le joueur n'est pas d�j� en train de sauter
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping) {
        jump();
    }
}

void Player::jump() {
    velocity.y = -jumpHeight;  // Appliquer une vitesse vers le haut
    isJumping = true;  // Le joueur est en train de sauter
}

void Player::update(float deltaTime, const std::vector<sf::RectangleShape>& platforms) {
    // Appliquer la gravit�
    Physics::applyGravity(velocity, deltaTime);

    // Mise � jour de la position en fonction de la vitesse
    position += velocity * deltaTime;
    sprite.setPosition(position);

    bool isOnPlatform = false;

    // V�rification des collisions avec les plateformes
    for (const auto& platform : platforms) {
        if (Physics::checkCollision(sprite, platform)) {
            Physics::resolveCollision(sprite, platform);
            velocity.y = 0;  // Arr�te la chute lorsque le joueur touche une plateforme
            isOnPlatform = true;
            isJumping = false;  // Le joueur n'est plus en train de sauter
        }
    }

    // Si le joueur est sur une plateforme ou le sol, il peut sauter � nouveau
    if (!isOnPlatform && position.y >= 500.0f) {  // Position o� le sol serait
        position.y = 500.0f;  // Bloque le joueur au niveau du sol
        velocity.y = 0;  // Arr�te la chute
        isJumping = false;  // Le joueur peut sauter � nouveau
    }
}

void Player::render(sf::RenderWindow& window) {
    window.draw(sprite);  // Dessiner le joueur � l'�cran
}

sf::RectangleShape Player::getSprite() const {
    return sprite;
}

int Player::getScore() const {
    return score;
}

int Player::getLives() const {
    return lives;
}
