// https://leetcode.cn/problems/palindrome-linked-list/
// 用容器做的方法不说了，很简单

// 


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)  return true; 
        //快慢指针找中点(快慢指针不仅可以用来找环，还可以找链表中点：fast指针速度是slow的两倍，fast到达尾结点时，slow正好在中点)
        ListNode* fast = head , *slow = head;
        int len = 0;//链表长度

        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            len++;
        }

        len = fast->next == nullptr ? (len * 2 + 1) : (len + 1) * 2;
        //做一个特判，如果链表长度为偶数 且 mid->val != mid->next->val , 链表一定不是回文链表
        if(len % 2 == 0 && slow->val != slow->next->val)    return false;

        //此时slow来到链表的中点位置(若链表结点为偶数，slow = length / 2 - 1, 若为奇数 ， slow = length / 2)
        ListNode* mid = slow;//记录中点结点

        //翻转中点以后的结点，便于从尾结点遍历链表(类似于判断回文字符串的双指针算法)
        //例如，1 -> 2 -> 3 -> 3 -> 2 -> 1
        //变成，1 -> 2 -> 3 <- 3 <- 2 <- 1 , 3 -> null
        //注意，中间结点mid要指向null

        ListNode* cur = mid->next;
        ListNode* next = nullptr , *pre = mid;
        while(cur != nullptr){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;

        }
        mid->next = nullptr;
        ListNode* end = pre;//拿出尾结点
        ListNode* start = head;
        //以下就类似双指针算法
        bool ans = true;
        while(start != nullptr && end != nullptr){
           if(start->val != end->val){
                ans = false;
                break;
           } 

           start = start->next;
           end = end->next;
        }

        //恢复链表原状
        end = pre;//尾结点
        cur = end;
        pre = nullptr;
        next = cur->next;
        while(cur != nullptr){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }




        return ans;



        
    }
};