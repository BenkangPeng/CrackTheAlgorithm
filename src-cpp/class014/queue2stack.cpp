// https://leetcode.cn/problems/implement-stack-using-queues/
#include<iostream>
#include<queue>

class MyStack {
private:
    std::queue<int> q;
public:
    MyStack() {

    }
    
    void push(int x) {
        int len = q.size();
        q.push(x);
        for(int i = 0 ; i < len ; i++){
            int num = q.front();
            q.pop();
            q.push(num);
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */