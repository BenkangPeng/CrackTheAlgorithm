//测试链接 https://leetcode.cn/problems/implement-queue-using-stacks/

#include<iostream>
#include<stack>

class MyQueue {

private:
    std::stack<int> in;//in用来入队列，out用来出队列
    std::stack<int> out;
    void in2out(){
        // 倒数据
		// 从in栈，把数据倒入out栈
		// 1) out空了，才能倒数据
		// 2) 如果倒数据，in必须倒完

        if(out.empty()){
            while(!in.empty()){
                int x = in.top();
                in.pop();
                out.push(x);
            }
        }
    }
public:
    MyQueue() {
    }
    
    void push(int x) {
        in2out();
        in.push(x);
    }
    
    int pop() {
        in2out();
        int x = out.top();
        out.pop();
        return x;
    }
    
    int peek() {
        in2out();
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */