/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

 #include<vector>
 using std::vector;
// @lc code=start
class Solution {
public:
  int minEatingSpeed(std::vector<int> &piles, int h) {
    int l = 1;
    int r = *std::max_element(piles.begin(), piles.end());
    int mid, ans;

    while (l <= r) {
      mid = l + ((r - l) >> 1);
      if (f(piles, mid) <= h) {
        r = mid - 1;
        ans = mid;
      } else {
        l = mid + 1;
      }
    }

    return ans;
  }

  /// 以k速度，多少小时可以吃完香蕉
  long long f(std::vector<int> &piles, int k) {
    long long ans = 0;
    for (auto pile : piles) {
      ans += (pile + k - 1) / k;
    }

    return ans;
  }
};
// @lc code=end

