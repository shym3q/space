#define RANDOM_COORDINATE(i) random.generateCoordinate(i)
#define RANDOM_VELOCITY random.generateVelocity()

#include "game.hpp"
#include "../entity/bullet/bullet.hpp"

void Game::initWindow() {
  window = new sf::RenderWindow{{WINDOW_WIDTH, WINDOW_HEIGHT}, GAME_NAME};
  window->setFramerateLimit(144);
  window->setKeyRepeatEnabled(false);
}

Game::Game() {
  initWindow();
  gameObjects.push_back(&player);
  for(auto i = 0; i < 3; i++)
    gameObjects.push_back(new Enemy(&player, RANDOM_COORDINATE(COORDINATE_X), RANDOM_COORDINATE(COORDINATE_Y), RANDOM_VELOCITY));
}

Game::~Game() {
  delete window;
  gameObjects.clear();
}

const bool Game::isRunning() const {
  return window->isOpen();
}

void Game::update() {
  pollEvents();
  spawnEnemies();
  for(auto object = gameObjects.begin(); object != gameObjects.end();) {
    if(!(*object)->isAlive) {
      object = gameObjects.erase(object);
      continue;
    }
    (*object)->update();
    ++object;
  }
  checkCollision();
}

void Game::render() {
  window->clear();
  for(auto& object : gameObjects)
    object->draw(window);
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
        else if(event.key.code == sf::Keyboard::J)
          gameObjects.push_back(new Bullet(player.body.getRotation(), player.body.getPosition(), &gameObjects));
        break;
      default:
        continue;
    }
  }
}

void Game::spawnEnemies() {
  if(timer.getElapsedTime().asSeconds() > 2.0) {
    gameObjects.push_back(new Enemy(&player, RANDOM_COORDINATE(COORDINATE_X), RANDOM_COORDINATE(COORDINATE_Y), RANDOM_VELOCITY));
    timer.restart();
  }
}

void Game::checkCollision() {
  auto bounds = player.body.getGlobalBounds();
  for (auto& obj : gameObjects) {
    if(bounds.intersects(obj->body.getGlobalBounds()) && obj->body.getPosition() != player.body.getPosition()) {
      obj->isAlive = false;
      if(--player.health == 0)
        player.isAlive = false;
      return;
    }
  }
}
