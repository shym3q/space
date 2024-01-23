#include "player.h"
#include "../const.h"

Player::Player() {

}

void Player::init() {
  body.setPosition(sf::Vector2f(400.f, 400.f));
  body.setSize(sf::Vector2f(50.f, 50.f));   
  body.setFillColor(sf::Color::Blue);
  body.setOutlineColor(sf::Color::Green);
  body.setOutlineThickness(1.f);
  vel_x = 0;
  vel_y = 0;
}

void Player::move() {
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && vel_y > -MAX_SPEED)
    vel_y -= 0.1;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && vel_y < MAX_SPEED)
    vel_y += 0.1;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && vel_x > -MAX_SPEED)
    vel_x -= 0.1;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && vel_x < MAX_SPEED)
    vel_x += 0.1;

  body.move(sf::Vector2f(vel_x, vel_y));
}
