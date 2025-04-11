/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)    return list2;
        if(list2 == nullptr)    return list1;

        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val > list2->val){
                head->next  = list2;
                head = head->next;
                list2 = list2->next;
            }
            else{
                head->next  = list1;
                head = head->next;
                list1 = list1->next;
            }
        }

        if(list1)   head->next = list1;
        if(list2)   head->next = list2;

        return dummy->next;
    }
};
// @lc code=end

