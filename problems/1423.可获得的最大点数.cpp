/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */
#include <climits>
#include <vector>
// @lc code=start
class Solution {
public:
  int maxScore(std::vector<int> &cardPoints, int k) {
    int all = 0;
    for (int num : cardPoints) {
      all += num;
    }

    int n = cardPoints.size();
    int len = n - k; /// 窗口长度
    if (len == 0)
      return all;
    int ans = INT_MAX, sum = 0;
    for (int l = 0, r = 0; r < n; ++r) {
      sum += cardPoints[r];

      if (r - l + 1 == len) {
        ans = sum < ans ? sum : ans;
        sum -= cardPoints[l++];
      }
    }

    return all - ans;
  }
};
// @lc code=end
