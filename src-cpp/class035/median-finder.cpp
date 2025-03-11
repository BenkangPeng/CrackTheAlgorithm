// https://leetcode.cn/problems/find-median-from-data-stream/description/
// 学堆之前，肯定想着时刻去维护一个有序数组，从而找到中位数
// 但会发现，中位数两端的元素的有序性这一信息是冗余信息
// 只要保证：中位数左边元素都小于中位数，右边元素都大于中位数，即可确定中位数的位置
// 因此将元素分段，一段用大根堆维护，一段用小根堆维护


#include<queue>
#include<vector>
#include<cmath>
#include<iostream>
struct comparator
{
    bool operator()(int a , int b){
        return a > b;
    }
};

class MedianFinder {

private:
    std::priority_queue<int , std::vector<int> , comparator> min_heap;
    std::priority_queue<int> max_heap; 

    void balance(){//平衡两个堆，保证两个堆中元素个数差值<2
        if(abs((int)(max_heap.size() - min_heap.size())) == 2){//max_heap.size()返回的是size_t类型，直接用abs会产生编译错误
        //编译歧义：因为abs没有定义size_t的形参，编译器不知道选择哪一个abs函数，因此要转一次int型
            if(max_heap.size() < min_heap.size()){
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
            else{
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        }
    }
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(max_heap.empty() || num <= max_heap.top()){
            max_heap.push(num);
        }
        else{
            min_heap.push(num);
        }

        balance();
    }
    
    double findMedian() {
        return max_heap.size() == min_heap.size() ? (max_heap.top() + min_heap.top())/2.0 : (max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */