#include "player.hpp"
#include "../../const.hpp"


Player::Player() {
  body.setPosition(sf::Vector2f(800.f, 800.f));
  body.setSize(sf::Vector2f(CHARACTER_WIDTH, CHARACTER_HEIGHT));   
  body.setFillColor(sf::Color::Blue);
  body.setOutlineColor(sf::Color::Green);
  body.setOutlineThickness(1.f);
  body.setOrigin(CHARACTER_X_CENTER, CHARACTER_Y_CENTER);
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

  float degree = body.getRotation();
  body.move(sf::Vector2f(X(vel, degree), Y(vel, degree)));
  body.rotate(vel_rotation);

  if(body.getPosition().x < LEFT_LIMIT)
    body.move(sf::Vector2f(RIGHT_LIMIT+CHARACTER_WIDTH, 0));
  if(body.getPosition().x > RIGHT_LIMIT)
    body.move(sf::Vector2f(-(RIGHT_LIMIT+CHARACTER_WIDTH), 0));
  if(body.getPosition().y < UPPER_LIMIT)
    body.move(sf::Vector2f(0, LOWER_LIMIT+CHARACTER_WIDTH));
  if(body.getPosition().y > LOWER_LIMIT)
    body.move(sf::Vector2f(0, -(LOWER_LIMIT+CHARACTER_WIDTH)));
}
