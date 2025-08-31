/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */
#include <unordered_map>
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
  int totalFruit(vector<int> &fruits) {

    std::unordered_map<int, int> map;
    int cnt = 0;
    int ans = 0;
    for (int l = 0, r = 0; r < fruits.size(); ++r) {
      if (map[fruits[r]]++ == 0) {
        ++cnt;
      }

      while (cnt > 2) {
        if (--map[fruits[l]] == 0) {
          --cnt;
        }
        ++l;
      }

      ans = std::max(ans, r - l + 1);
    }
    return ans;
  }
};
// @lc code=end
