#include "pla.h"

std::tuple<Vector, unsigned int> trainPLA(
    const std::vector<std::tuple<Vector, int>>& data, unsigned int dimension) {
  return trainPLA(data, dimension, 0, 1.0);
}

std::tuple<Vector, unsigned int> trainPLA(
    const std::vector<std::tuple<Vector, int>>& data, unsigned int dimension,
    unsigned int until_steps) {
  return trainPLA(data, dimension, until_steps, 1.0);
}

std::tuple<Vector, unsigned int> trainPLA(
    const std::vector<std::tuple<Vector, int>>& data, unsigned int dimension,
    double learning_rate) {
  return trainPLA(data, dimension, 0, learning_rate);
}

std::tuple<Vector, unsigned int> trainPLA(
    const std::vector<std::tuple<Vector, int>>& data, unsigned int dimension,
    unsigned int until_steps, double learning_rate) {
  Vector weights;
  for (unsigned int i = 0; i != dimension + 1; i++) weights.addElement(0.0);

  bool keep_doing = true;
  unsigned int steps = 0;
  while (keep_doing) {
    keep_doing = false;
    for (auto& [x, y] : data) {
      if (weights.dot(x) * y <= 0.0) {
        weights = weights + learning_rate * y * x;
        keep_doing = true;
        steps++;
        if (until_steps > 0 && steps >= until_steps) {
          keep_doing = false;
          break;
        }
      }
    }
  }

  return {weights, steps};
}

Vector trainPocketPLA(const std::vector<std::tuple<Vector, int>>& data,
                      unsigned int dimension, unsigned int until_steps) {
  Vector weights;
  for (unsigned int i = 0; i != dimension + 1; i++) weights.addElement(0.0);
  Vector best_weights = weights;
  double error, best_error = 1.0;

  std::random_device random_device;
  std::mt19937 random_engine(random_device());
  std::uniform_int_distribution<> dis(0, data.size() - 1);

  unsigned int steps = 0;
  while (steps < until_steps) {
    auto& [x, y] = data[dis(random_engine)];
    if (weights.dot(x) * y <= 0.0) {
      steps++;
      weights = weights + y * x;
      error = test(weights, data);
      if (error < best_error) {
        best_weights = weights * 1.0;
        best_error = error;
      }
    }
  }

  return best_weights;
}

double test(const Vector& weights,
            const std::vector<std::tuple<Vector, int>>& data) {
  unsigned int wrong = 0;
  for (auto& [x, y] : data)
    if (weights.dot(x) * y <= 0.0) wrong++;

  return static_cast<double>(wrong) / data.size();
}
