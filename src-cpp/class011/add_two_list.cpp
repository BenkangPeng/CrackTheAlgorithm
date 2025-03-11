// https://leetcode.cn/problems/add-two-numbers/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1->val == 0 && l1->next == nullptr) return l2;
        if(l2->val == 0 && l2->next == nullptr) return l1;

        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p3 = new ListNode(0);
        ListNode* _p3 = p3;
        // ListNode* tail = nullptr;
        int c = 0;
        while(p1 || p2){

            int val1 = p1 ? p1->val : 0;
            int val2 = p2 ? p2->val : 0;
            int t = val1 + val2 + c;
            c = t / 10;

            p3->next = new ListNode(t % 10);
            p3 = p3->next;
            p1 = p1 ? p1->next : p1;
            p2 = p2 ? p2->next : p2;
        }

        if(c){
            p3->next = new ListNode(1);
        }

        ListNode* head = _p3->next;
        delete(_p3);
        return head;
    }
};