/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 */

#include <algorithm>
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
  int findRadius(vector<int> &houses, vector<int> &heaters) {

    std::sort(houses.begin(), houses.end());
    std::sort(heaters.begin(), heaters.end());

    int ans = 0;
    for (int i = 0, j = 0; i < houses.size(); ++i) {
      while (!best(houses, heaters, i, j)) {
        ++j;
      }

      ans = std::max(ans, std::abs(houses[i] - heaters[j]));
    }

    return ans;
  }

  bool best(vector<int> &houses, vector<int> &heaters, int i, int j) {
    return j == heaters.size() - 1 || (std::abs(houses[i] - heaters[j]) <
                                       std::abs(houses[i] - heaters[j + 1]));
  }
};
// @lc code=end
