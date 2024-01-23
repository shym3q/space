#include "../entity/player.h"

#ifndef GAME_H
#define GAME_H

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

#endif // !GAME_H
