// https://leetcode.cn/problems/partition-list/
#include<iostream>
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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0);
        ListNode* left_tail = &dummy1;

        ListNode dummy2(0);
        ListNode* right_tail = &dummy2;

        ListNode* _head = head;
        while(_head != nullptr){
            if(_head->val >= x){
                right_tail->next = _head;
                right_tail = right_tail->next;
            }
            else{
                left_tail->next = _head;
                left_tail = left_tail->next;
            }
            _head = _head->next;
        }

        left_tail->next = dummy2.next;
        right_tail->next = nullptr;

        return dummy1.next;
    }
};


int main(){
    // ListNode* head = new ListNode(2);
    // ListNode* node1 = new ListNode(1);
    // head->next = node1;

    // Solution s;
    // s.partition(head , 2);
}