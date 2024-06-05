#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#pragma once

class DoubleManager {
 public:
  void Add(double value);
  double Closest(double value) const;
 private:
  std::vector<double> grid_[10];
  int GetIndex(double value) const;
};