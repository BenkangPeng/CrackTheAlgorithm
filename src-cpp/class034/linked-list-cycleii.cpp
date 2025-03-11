// https://leetcode.cn/problems/linked-list-cycle-ii/description/

//此题的证明见 algorithm-journey/note.md
#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)    return nullptr;

        ListNode* fast = head , *slow = head;
        do
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == nullptr || fast->next == nullptr)    return nullptr;
        } while (slow != fast);

        //以上的循环不要写成：(好傻逼，这个循环一次都运行不了，因为赋值后，fast = slow = head)
        // while(fast != slow){
        //     if(fast->next == nullptr || fast->next->next == nullptr)    return nullptr;

        //     fast = fast->next->next;
        //     slow = slow->next;
        // }
        

        ListNode* ptr = head;
        while(ptr != slow){
            ptr = ptr->next;
            slow = slow->next;
        }

        return ptr;
    }
};

int main()
{
    ListNode n1(3);
    ListNode n2(2);
    ListNode n3(0);
    ListNode n4(-4);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n2;

    ListNode* head = &n1;
    Solution s;

    std::cout << s.detectCycle(head)->val;
}