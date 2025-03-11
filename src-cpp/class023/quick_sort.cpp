#include<iostream>
#include<vector>
#include<random>
using namespace std;
class Solution {
private:

    int first , last;
    void swap(int& a , int& b){
        int t = a;
        a = b;
        b = t;
    }
    //荷兰国旗问题
    void partition(vector<int>& nums , int l , int r , int x){
        // 不要加 ： if(l >= r) return;
        //因为加上这一句后，l == r时不再更新 first , last
        //实际上需要更新first,last
        first = l;
        last = r;
        int i = l;
        while(i <= last){
            if(nums[i] == x){
                i++;
            }
            else if(nums[i] < x){
                swap(nums[i] , nums[first]);
                first++;
                i++;
            }
            else if(nums[i] > x){
                swap(nums[i] , nums[last]);
                last--;
            }
        }
    }
    void quick_sort(vector<int>& nums , int l , int r){
        if(l >= r)  return;

        int idx = l + rand() % (r - l + 1);
        int x = nums[idx];
        partition(nums , l , r , x);
        //经过一次partition后，==x的左边界记录在first中，==x的右边界记录在last中
        //例如nums = [5 4 2 4 3 6 5] , x = 4经过一次partition后
        //nums = [3 2 4 4 6 5 5]
        //first = 2 , last = 3
        //i = 4
        int left = first;
        int right = last;
        //这里用临时变量传参
        //如果写成quick_sort(nums , l , first - 1);quick_sort(nums , last + 1 , r);
        //在执行完第一个quick_sort后，first、last会发生变化，那么执行第二个quick_sort传入的last就不是原来像传入的last了
        quick_sort(nums , l , left - 1);
        quick_sort(nums , right + 1 , r); 
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quick_sort(nums , 0 , n - 1);
        return nums;
    }
};


//关于荷兰国旗问题，可以看下面这道题目
// https://leetcode.cn/problems/sort-colors/description

class Solution {
private:
    void swap(int& a , int& b){
        int t = a;
        a = b;
        b = t;
    }
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int first = 0 , last = n - 1;
        int i = 0;
        while(i <= last){
            int x = nums[i];
            if(x == 1){
                i++;
            }
            else if(x == 0){
                swap(nums[i] , nums[first]);
                i++;
                first++;
            }
            else if(x == 2){
                swap(nums[i] , nums[last]);
                last--;
            }
        }
    }
};