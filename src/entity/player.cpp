#define DEGREES_TO_RADIANS(x) (x * M_PI / 180.0)
#define X(a, b) (a * std::cos(DEGREES_TO_RADIANS(b)))
#define Y(a, b) (a * std::sin(DEGREES_TO_RADIANS(b)))

#include <math.h>
#include "player.hpp"
#include "bullet.hpp"
#include "../const.hpp"


Player::Player() {
  body.setPosition(sf::Vector2f(400.f, 400.f));
  body.setSize(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));   
  body.setFillColor(sf::Color::Blue);
  body.setOutlineColor(sf::Color::Green);
  body.setOutlineThickness(1.f);
  body.setOrigin(PLAYER_X_CENTER, PLAYER_Y_CENTER);
}

void Player::update() {
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && vel > -MAX_SPEED) {
    vel -= 0.03;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && vel < MAX_SPEED) {
    vel += 0.05;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && vel_rotation > -MAX_ROTATION_SPEED) {
    vel_rotation -= 0.1;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && vel_rotation < MAX_ROTATION_SPEED) {
    vel_rotation += 0.1;
  }

  if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    shot = false;

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !shot) {
    bullets.emplace_back(body.getRotation(), body.getPosition());
    shot = true;
  }

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
