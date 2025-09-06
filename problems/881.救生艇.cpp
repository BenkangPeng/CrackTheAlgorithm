/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */

#include <algorithm>
#include <vector>

using std::vector;
// @lc code=start
class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    std::sort(people.begin(), people.end());

    int n = people.size();
    int l = 0, r = n - 1;

    int sum = 0, ans = 0;
    while (l < r) {
      sum = people[l] + people[r];
      if (sum > limit) {
        --r;
      } else {
        ++l;
        --r;
      }
      ++ans;
    }

    if (l == r) {
      ++ans;
    }

    return ans;
  }
};
// @lc code=end
