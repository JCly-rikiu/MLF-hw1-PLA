#include "file.h"

std::tuple<std::vector<std::tuple<Vector, int>>, unsigned int> parse(
    std::string&& filename) {
  std::vector<std::tuple<Vector, int>> data;
  unsigned int dimension;

  std::string line;
  std::ifstream file(filename);
  if (!file.is_open()) std::cerr << "Error opening file" << std::endl;
  while (std::getline(file, line)) {
    std::istringstream line_stream(line);
    double d;
    std::vector<double> numbers;
    while (line_stream >> d) numbers.push_back(d);

    int y = static_cast<int>(numbers.back());
    numbers.pop_back();

    Vector x;
    x.addElement(1.0);
    for (auto& d : numbers) x.addElement(d);
    dimension = x.getDimension();

    data.push_back({x, y});
  }

  return {data, dimension};
}
