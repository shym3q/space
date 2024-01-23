#include "player.h"
#include <SFML/System/Vector2.hpp>

Player::Player() {

}

void Player::init() {
  body.setPosition(sf::Vector2f(200.f, 200.f));
  body.setSize(sf::Vector2f(100.f, 100.f));   
  body.setFillColor(sf::Color::Blue);
  body.setOutlineColor(sf::Color::Green);
  body.setOutlineThickness(1.f);
}

void Player::move() {
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    body.move(sf::Vector2f(0, -4.f));
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    body.move(sf::Vector2f(0, 4.f));
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    body.move(sf::Vector2f(-4.f, 0));
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    body.move(sf::Vector2f(4.f, 0));
}
