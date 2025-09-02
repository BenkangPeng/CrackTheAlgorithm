/// 287 https://leetcode.cn/problems/find-the-duplicate-number/description/
/// 思路：对于nums，以索引idx为结点, nums[idx]为边, 构建一个图
/// 因为至少存在一对i,j使得nums[i] = nums[j] = d(重复值)
/// 因此结点i,j指向同一个结点, 图存在一个环
/// 问题转换为链表找环问题

#include <iostream>
#include <vector>

class Solution {
public:
  int findDuplicate(std::vector<int> &nums) {
    int slow = 0, fast = 0;

    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    fast = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};

int main() {
  Solution ss;
  std::vector<int> nums = {1, 3, 4, 2, 2};
  std::cout << ss.findDuplicate(nums);
}