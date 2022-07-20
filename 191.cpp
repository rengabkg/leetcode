#include <cstdint>

using namespace std;

class Solution {
  public:
    int hammingWeight(const uint32_t n) { return __builtin_popcount(n); }
};
