//计数排序 参考link https://oi-wiki.org/basic/counting-sort/

//测试链接： https://leetcode.cn/problems/sort-an-array/description/
// 99.9%
#include<vector>
class Solution {
private:
    std::vector<int> count_sort(std::vector<int>& nums){
        int min = nums[0] , max = nums[0];
        for(auto it : nums){
            min = min < it ? min : it;
            max = max > it ? max : it;
        }

        // int* help = new int[max - min + 1];
        // int* cnt  = new int[max - min + 1];

        const int MAXN = 1e5 + 10;
        int help[MAXN];
        int cnt[MAXN];
        for(int i = 0 ; i < MAXN ; i++){
            cnt[i] = 0;
        }

        //所有数变成非负数
        for(auto& it : nums){
            it -= min;
            cnt[it]++;
        }

        for(int i = 1 ; i < MAXN ; i++){
            cnt[i] += cnt[i-1];
        }

        for(int i = nums.size() - 1 ; i >= 0 ; i--){
            help[ --cnt[nums[i]] ] = nums[i];
        }

        for(int i = 0 ; i < nums.size() ; i++){
            nums[i] = help[i];
        }




        for(auto& it : nums){
            it += min;
        }
        // delete [] help;
        // delete [] cnt;

        return nums;
    }
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        return count_sort(nums);
    }

};