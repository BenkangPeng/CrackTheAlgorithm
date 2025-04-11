/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1->val == 0 && l1->next == nullptr) return l2;
        if(l2->val == 0 && l2->next == nullptr) return l1;

        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* l3 = new ListNode(0);
        ListNode* p3 = l3;
        int val1 = 0, val2 = 0;
        int c = 0;

        while(p1 || p2){
           
            val1 = (p1 == nullptr) ? 0 : p1->val;
            val2 = (p2 == nullptr) ? 0 : p2->val;

            p3->next = new ListNode(0);
            p3 = p3->next;

            int t = val1 + val2 + c;
            p3->val = t % 10;
            c = t / 10;
            
            p1 = p1 != nullptr ? p1->next : p1;
            p2 = p2 != nullptr ? p2->next : p2;
        }

        if(c){
            p3->next = new ListNode(c);
        }
        ListNode* head = l3->next;
        delete l3;
        return head;
    }
};
// @lc code=end

