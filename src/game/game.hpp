#ifndef GAME_HPP
#define GAME_HPP

#include "../entity/enemy/enemy.hpp"
#include "../lib/random.hpp"

class Game {
  sf::RenderWindow *window;
  sf::Event event;
  Player player;
  std::vector<Entity*> gameObjects;
  sf::Clock timer;
  Random random;
  void initWindow();
  void spawnEnemies();
  void checkCollision(); 
public:
  Game();
  ~Game();
  const bool isRunning() const;
  void update();
  void render();
  void pollEvents();
};

#endif // !GAME_HPP
