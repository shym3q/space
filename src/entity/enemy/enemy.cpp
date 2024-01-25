#define DEGREES_TO_RADIANS(x) (x * M_PI / 180.0)
#define X(a, b) (a * std::cos(DEGREES_TO_RADIANS(b)))
#define Y(a, b) (a * std::sin(DEGREES_TO_RADIANS(b)))

#include <math.h>
#include "enemy.hpp"
#include "../../const.hpp"

Enemy::Enemy() {
  body.setSize(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));   
  body.setFillColor(sf::Color::Red);
  body.setOutlineColor(sf::Color::Green);
  body.setOutlineThickness(1.f);
  body.setOrigin(PLAYER_X_CENTER, PLAYER_Y_CENTER);
  body.setPosition(sf::Vector2f(400, 400));
  vel = MAX_SPEED;
}

void Enemy::update() {
  int degree = body.getRotation();
  body.move(sf::Vector2f(X(vel, degree), Y(vel, degree)));
  body.rotate(vel_rotation);

  if(body.getPosition().x < LEFT_LIMIT)
    body.move(sf::Vector2f(RIGHT_LIMIT+PLAYER_WIDTH, 0));
  if(body.getPosition().x > RIGHT_LIMIT)
    body.move(sf::Vector2f(-(RIGHT_LIMIT+PLAYER_WIDTH), 0));
  if(body.getPosition().y < UPPER_LIMIT)
    body.move(sf::Vector2f(0, LOWER_LIMIT+PLAYER_WIDTH));
  if(body.getPosition().y > LOWER_LIMIT)
    body.move(sf::Vector2f(0, -(LOWER_LIMIT+PLAYER_WIDTH)));
}
