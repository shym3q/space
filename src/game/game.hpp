#ifndef GAME_HPP
#define GAME_HPP

#include "../entity/enemy/enemy.hpp"
#include "../lib/random.hpp"

class Game {
  sf::RenderWindow *window;
  sf::Event event;
  Player player;
  std::vector<Enemy> enemies;
  std::vector<Entity*> gameObjects;
  Random random;
  void initWindow();
public:
  Game();
  ~Game();
  const bool isRunning() const;
  void update();
  void render();
  void pollEvents();
};

#endif // !GAME_HPP
