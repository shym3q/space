#include <SFML/Graphics.hpp>
#include "game.h"

void Game::initWindow() {
  window = new sf::RenderWindow{ {1920u, 1080u }, "Space" };
  window->setFramerateLimit(144);
}

Game::Game() {
  initWindow();

  while(window->isOpen()) {
    update();
    render();
  }
}

Game::~Game() {
  delete window;
}

void Game::update() {
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

void Game::render() {
  window->clear();
  window->display();
}
