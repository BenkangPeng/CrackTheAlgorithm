/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
       
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0);

        ListNode *p1 = dummy1, *p2 = dummy2;
        ListNode *p = head;

        while(p != nullptr){
            if(p->val < x){
                p1->next = p;
                p1 = p1->next;
            }
            else{
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
        }

        p1->next = dummy2->next;
        p2->next = nullptr;
        ListNode* res = dummy1->next;
        delete dummy1;
        delete dummy2;
        return res;
    }
};
// @lc code=end

