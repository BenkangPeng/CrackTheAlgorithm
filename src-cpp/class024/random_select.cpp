#include<vector>
#include<random>
#include<iostream>
class Solution {
private:
    void swap(int& a , int& b){
        int t = a;
        a = b;
        b = t;
    }

    int first , last;
    void partition(std::vector<int>& nums , int l , int r , int x){
        // if(l >= r)  return; 不能加这一行

        first = l ;
        last = r;
        int i = l;
        while(i <= last){
            if(nums[i] < x){
                swap(nums[i++] , nums[first++]);
            }
            else if(nums[i] == x){
                i++;
            }
            else {
                swap(nums[i] , nums[last--]);
            }
        }
    }
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        int l = 0 , r = nums.size() - 1;
        int idx = r - k + 1;//第k个最大的数，对应排序后数组索引为r-k+1的数
        int ans = 0;
        while(l <= r){

            partition(nums , l , r , nums[l + rand() % (r - l + 1)]);

            if(idx < first){
                r = first - 1;
            }
            else if(idx > last){
                l = last + 1;
            }
            else{
                ans = nums[first];
                break;
            }
        }

        return ans;
    }
};


//时间复杂度O(n) , 证明略