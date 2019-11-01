#ifndef _VECTOR
#define _VECTOR

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Vector {
  std::vector<double> vector;

public:
  void addElement(double);

  Vector operator+(const Vector&) const;
  Vector operator-(const Vector&) const;
  double dot(const Vector&) const;
  Vector operator*(const int&) const;
  friend Vector operator*(const int&, const Vector&);
  Vector operator*(const double&) const;
  friend Vector operator*(const double&, const Vector&);

  unsigned int getDimension();

  friend std::ostream& operator<<(std::ostream&, const Vector&);
};

#endif
