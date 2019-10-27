#ifndef _VECTOR
#define _VECTOR

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Vector {
  std::vector<double> vector;
  unsigned int dimension = 0;

public:
  void addElement(double);

  Vector operator+(const Vector&) const;
  Vector operator-(const Vector&) const;
  double dot(const Vector&) const;

  unsigned int getDimension();

  friend std::ostream& operator<<(std::ostream&, const Vector&);
};

#endif
