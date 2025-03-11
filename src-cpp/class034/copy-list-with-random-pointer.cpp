// https://leetcode.cn/problems/copy-list-with-random-pointer/description/

//这个题用容器来做很简单，只需要将结点与random指针的对应关系存在哈希表中
//然后照着哈希表复制链表即可

#include<unordered_map>
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        Node* p1 = head;
        Node* list2 = new Node(p1->val);//新链表的头结点
        Node* p2 = list2;

        std::unordered_map<Node* , Node*> map;
        map[p1] = p2;
        p1 = p1->next;
        while(p1 != nullptr){//将原链表与新链表各结点建立map
            Node* tmp = new Node(p1->val);
            p2->next = tmp;
            p2 = p2->next;
            map[p1] = p2;
            p1 = p1->next;
        }

        p2->next = nullptr;

        p1 = head;//再次遍历原链表
        while(p1){
            map[p1]->random = map[p1->random];//map[p1]表示原链表对应的新链表中的结点
            p1 = p1->next;
        }

        return list2;


       
    }
};

// 链表的题，用容器来做都不难
// 难在不带来额外空间开销，原地操作O(1)空间复杂度


// 上面使用容器的方法，就是利用了哈希表建立对应关系
// 如果不用哈希表，如何使链表中隐含新旧链表结点对应关系呢？
// 我们可以如下建表：
// 1 -> 2 -> 3 -> ...
// 变成 : 1 -> 1' -> 2 -> 2' -> 3 -> 3' -> ...
// 在原链表上建表(1'表示新结点)，这时新旧链表结点的对应关系就是：old_node->next == new_node
// 根据这一对应关系去建立新的random关系
// 最后再把新旧链表拆开
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return nullptr;

        Node* p1 = head;
        while(p1){
            Node* next = p1->next;//记录原结点的next
            p1->next = new Node(p1->val);
            p1->next->next = next;//新节点指向下一个老节点(例如1'->2)
            p1 = next;
        }

        p1 = head;//重新遍历，步长为两个结点

        while(p1){
            p1->next->random = p1->random == nullptr ? nullptr : p1->random->next;

            p1 = p1->next->next;
        }

        //拆链表
        p1 = head;
        Node* list2 = p1->next;
        Node* p2 = list2;

        while(p1){
            Node* new_node = p1->next;
            p1->next = p1->next->next;
            new_node->next = p1->next == nullptr ? nullptr : p1->next->next;

            p1 = p1->next;
        } 

        return list2;

    }
};

int main()
{
    Node n1(1);
    Node n2(2);
    n1.next = &n2;
    n1.random = &n1;
    n2.next = nullptr;
    n2.random = &n1;

    Node* head = &n1;
    Solution s;
    Node* list2 = s.copyRandomList(head);
}



