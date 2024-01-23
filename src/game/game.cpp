// #define WINDOW_WIDTH 1920u
// #define WINDOW_HEIGHT 1080u

#include "game.h"
#include "../const.h"

void Game::initWindow() {
  window = new sf::RenderWindow{{WINDOW_WIDTH, WINDOW_HEIGHT}, "Space"};
  window->setFramerateLimit(144);
}

Game::Game() {
  initWindow();
  player.init();
}

Game::~Game() {
  delete window;
}

const bool Game::isRunning() const {
  return window->isOpen();
}

void Game::update() {
  pollEvents();
  player.move();
}

void Game::render() {
  window->clear();
  window->draw(player.body);
  window->display();
}

void Game::pollEvents() {
  while(window->pollEvent(event)) {
    switch(event.type) {
      case sf::Event::Closed:
        window->close();
        break;
      case sf::Event::KeyPressed:
        if(event.key.code == sf::Keyboard::Escape)
          window->close();
        break;
      default:
        continue;
    }
  }
}
