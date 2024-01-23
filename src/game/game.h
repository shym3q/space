#include "../char/player.cpp"

#ifndef GAME_H
#define GAME_H

class Game {
  sf::RenderWindow *window;
  sf::Event event;
  Player p;
  void initWindow();
public:
  Game();
  ~Game();
  void update();
  void render();
};

#endif // !GAME_H
