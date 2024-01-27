#include <random>
#include "const.hpp"

enum Coordinate {
  COORDINATE_X,
  COORDINATE_Y
};

class Random {
  std::random_device rd;
  std::uniform_real_distribution<float> x_dist;
  std::uniform_real_distribution<float> y_dist;
  std::mt19937 gen;
public:
  Random() {
    gen = std::mt19937(rd());
    x_dist = std::uniform_real_distribution<float>(0.0, WINDOW_WIDTH);
    y_dist = std::uniform_real_distribution<float>(1.0, WINDOW_HEIGHT);
  }

  float generate(int t) {
    switch(t) {
      case COORDINATE_X:
        return x_dist(gen);
      case COORDINATE_Y:
        return y_dist(gen);
      default:
        return 0.0;
    }
  }
};
