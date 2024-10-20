#include "Game.h"
#include <iostream>

Game::Game()
    : window(sf::VideoMode(800, 600), "Platformer Game") {
    // Initialisation des ressources (textures, polices, etc.)
    sf::Font& gameFont = resourceManager.getFont("arial.ttf");

    // Initialisation des éléments du jeu
    player = Player();
    enemy = Enemy();
    enemy.setPosition(sf::Vector2f(400.0f, 300.0f));  // Placer l'ennemi quelque part dans le niveau

    level.loadFromFile("level.txt");  // Charger un niveau depuis un fichier

    hud.setFont(gameFont);  // Charger la police dans le HUD
}

Game::~Game() {
    // Destruction et nettoyage si nécessaire
}

void Game::run() {
    // Boucle principale du jeu
    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        handleInput();  // Gestion des entrées utilisateur
        update(deltaTime.asSeconds());  // Mise à jour des objets de jeu
        render();  // Rendu du jeu
    }
}

void Game::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();  // Fermer la fenêtre si l'événement "Closed" est reçu
        }
    }

    player.handleInput();  // Gérer les mouvements et les actions du joueur
}

void Game::update(float deltaTime) {
    // Mise à jour des objets de jeu
    player.update(deltaTime, level.getPlatforms());  // Mise à jour du joueur avec gestion des collisions
    enemy.update(deltaTime);  // Mise à jour de l'ennemi

    // Vérification des collisions entre le joueur et l'ennemi
    if (enemy.checkCollision(player.getSprite())) {
        std::cout << "Collision avec l'ennemi !" << std::endl;
        // Gestion des effets de la collision (par exemple, réduire les vies)
        // Ici, par exemple, on peut enlever une vie
        player.getLives() > 0 ? player.getLives() - 1 : 0;
    }

    hud.update(player.getScore(), player.getLives());  // Mise à jour du HUD (score et vies)
}

void Game::render() {
    window.clear();

    // Afficher les différents éléments du jeu
    level.render(window);  // Affichage du niveau
    player.render(window);  // Affichage du joueur
    enemy.render(window);  // Affichage de l'ennemi
    hud.render(window);  // Affichage du HUD

    window.display();  // Affichage final à l'écran
}
