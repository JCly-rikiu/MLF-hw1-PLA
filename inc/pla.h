#ifndef _PLA
#define _PLA

#include <vector>
#include <tuple>
#include <random>

#include "vector.h"

std::tuple<Vector, unsigned int> trainPLA(const std::vector<std::tuple<Vector, int>>&, unsigned int);
std::tuple<Vector, unsigned int> trainPLA(const std::vector<std::tuple<Vector, int>>&, unsigned int, unsigned int);
std::tuple<Vector, unsigned int> trainPLA(const std::vector<std::tuple<Vector, int>>&, unsigned int, double);
std::tuple<Vector, unsigned int> trainPLA(const std::vector<std::tuple<Vector, int>>&, unsigned int, unsigned int, double);
Vector trainPocketPLA(const std::vector<std::tuple<Vector, int>>&, unsigned int, unsigned int);

double test(const Vector&, const std::vector<std::tuple<Vector, int>>&);

#endif
