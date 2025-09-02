/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return nullptr;
    }

    ListNode *slow = head, *fast = head;
    do {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == nullptr || fast->next == nullptr) {
        return nullptr;
      }
    } while (slow != fast);

    ListNode *ptr = head;
    while (slow != ptr) {
      slow = slow->next;
      ptr = ptr->next;
    }

    return slow;
  }
};
// @lc code=end
