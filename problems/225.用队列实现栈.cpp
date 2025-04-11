/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include<queue>
// @lc code=start
class MyStack {
private:
    std::queue<int> Q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int len = Q.size();
        Q.push(x);
        //将x放到队列的最前面
        for(int i = 0; i < len; ++i){
            int t = Q.front();
            Q.pop();
            Q.push(t);
        }

    }
    
    int pop() {
       int tmp = Q.front();
       Q.pop();
       return tmp; 
    }
    
    int top() {
        return Q.front();
    }
    
    bool empty() {
        return Q.empty();
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
// @lc code=end

