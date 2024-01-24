#ifndef GAME_HPP
#define GAME_HPP

#include "../entity/player.hpp"

class Game {
  sf::RenderWindow *window;
  sf::Event event;
  Player player;
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
