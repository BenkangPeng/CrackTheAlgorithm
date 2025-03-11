// https://leetcode.cn/problems/min-stack/
#include<iostream>
#include<stack>
class MinStack {

private:
    std::stack<int> s , min;

    void in_min(int val){
        if(min.empty() || val <= min.top()){
            min.push(val);
        }
    }
public:
    MinStack() {

    }
    
    void push(int val) {
        s.push(val);
        in_min(val);
    }
    
    void pop() {
        int x = s.top();
        s.pop();
        if(x == min.top()){
            min.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//用数组来模拟栈，降低常数时间
class MinStack2 {
private:
    const int MAXSIZE = 8001;
    int* data;
    int* min;

    //栈指针
    int p1 = 0;
    int p2 = 0;
public:
    MinStack2():data(new int[MAXSIZE]) , min(new int[MAXSIZE]) {

    }
    
    void push(int val) {
        data[p1++] = val;
        
        if(p2 == 0 || val <= min[p2-1]){
            min[p2++] = val;
        }
    }
    
    void pop() {
        int x = data[p1-1];
        if(x == min[p2-1])  p2--;
        p1--;
    }
    
    int top() {
        return data[p1-1];
    }
    
    int getMin() {
        return min[p2-1];
    }

    ~MinStack2(){
        delete[] data;
        delete[] min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */