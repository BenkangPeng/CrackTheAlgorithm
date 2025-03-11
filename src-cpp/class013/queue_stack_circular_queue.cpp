#include<iostream>

#define MAXSIZE 100


template <typename T>
class _queue{
    public:
        T* q = new T[MAXSIZE];
        int front = 0 , rear = 0;

        int get_length(){
            return (rear - front);
        }

        void push(T elem){
            if(rear == MAXSIZE - 1){
                std::cout << "the queue is filled" << std::endl;
                exit(-1);
            }
            q[rear++] = elem;
        }

        T pop(){
            if(get_length() == 0){
                std::cout << "the queue is empty" << std::endl;
                exit(-1);
            }
            return q[front++];
        }

        ~_queue(){
            delete[] q;
        }
};


template <typename T>
class _stack{
    public:
        T* s = new T[MAXSIZE];
        int base = 0 , top = 0;

    int get_length(){
        return top - base;
    }

    void push(T elem){
        if(top == MAXSIZE - 1){
            std::cout << "the stack is filled" << std::endl;
            exit(-1);
        }

        s[top++] = elem;
    }

    T pop(){
        if(top == 0){
            std::cout << "the stack is empty" << std::endl;
            exit(-1);
        }
        return s[--top];
    }

    ~_stack(){
        delete[] s;
    }
};

template <typename T>
class circular_queue{
    private:
        T* c_q = new T[MAXSIZE];
        int front = 0 , rear = 0;

    public:
        int get_length(){
            return (rear - front + MAXSIZE) % MAXSIZE;
        }

        void push(T elem){
            if((rear + 1) % MAXSIZE == front){
                std::cout << "the circular queue is filled" << std::endl;
                exit(-1);
            }
            else{
                c_q[rear] = elem;
                rear = (rear + 1 + MAXSIZE) % MAXSIZE;
            }
        }

        T pop(){
            if(front == rear){
                std::cout << "the circular queue is empty" << std::endl;
                exit(-1);
            }
            else{
                T e = c_q[front];
                front = (front + 1) % MAXSIZE;
                return e;
            }
        }

        ~circular_queue(){
            delete[] c_q;
        }

    
};


// https://leetcode.cn/problems/design-circular-queue/

class MyCircularQueue {
private:
    int* q;
    int len;
    int front = 0 , rear = 0;

public:
    MyCircularQueue(int k): len(k+1) {
        q = new int[k+1];
    }
    
    bool enQueue(int value) {
        if((rear+1)%len == front){
            return false;
        }
        else{
            q[rear] = value;
            rear = (rear + 1) % len;
            return true;
        }
    }
    
    bool deQueue() {
        if(front == rear)   return false;
        else{
            front = (front + 1) % len;
            return true;
        }
    }
    
    int Front() {
        if(front == rear)   return -1;
        else    return q[front];
    }
    
    int Rear() {
        if(front == rear)   return -1;
        else return q[(rear-1+len) % len];
    }
    
    bool isEmpty() {
        if(front == rear)   return true;
        else return false;
    }
    
    bool isFull() {
        if((rear+1)%len == front)   return true;
        else return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main(){
    MyCircularQueue cq(5);

    for(int i = 0 ; i < 5 ; i++)
        cq.enQueue(i);

    
    std::cout << cq.Rear() << std::endl;
    // for(int i = 0 ; i < 5 ; i++)
}