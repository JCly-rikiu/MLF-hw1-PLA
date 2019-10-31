#include <algorithm>
#include <random>
#include <tuple>

#include "file.h"
#include "pla.h"
#include "vector.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Please select the problem!" << std::endl;
    return -1;
  }

  std::random_device random_device;
  std::mt19937 random_engine(random_device());
  switch (std::stoi(argv[1])) {
    case 6: {
      auto&& [data, dimension] = parse("data/hw1_6_train.dat");
      for (auto i = 0; i != 1126; i++) {
        std::shuffle(data.begin(), data.end(), random_engine);
        [[maybe_unused]] auto&& [weights, steps] = trainPLA(data, dimension);
        std::cout << steps << " ";
      }
      std::cout << std::endl;
    } break;
    case 7: {
      auto&& [data, dimension] = parse("data/hw1_7_train.dat");
      [[maybe_unused]] auto [test_data, test_dimension] =
          parse("data/hw1_7_test.dat");
      for (auto i = 0; i != 1126; i++) {
        auto&& weights = trainPocketPLA(data, dimension, 100);
        std::cout << test(weights, test_data) << " ";
      }
      std::cout << std::endl;
    } break;
    case 8: {
      auto&& [data, dimension] = parse("data/hw1_7_train.dat");
      [[maybe_unused]] auto [test_data, test_dimension] =
          parse("data/hw1_7_test.dat");
      for (auto i = 0; i != 1126; i++) {
        std::shuffle(data.begin(), data.end(), random_engine);
        [[maybe_unused]] auto&& [weights, steps] =
            trainPLA(data, dimension, static_cast<unsigned int>(100));
        std::cout << test(weights, test_data) << " ";
      }
      std::cout << std::endl;
    } break;
    default:
      std::cerr << "Please select the problem!" << std::endl;
      break;
  }

  return 0;
}
