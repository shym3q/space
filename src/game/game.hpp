#ifndef GAME_HPP
#define GAME_HPP

#include "../entity/player/player.hpp"
#include "../entity/enemy/enemy.hpp"

class Game {
  sf::RenderWindow *window;
  sf::Event event;
  Player player;
  Enemy enemy;
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
