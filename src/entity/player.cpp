#define DEGREES_TO_RADIANS(x) (x * M_PI / 180.0)

#include <iostream>
#include <math.h>
#include "player.h"
#include "../const.h"


Player::Player() {

}

void Player::init() {
  body.setPosition(sf::Vector2f(400.f, 400.f));
  body.setSize(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));   
  body.setFillColor(sf::Color::Blue);
  body.setOutlineColor(sf::Color::Green);
  body.setOutlineThickness(1.f);
  body.setOrigin(PLAYER_X_CENTER, PLAYER_Y_CENTER);
  vel_x = 0;
  vel_y = 0;
  vel = 0;
  vel_rotation = 0;
}

void Player::move() {
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

  body.move(sf::Vector2f(vel * std::cos(DEGREES_TO_RADIANS(body.getRotation())), vel * std::sin(DEGREES_TO_RADIANS(body.getRotation()))));
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
