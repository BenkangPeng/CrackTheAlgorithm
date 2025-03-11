// https://leetcode.cn/problems/merge-two-sorted-lists/description/


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)   return list2;
        if(list2 == nullptr)   return list1;

        ListNode* p3 = new ListNode;
        ListNode* head = p3;
        ListNode* p1 = list1;
        ListNode* p2 = list2;

        if(p1->val <= p2->val){
            p3->val  = p1->val;
            p1 = p1->next;
        }
        else{
            p3->val = p2->val;
            p2 = p2->next;
        }
        while(p1 != nullptr && p2 != nullptr){
            if(p1->val >= p2->val){
                p3->next = p2;
                p2 = p2->next;
                p3 = p3->next;
            }
            else {
                p3->next = p1;
                p1 = p1->next;
                p3 = p3->next;
            }
        }

        if(p1 != nullptr){
                p3->next = p1;
            }
        if(p2 != nullptr){
                p3->next = p2;
            }
        return head;
    }
};