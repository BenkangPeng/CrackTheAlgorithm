// https://leetcode.cn/problems/reverse-nodes-in-k-group/description/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* group_end(ListNode* head , int k){
        //返回以head为起始结点，偏移k个结点后的结点，即k-group的尾
        ListNode* k_offset = head;
        while(--k && k_offset != nullptr){//此处偏移不要习惯性地写成了k--
            k_offset = k_offset->next;
        }

        return k_offset;
    }

    void reverse(ListNode* start , ListNode* end){
        //翻转头结点、尾结点为start , end的子链表 
        ListNode* cur = start;
        ListNode* pre = nullptr , *next = nullptr;//pre记录翻转前，当前结点cur的前一个结点
        ListNode* next_group_start = end->next;//记录cur应该停下的结点,即下一组(k个结点一组)的头结点
        while(cur != next_group_start){//不能写成cur != end->next , 因为在while中，end->next会改变
            next = cur->next;
            cur->next = pre;
            pre = cur;//为下一个结点做记录 
            cur = next; 
        }
        start->next = next_group_start;
        
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* end = group_end(head , k);
        if(end == nullptr)  return head;//end == nullptr表示该链表长度不足k，无需翻转

        ListNode* start = head;
        head = end;//记录整个链表翻转后的头结点
        reverse(start , end);

        ListNode* last_group_end = start;//上一组(k个结点为一组)翻转后的尾结点
        start = start->next;
        while(start != nullptr){
            end = group_end(start , k);
            if(end == nullptr)  return head;

            reverse(start , end);
            last_group_end->next = end;
            last_group_end = start;
            start = start->next; 
        }

        return head;
    }
};


int main()
{
    Solution s;
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;


    ListNode* head = &n1;
    s.reverseKGroup(head , 2);

}