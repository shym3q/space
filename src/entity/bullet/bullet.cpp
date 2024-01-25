#define DEGREES_TO_RADIANS(x) (x * M_PI / 180.0)
#define X(a, b) (a * std::cos(DEGREES_TO_RADIANS(b)))
#define Y(a, b) (a * std::sin(DEGREES_TO_RADIANS(b)))

#include <math.h>
#include "bullet.hpp"
#include "../../const.hpp"

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

  if(body.getPosition().x < LEFT_LIMIT)
    body.move(sf::Vector2f(RIGHT_LIMIT+PLAYER_WIDTH, 0));
  if(body.getPosition().x > RIGHT_LIMIT)
    body.move(sf::Vector2f(-(RIGHT_LIMIT+PLAYER_WIDTH), 0));
  if(body.getPosition().y < UPPER_LIMIT)
    body.move(sf::Vector2f(0, LOWER_LIMIT+PLAYER_WIDTH));
  if(body.getPosition().y > LOWER_LIMIT)
    body.move(sf::Vector2f(0, -(LOWER_LIMIT+PLAYER_WIDTH)));
}
