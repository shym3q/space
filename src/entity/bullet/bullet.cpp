#include "bullet.hpp"

Bullet::Bullet(float deg, sf::Vector2f pos) {
  vel = BULLET_SPEED;
  body.setSize(sf::Vector2f(BULLET_WIDTH, BULLET_HEIGHT));
  body.setFillColor(sf::Color::Yellow);
  body.setOrigin(sf::Vector2f(BULLET_X_CENTER, BULLET_Y_CENTER));
  body.setRotation(deg);
  body.setPosition(pos);
}

void Bullet::update() {
  if(timer.getElapsedTime().asSeconds() > BULLET_LIFETIME)
    isAlive = false;
  int degree = body.getRotation();
  body.move(sf::Vector2f(X(vel, degree), Y(vel, degree)));
  
  edge_check();
}
