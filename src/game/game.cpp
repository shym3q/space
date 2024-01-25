#include "game.hpp"
#include "../const.hpp"

void Game::initWindow() {
  window = new sf::RenderWindow{{WINDOW_WIDTH, WINDOW_HEIGHT}, GAME_NAME};
  window->setFramerateLimit(144);
}

Game::Game() {
  initWindow();
}

Game::~Game() {
  delete window;
}

const bool Game::isRunning() const {
  return window->isOpen();
}

void Game::update() {
  pollEvents();
  player.update();
  if(enemies.size() != 2)
    enemies.emplace_back(&player);
  for(auto it = player.bullets.begin(); it != player.bullets.end();) {
    if(!it->isAlive) {
      it = player.bullets.erase(it);
      continue;
    }
    it->update();
    ++it;
  }
  for(auto& enemy : enemies)
    enemy.update();
}

void Game::render() {
  window->clear();
  window->draw(player.body);
  for(auto& enemy : enemies)
    window->draw(enemy.body);
  for(auto& bullet : player.bullets)
    window->draw(bullet.body);
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
