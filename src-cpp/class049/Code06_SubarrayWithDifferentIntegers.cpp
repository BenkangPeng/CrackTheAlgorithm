/// https://leetcode.cn/problems/subarrays-with-k-different-integers/description/
/// 发现用滑动窗口去做,没法做剪枝,想不到比O(N^2)更好的解法,必定超时
/// 用滑窗做时,[l,r]中有k个不同的数时, 也不知道[l,r]中有多少个数的种类=k的子串
/// 但是知道数的种类<=k的子串个数为r-l+1, 即[l,r]中有r-l+1个子串,
/// 它们有<=k个不同的数

/// 技巧:
// 例如，要计算有多少个元素和恰好等于 k 的子数组，可以把问题变成：
// 计算有多少个元素和 ≥k 的子数组。
// 计算有多少个元素和 >k，也就是 ≥k+1 的子数组。
// 答案就是元素和 ≥k 的子数组个数，减去元素和 ≥k+1 的子数组个数。这里把 > 转换成
// ≥，从而可以把滑窗逻辑封装成一个函数 f，然后用 f(k) - f(k + 1)
// 计算，无需编写两份滑窗代码。
// 总结：「恰好」可以拆分成两个「至少」，也就是两个「越长越合法」的滑窗问题。
// 注：也可以把问题变成 ≤k 减去 ≤k−1（两个至多）。可根据题目选择合适的变形方式
// 作者：灵茶山艾府
// 链接：https://leetcode.cn/discuss/post/3578981/ti-dan-hua-dong-chuang-kou-ding-chang-bu-rzz7/

#include <vector>

class Solution {

public:
  int subarraysWithKDistinct(std::vector<int> &nums, int k) {
    return f(nums, k) - f(nums, k - 1);
  }

private:
  /// nums中有多少个子串, 它们的数的种类要<=k
  int f(const std::vector<int> &nums, int k) {

    int n = nums.size();
    std::vector<int> cnt(n + 1, 0);
    int collect = 0; // 当前窗口中不同数的个数
    int ans = 0;
    for (int l = 0, r = 0; r < n; ++r) {
      if (cnt[nums[r]]++ == 0) {
        collect++;
      }

      /// 缩小左边界
      while (collect > k) {
        if (--cnt[nums[l]] == 0) {
          collect--;
        }
        l++;
      }
      ans += r - l + 1;
    }

    return ans;
  }
};