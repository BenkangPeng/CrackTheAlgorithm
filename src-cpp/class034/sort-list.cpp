// https://leetcode.cn/problems/sort-list/description/
// 要求时间复杂度为O(NlogN), 空间复杂度为O(1) , 且排序具有稳定性
// 以上要求在数组中无法做到，但在链表中可以用归并排序满足以上要求，无需额外空间
// 而且不能使用递归版的归并排序，因为递归的时间复杂度不是O(1)
// 需要使用迭代版的归并排序


#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* new_head , *new_end;//全局变量,记录一段子链表经过merge后新的头与尾
    void merge(ListNode* l1 , ListNode* r1 , ListNode* l2 , ListNode* r2){
        if(l1->val <= l2->val){
            new_head = l1;
            l1 = l1->next;
        }
        else{
            new_head = l2;
            l2 = l2->next;
        }

        ListNode* cur = new_head;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }

        if(l1 != nullptr){
            cur->next = l1;
            new_end = r1;
        }
        else{
            cur->next = l2;
            new_end = r2;
        }
        

    }

    ListNode* find_end(ListNode* first , int k){
        //返回first偏置k后的结点，如果为null，则返回最后一个非空结点
        ListNode* cur = first;
        while(cur->next && --k){//这里的while判断条件中一定要写成cur->next,否则有返回nullptr的可能
        //与reverse-nodes-in-k-group中不同
            cur = cur->next;
        }

        return cur;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head)   return nullptr;

        ListNode* p = head;
        int n = 0;//记录链表长度
        while(p){
            p = p->next;
            n++;
        }
   
        ListNode* l1 , *r1 , *l2 , *r2;
        ListNode* next_group_l1 , *last_group_end;
        for(int step = 1 ; step <= n ; step <<= 1){


            //第一组特殊，因为它决定了链表的头，需要单独处理
            l1 = head;
            r1 = find_end(l1 , step);

            l2 = r1->next;
            if(l2 == nullptr)   break;
            r2 = find_end(l2 , step);
            next_group_l1 = r2->next;//记录下一组的l1  


            r1->next = nullptr;
            r2->next = nullptr;//断开链表，设置merge函数中遍历截止条件

            merge(l1 , r1 , l2 , r2);

            head = new_head;
            last_group_end = new_end;

            while(next_group_l1 != nullptr){
                l1 = next_group_l1;
                r1 = find_end(l1 , step);
                l2 = r1->next;
                if(l2 == nullptr){
                    last_group_end->next = l1;//连接上一个经过merge的子链
                    break;
                }

                r2 = find_end(l2 , step);
                next_group_l1 = r2->next;

                r1->next = nullptr;
                r2->next = nullptr;

                merge(l1 , r1 , l2 , r2);
                last_group_end->next = new_head;
                last_group_end = new_end;
            }
            
        }
        return head;
    }
};


int main()
{
    // -1,5,3,4,0
    ListNode n1(-1);
    ListNode n2(5);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(0);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = nullptr;

    Solution s;
    ListNode* head = &n1;
    ListNode* _head = s.sortList(head); 
}