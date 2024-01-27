#ifndef GAME_HPP
#define GAME_HPP

#include "../entity/player/player.hpp"
#include "../entity/enemy/enemy.hpp"
#include "../lib/random.hpp"

class Game {
  sf::RenderWindow *window;
  sf::Event event;
  Player player;
  std::vector<Enemy> enemies;
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
