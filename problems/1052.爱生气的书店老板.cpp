/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

#include <cstddef>
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
    /// 老板改变脾气后, 救回来的顾客数量
    int add = 0, max_add = 0;
    for (int l = 0, r = 0; r < customers.size(); ++r) {
      if (grumpy[r] == 1) {
        add += customers[r];
      }

      while (r - l + 1 > minutes) {
        if (grumpy[l] == 1) {
          add -= customers[l];
        }
        ++l;
      }
      max_add = std::max(max_add, add);
    }

    int origin = 0;
    for (int i = 0; i < customers.size(); ++i) {
      origin += customers[i] * (grumpy[i] != 1);
    }

    return origin + max_add;
  }
};
// @lc code=end
