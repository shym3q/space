#include <cmath>
#include <iostream>
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
    vel -= 0.05;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && vel < MAX_SPEED) {
    vel += 0.1;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && vel_rotation > -MAX_ROTATION_SPEED) {
    vel_rotation -= 0.1;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && vel_rotation < MAX_ROTATION_SPEED) {
    vel_rotation += 0.1;
  }
    // body.rotate(1);
    // vel_x += 0.1;
  // std::cout<<body.getRotation()<<std::endl;

  body.move(sf::Vector2f(vel * std::cos(body.getRotation() * 3.141592 / 180), vel * std::sin(body.getRotation() * 3.141592 / 180)));
  body.rotate(vel_rotation);
}
