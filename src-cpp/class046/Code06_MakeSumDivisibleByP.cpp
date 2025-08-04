/// https://leetcode.cn/problems/make-sum-divisible-by-p/description/
/// 思路：如果仍按常规思路:
/// 拿到nums的前缀和数组prefix,去除子数组,使得剩下元素是p的整数倍,需要遍历到所有的n*p(n=1,2,3......)较为复杂
/// 转换思路: 求nums的余数前缀和
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int minSubarray(std::vector<int> &nums, int p) {
    long sum = 0;
    for (int num : nums) {
      sum += num;
    }
    int mod = sum % p;
    if (mod == 0) {
      return 0;
    }

    /// @param key 前缀和 % p
    /// @param vaule index
    std::unordered_map<int, int> map{{0, 0}};
    int n = nums.size();
    int ans = n, pre_mod = 0;
    for (int i = 0; i < n; ++i) {
      pre_mod = (pre_mod + nums[i]) % p;
      /// 找到index = j的点,余数前缀和为(pre_mod + p - mod) % p
      /// [j,i)余数前缀和的总和为mod
      /// 删除这个子数组后,剩下的数组 % p = 0
      int _find = (pre_mod + p - mod) % p;
      if (map.find(_find) != map.end()) {
        /// 易错:当前pre_mod索引值为i+1
        int len = i + 1 - map[_find];
        ans = ans < len ? ans : len;
      }
      /// 向map中添加最新的pre_mod
      map[pre_mod] = i + 1;
    }

    return ans == n ? -1 : ans;
  }
};

// int main() {
//   std::vector<int> arr = {26, 19, 11, 14, 18, 4, 7,  1,
//                           30, 23, 19, 8,  10, 6, 26, 3};

//   Solution ss;
//   int p = 26;

//   int n = arr.size();
//   std::vector<int> pre_mods(n + 1);
//   pre_mods[0] = 0;
//   for (int i = 0; i < n; ++i) {
//     pre_mods[i + 1] = (arr[i] + pre_mods[i]) % p;
//   }
//   for (int pre_mod : pre_mods) {
//     std::cout << pre_mod << ' ';
//   }
//   std::cout << '\n' << ss.minSubarray(arr, p) << std::endl;
// }