// hard : https://leetcode.cn/problems/merge-k-sorted-lists/description/


#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    struct comparator{
        bool operator()(ListNode* a , ListNode* b){
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode* , std::vector<ListNode*> , comparator > min_heap;

        for(auto it : lists){
            if(it != nullptr){
                min_heap.push(it);
            }
        }

        if(min_heap.empty())    return nullptr;

        ListNode* h = min_heap.top();
        ListNode* cur = h;
        min_heap.pop();
        if(h->next != nullptr){
            min_heap.push(h->next);
        }

        while(!min_heap.empty()){
            ListNode* tmp = min_heap.top();
            min_heap.pop();
            cur->next = tmp;
            cur = cur->next;
            if(tmp->next != nullptr){
                min_heap.push(tmp->next);
            }
        }

        return h;
    }
};