#include "bullet.hpp"

Bullet::Bullet(float deg, sf::Vector2f pos, std::vector<Entity*>* obj) : objects(obj) {
  velocity = BULLET_SPEED;
  body.setSize(sf::Vector2f(BULLET_WIDTH, BULLET_HEIGHT));
  body.setFillColor(sf::Color::Yellow);
  body.setOrigin(sf::Vector2f(BULLET_X_CENTER, BULLET_Y_CENTER));
  body.setRotation(deg);
  body.setPosition(pos.x + X(CHARACTER_WIDTH, deg), pos.y + Y(CHARACTER_WIDTH, deg));
}

void Bullet::update() {
  if(timer.getElapsedTime().asSeconds() > BULLET_LIFETIME) {
    isAlive = false;
    return;
  }

  auto bounds = body.getGlobalBounds();
  for (auto& obj : *objects) {
    if(bounds.intersects(obj->body.getGlobalBounds()) && obj->collision()) {
      isAlive = false;
      return;
    }
  }

  int degree = body.getRotation();
  body.move(sf::Vector2f(X(velocity, degree), Y(velocity, degree)));
  edgeCheck();
}

const bool Bullet::collision() const {
  return false;
}
