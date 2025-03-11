// https://leetcode.cn/problems/intersection-of-two-linked-lists/description/

#include<unordered_set>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       std::unordered_set<ListNode*> set;
       ListNode* p1 = headA;
       while(p1 != nullptr){
            set.insert(p1);
            p1 = p1->next;
       }

       ListNode* p2 = headB;
       ListNode* ans = nullptr;
       while(p2 != nullptr){
           if(set.find(p2) != set.end()){
                ans = p2;
                break;
           }
           p2 = p2->next; 
       }

       return ans;

    }
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)    return nullptr;

        ListNode* p1 = headA ;
        ListNode* p2 = headB;
        int lengthA = 0 , lengthB = 0;

        while(p1){
            lengthA++;
            p1 = p1->next;
        }

        while(p2){
            lengthB++;
            p2 = p2->next;
        }

        if(p1 != p2)    return nullptr;//两个单链表相交后一定会到达同一尾结点，不会有分叉的情况(因为交点处的结点不可能有两个next结点，不可能分叉)

        int diff = lengthA - lengthB;
        if(diff > 0){
            p1 = headA;
            p2 = headB;
        }
        else{
            p1 = headB;
            p2 = headA;
            diff = -diff;
        }

        while(diff--){
            p1 = p1->next;
        }

        while(p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;

    }
};