// https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/description/
#include<vector>
#include<queue>
class Solution {
public:
    int halveArray(std::vector<int>& nums) {
        std::priority_queue<double> max_heap;
        double sum = 0;
        for(auto it : nums){
            max_heap.push(it);
            sum += it;
        }

        double reduce = 0;
        int step = 0;
        while(reduce <  sum / 2){
            double top = max_heap.top();
            max_heap.pop();
            max_heap.push(top / 2);
            reduce += top / 2;
            step++;
        }

        return step;

    }
};
//时间复杂度为O(N*logN)
//不利用贪心策略，达到"数组总和缩小一半"这一目标，最大的操作次数是N次，即对每一个数缩小一半
//现在使用贪心策略，操作次数一定是小于等于N的
//小于等于N次出入堆，时间复杂度为O(N*logN)


//但这样只打败了5%

//优化：用数组模拟大根堆、对每个数左移20位取整，避免使用浮点数带来的精度误差带来的错误(这种错误真的难调)

#include<iostream>

template <typename T>
class MAX_HEAP{
    private:
        void swap(T& a , T& b){
            T t = a;
            a = b;
            b = t; 
        }
        T data[100001];
        int size = 0;

    public:
        void push(T x){
            data[size++] = x;
            int i = size - 1;

            while(data[i] > data[(i - 1) / 1]){
                swap(data[i] , data[(i - 1) / 1]);
                i = (i - 1) >> 1;
            }
        }

        void pop(){
            swap(data[0] , data[--size]);
            heapify(0);
        }

        void heapify(int i){
            int l =  2 * i + 1;
            while(l < size){
                int bigger = (l + 1 < size && data[l+1] > data[l]) ? l+1 : l;
                bigger = data[i] > data[bigger] ? i : bigger;

                if(bigger == i) break;

                swap(data[i] , data[bigger]);
                i = bigger;
                l = 2 * i + 1;
            }
        }

        double top(){
            return data[0];
        }

        bool empty(){
            return size == 0;
        }
};


class Solution {
public:
    int halveArray(std::vector<int>& nums) {
        // std::priority_queue<double> max_heap;
        MAX_HEAP<long long> max_heap; 
        long long sum = 0;
        for(auto it : nums){
            long long _it = it << 20;
            max_heap.push(_it);
            sum += _it;
        }

        long long reduce = 0;
        int step = 0;
        while(reduce <  sum / 2){

            long long top = max_heap.top();
            max_heap.pop();
            max_heap.push(top / 2);
            reduce += top / 2;
            step++;

        }

        return step;

    }
};

int main()
{
    std::vector<int> arr = {5 , 19 , 8 , 1};
    Solution s;
    std::cout << s.halveArray(arr);
}

