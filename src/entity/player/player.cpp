#include "player.hpp"

Player::Player() {
  body.setPosition(sf::Vector2f(800.f, 800.f));
  body.setSize(sf::Vector2f(CHARACTER_WIDTH, CHARACTER_HEIGHT));   
  body.setFillColor(sf::Color::Blue);
  body.setOutlineColor(sf::Color::Green);
  body.setOutlineThickness(1.f);
  body.setOrigin(CHARACTER_X_CENTER, CHARACTER_Y_CENTER);
}

void Player::update() {
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && velocity > -MAX_SPEED) {
    velocity -= 0.03;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && velocity < MAX_SPEED) {
    velocity += 0.05;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && rotationSpeed > -MAX_ROTATION_SPEED) {
    rotationSpeed -= 0.1;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && rotationSpeed < MAX_ROTATION_SPEED) {
    rotationSpeed += 0.1;
  }

  if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    shot = false;

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !shot) {
    bullets.emplace_back(body.getRotation(), body.getPosition());
    shot = true;
  }

  float degree = body.getRotation();
  body.move(sf::Vector2f(X(velocity, degree), Y(velocity, degree)));
  body.rotate(rotationSpeed);
  
  edgeCheck();
}
