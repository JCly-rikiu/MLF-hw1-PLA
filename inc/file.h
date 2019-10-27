#ifndef _FILE
#define _FILE

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>

#include "vector.h"

std::tuple<std::vector<std::tuple<Vector, int>>, unsigned int> parse(std::string&&);

#endif
