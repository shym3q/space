#include <iostream>
#include <random>
#include "enemy.hpp"
#include "../../const.hpp"

float target_degree(sf::Vector2f, sf::Vector2f);

Enemy::Enemy(Player *p) : player_reference(p) {
  body.setSize(sf::Vector2f(CHARACTER_WIDTH, CHARACTER_HEIGHT));   
  body.setFillColor(sf::Color::Red);
  body.setOutlineColor(sf::Color::Green);
  body.setOutlineThickness(1.f);
  body.setOrigin(CHARACTER_X_CENTER, CHARACTER_Y_CENTER);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<float> x_dist(0.0, WINDOW_WIDTH);
  std::uniform_real_distribution<float> y_dist(0.0, WINDOW_HEIGHT);
  body.setPosition(sf::Vector2f(x_dist(gen), y_dist(gen)));
  vel = MAX_SPEED - 1.9;
  vel_rotation = 0;
  body.setRotation(target_degree(p->body.getPosition(), sf::Vector2f(400, 400)));
}

float target_degree(sf::Vector2f p, sf::Vector2f e) {
  float x = p.x - e.x;
  float y = p.y - e.y;
  return std::atan2(y, x) * 180.0 / M_PI;
}

void Enemy::update() {
  float degree = body.getRotation();

  auto t = target_degree(player_reference->body.getPosition(), body.getPosition());
  if(t < 0.0)
    t = 360.0 - t;
  body.rotate((t-degree) * 0.012);

  body.move(sf::Vector2f(X(vel, body.getRotation()), Y(vel, body.getRotation())));

  if(body.getPosition().x < LEFT_LIMIT)
    body.move(sf::Vector2f(RIGHT_LIMIT+CHARACTER_WIDTH, 0));
  if(body.getPosition().x > RIGHT_LIMIT)
    body.move(sf::Vector2f(-(RIGHT_LIMIT+CHARACTER_WIDTH), 0));
  if(body.getPosition().y < UPPER_LIMIT)
    body.move(sf::Vector2f(0, LOWER_LIMIT+CHARACTER_WIDTH));
  if(body.getPosition().y > LOWER_LIMIT)
    body.move(sf::Vector2f(0, -(LOWER_LIMIT+CHARACTER_WIDTH)));
}

