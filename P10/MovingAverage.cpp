#include "MovingAverage.h"
#include <algorithm>
#include <numeric>

MovingAverage::MovingAverage(std::size_t n) : n_{n} {}

void MovingAverage::update(double value) {
  values_.push_back(value);
  if (values_.size() > n_) {
    values_.pop_front();
  }
}

double MovingAverage::get() const {
  if (values_.empty()) {
    return 0.0;
  }
  return std::accumulate(values_.begin(), values_.end(), 0.0) / values_.size();
}