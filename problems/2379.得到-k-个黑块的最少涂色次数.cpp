/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 *
 * [2379] 得到 K 个黑块的最少涂色次数
 */
#include <climits>
#include <string>
// @lc code=start
class Solution {
public:
  int minimumRecolors(std::string &blocks, int k) {

    int n = blocks.size();
    int black = 0, ans = INT_MAX;
    for (int l = 0, r = 0; r < n; ++r) {
      if (blocks[r] == 'B') {
        black++;
      }

      if (r - l == k - 1) {
        ans = ans > (k - black) ? k - black : ans;

        if (blocks[l++] == 'B') {
          black--;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
