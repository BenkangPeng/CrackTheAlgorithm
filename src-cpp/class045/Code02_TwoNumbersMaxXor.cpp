/// https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/
/// 思路：：将所有num从高到低的每一位(0 or
/// 1)存在字典树中；；对每一个num，，从高位到低位，寻找相反位是否存在 例如num =
/// 11001,那么问题转换为了字典树中是否存在00110
#include <algorithm>
#include <memory>
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
  */
  void insert(const std::vector<int> &nums, int bit) {
    for (int num : nums) {
      int node = 0;
      int elem;
      for (int i = bit; i >= 0; --i) {
        elem = (num >> i) & 1; // 0 or 1
        if (tree[node].next[elem] == 0) {
          tree[node].next[elem] = ++cnt;
        }
        node = tree[node].next[elem];
      }
    }
  }

  int findMaxXor(int num, int bit) {
    int ans = 0;
    int node = 0;
    for (int i = bit; i >= 0; --i) {
      int state = (num >> i) & 1;
      int want = !state;
      if (tree[node].next[want] != 0) {
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
    if(max_val == 0)    return 0;
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