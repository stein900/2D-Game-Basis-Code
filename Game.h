#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "ResourceManager.h"
#include "HUD.h"

class Game {
public:
    Game();
    ~Game();

    void run();  // Lancer la boucle principale du jeu

private:
    sf::RenderWindow window;
    sf::Clock clock;

    Player player;
    Level level;
    Enemy enemy;
    HUD hud;
    ResourceManager resourceManager;

    void handleInput();  // Gestion des entrées utilisateur
    void update(float deltaTime);  // Mise à jour des objets de jeu
    void render();  // Rendu graphique du jeu
};
