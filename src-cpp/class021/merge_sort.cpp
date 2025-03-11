// https://leetcode.cn/problems/sort-an-array/description/
// 填函数风格
#include<vector>
class Solution {
private:
    int help[50001];

    void merge(int l , int mid , int r , std::vector<int>& nums){
        int i = l , j = mid + 1;
        int k = l;
        while(i <= mid && j <= r){
            help[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];//两数相等时，先拷贝左边的数，以保证稳定性

        }
        while(i <= mid) help[k++] = nums[i++];
        while(j <= r)   help[k++] = nums[j++];

        for(int i = l ; i <= r ; i++){
            nums[i] = help[i];
        }
    }
    void merge_sort(int l , int r , std::vector<int>& nums){
        if(l == r) return;

        int mid = (l + r) >> 1;
        merge_sort(l , mid , nums);
        merge_sort(mid+1 , r , nums);
        merge(l , mid , r , nums);

    }
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        int n = nums.size();
        merge_sort(0 , n-1 , nums);
        return nums;
    }
};


//递归的归并排序：T(n) = 2 * T(n/2) + O(n)
// a = 2 , b = 2 , c = 1
//根据master公式，时间复杂度为O(nlogn)
//需要额外开辟一个help数组，空间复杂度为O(n)