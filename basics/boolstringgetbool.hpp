// full specialization for BoolString::getValue<>() for bool
template <>
inline bool BoolString::get<bool>() const {
  return value == "true" || value == "1" || value == "on";
}

constexpr auto tenMillion = 10000000;
bool doWork(std::function<bool(int)> filter, int maxVal = tenMillion) {
  std::vector<int> goodVals;
  std::thread t([&filter, maxVal, &goodVals] {
    for (auto i = 0; i <= maxVal; ++i) {
      if (filter(i)) {
        goodVals.push_back(i);
      }
    }
  });
  auto nh = t.native_handle();  // use t's native handle to set t's priority

  if (conditionsAreStatisfied()) {
    t.join();
    performComputation(goodVals);
    return true;
  }

  return false;
}