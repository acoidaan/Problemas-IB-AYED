#include "program.h"

int DoubleManager::GetIndex(double value) const {
  assert(value >= 0.0 && value <= 9.99);
  return static_cast<int>(value);
}

void DoubleManager::Add(double value) {
  int index = GetIndex(value);
  grid_[index].emplace_back(value);
}

double DoubleManager::Closest(double value) const {
  int index = GetIndex(value);
  double closest = -1.0;
  double min_diff = 1.0; 

  for (int i = std::max(0, index - 1); i <= std::min(9, index + 1); ++i) {
    for (double num : grid_[i]) {
      double diff = std::abs(num - value);
      if (diff < min_diff && diff != 0) {
        closest = num;
        min_diff = diff;
      }
    }
  } 
  return closest;
}
