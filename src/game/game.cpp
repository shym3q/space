#include "game.h"

void Game::initWindow() {
  window = new sf::RenderWindow{ {1920u, 1080u }, "Space" };
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
