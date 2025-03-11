#include<deque>
class MyCircularDeque {
private:
    std::deque<int> dq;
    int MAXSIZE;
public:
    MyCircularDeque(int k): MAXSIZE(k) {

    }
    
    bool insertFront(int value) {
        if(isFull())    return false;
        else{
            dq.push_front(value);
            return true;
        }
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        else{
            dq.push_back(value);
            return true;
        }
    }
    
    bool deleteFront() {
        if(isEmpty())   return false;
        else{
            dq.pop_front();
            return true;
        }
    }
    
    bool deleteLast() {
        if(isEmpty())   return false;
        else{
            dq.pop_back();
            return true;
        }
    }
    
    int getFront() {
        if(isEmpty())   return -1;
        else{
            return dq.front();
        }
    }
    
    int getRear() {
        if(isEmpty())   return -1;
        else{
            return dq.back();
        }
    }
    
    bool isEmpty() {
        return dq.empty();
    }
    
    bool isFull() {
        return dq.size() == MAXSIZE;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */


class MyCircularDeque2 {
private:
    int* data;
    int size;
    int l , r;
    int MAXSIZE;
public:
    MyCircularDeque2(int k): data(new int[k]) {
        size = 0;
        l = 0;
        r = 0;
        MAXSIZE = k;
    }
    
    bool insertFront(int value) {
        if(isFull())    return false;
        else{
            if(isEmpty()){
                l = r = 0;
                data[l] = value;
            }
            else{
                l = (l - 1 + MAXSIZE) % MAXSIZE;
                data[l] = value;
            }
            size++;
            return true;
        }
    }
    
    bool insertLast(int value) {
        if(isFull())    return false;
        else{
            if(isEmpty()){
                l = r = 0;
                data[r] = 0;
            }
            else{
            r = (r+1) % MAXSIZE;
            data[r] = value;
            }
            size++;
            return true;
        }
    }
    
    bool deleteFront() {
        if(isEmpty())   return false;
        else{
            l = (l+1)%MAXSIZE;
            size--;
            return true;
        }
    }
    
    bool deleteLast() {
        if(isEmpty())    return false;
        else{
            r = (r - 1 + MAXSIZE) % MAXSIZE;
            size--;
            return true;
        }
    }
    
    int getFront() {
        if(isEmpty())   return -1;
        else return data[l];
    }
    
    int getRear() {
        if(isEmpty())   return -1;
        else{
            return data[r];
        }
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == MAXSIZE;
    }

    ~MyCircularDeque2(){
        delete[] data;
    }
};

int main()
{
    MyCircularDeque2 circularDeque(5); // 设置容量大小为3
    circularDeque.insertFront(7);			        // 返回 true
    circularDeque.insertLast(0);			        // 已经满了，返回 false
    int a = circularDeque.getFront();  				// 返回 2
    circularDeque.isFull();				        // 返回 true
    circularDeque.deleteLast();			        // 返回 true
    circularDeque.insertFront(4);			        // 返回 true
    int b = circularDeque.getFront();				// 返回 4
}
/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */