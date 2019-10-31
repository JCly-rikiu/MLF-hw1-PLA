#include "vector.h"

void Vector::addElement(double d) { vector.push_back(d); }

Vector Vector::operator+(const Vector& other) const {
  Vector result;
  result.vector.resize(vector.size());
  std::transform(vector.begin(), vector.end(), other.vector.begin(),
                 result.vector.begin(), std::plus<double>());
  return result;
}

Vector Vector::operator-(const Vector& other) const {
  Vector result;
  result.vector.resize(vector.size());
  std::transform(vector.begin(), vector.end(), other.vector.begin(),
                 result.vector.begin(), std::minus<double>());
  return result;
}

double Vector::dot(const Vector& other) const {
  return std::inner_product(vector.begin(), vector.end(), other.vector.begin(),
                            0.0);
}

Vector Vector::operator*(const int& other) const {
  return (*this) * static_cast<double>(other);
}

Vector operator*(const int& other, const Vector& vector) {
  return vector * other;
}

Vector Vector::operator*(const double& other) const {
  Vector result;
  result.vector.resize(vector.size());
  std::transform(vector.begin(), vector.end(), result.vector.begin(),
                 [&](auto& x) { return x * other; });
  return result;
}

Vector operator*(const double& other, const Vector& vector) {
  return vector * other;
}

unsigned int Vector::getDimension() { return vector.size() - 1; }

std::ostream& operator<<(std::ostream& os, const Vector& other) {
  os << "Dim: " << other.vector.size() << "\n";
  for (auto& d : other.vector) os << d << " ";
  return os;
}
