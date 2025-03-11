//迭代实现归并排序
// https://leetcode.cn/problems/sort-an-array/
#include<vector>
class Solution {
private:
    int help[50001];
    void merge(int l , int mid , int r , std::vector<int>& nums){
        int i = l , j = mid + 1;
        int k = l;
        while(i <= mid && j <= r){
            help[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
        }

        while(i <= mid)   help[k++] = nums[i++];
        while(j <= r)   help[k++] = nums[j++];

        for(int i = l ; i <= r ; i++){
            nums[i] = help[i];
        }
    }
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        int n = nums.size();
        for(int l , m , r , step = 1 ; step <= n ; step <<= 1){
            l = 0;
            while(l < n){
                m = l + step - 1;
                if(m >= n-1){
                    break;//m >= n-1时，右半段没数了，无需merge
                }
                r = (l + 2 * step - 1) < (n-1) ? (l + 2 * step - 1) : n-1;
                //上一行特别注意，r最大只能到n-1
                //常错写成r = (l + 2 * step - 1);
                merge(l , m , r , nums);
                l = r + 1;
            }

        }

        return nums;
    }
};
