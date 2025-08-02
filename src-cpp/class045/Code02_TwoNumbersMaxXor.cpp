/// https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/
/// 思路：：将所有num从高到低的每一位(0 or
/// 1)存在字典树中；；对每一个num，，从高位到低位，寻找相反位是否存在 例如num =
/// 11001,那么问题转换为了字典树中是否存在00110
#include <algorithm>
#include <vector>
using std::vector;
const int MAXN = (int)3e6;
struct TrieNode {
  int next[2] = {0};
};
class TrieTree {
private:
  TrieNode tree[MAXN];
  int cnt = 0;

public:
  /*!
  @param bit the bit position which num is stored from.
  @note 若nums中最大值的最高位1为`bit`，`bit` <
  32时，我们可以从`bit`位开始存储，而不需要存储前面的0;
  例如nums中所有数的高10位(31~22)均为0，那么可以从21位开始存进TrieTree
  */
  void insert(const std::vector<int> &nums, int bit) {
    for (int num : nums) {
      int node = 0;
      int elem;
      for (int i = bit; i >= 0; --i) {
        /// `num`的第i位，0 or 1
        elem = (num >> i) & 1; // 0 or 1
        if (tree[node].next[elem] == 0) {
          tree[node].next[elem] = ++cnt;
        }
        node = tree[node].next[elem];
      }
    }
  }

  /*!
  @brief 在TrieTree中寻找与`num`异或能得到的最大值
  @param bit 从第bit位开始匹配(前bit位均为0)
  */
  int findMaxXor(int num, int bit) {
    int ans = 0;
    int node = 0;
    for (int i = bit; i >= 0; --i) {
      /// `num`第i位比特值，0 or 1
      int state = (num >> i) & 1;
      /// 为达到最大异或值，want与state相反
      /// 例如state=1,那么want=0时,这一位上异或值最大(1)
      int want = !state;
      /// 如果字典树中有数的第i位 == want
      if (tree[node].next[want] != 0) {
        /// 第i位 = 1
        ans = ans | (1 << i);
        node = tree[node].next[want];
      } else {
        node = tree[node].next[state];
      }
    }

    return ans;
  }
};
class Solution {
public:
  int findMaximumXOR(vector<int> &nums) {
    int max_val = *std::max_element(nums.begin(), nums.end());
    if (max_val == 0)
      return 0;
    /// 得到最大值的最高位1的位置，之后字典树只要从这一bit开始存
    int high = 0;
    while (max_val != 1) {
      max_val = max_val >> 1;
      ++high;
    }

    TrieTree tree;
    tree.insert(nums, high);

    int res = 0;
    for (int num : nums) {
      int max_xor = tree.findMaxXor(num, high);
      res = res > max_xor ? res : max_xor;
    }

    return res;
  }
};