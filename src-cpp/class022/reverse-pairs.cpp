// * 思考一个问题在大范围上的答案，是否等于，左部分的答案 + 右部分的答案 + 跨越左右产生的答案
// * 计算“跨越左右产生的答案”时，如果加上左、右各自有序这个设定，会不会获得计算的便利性
// * 如果以上两点都成立，那么该问题很可能被归并分治解决（话不说满，因为总有很毒的出题人）

// https://leetcode.cn/problems/reverse-pairs/description/

#include<vector>
#include<iostream>
class Solution {
private:
    int help[50001];
    int merge(std::vector<int>& nums , int l , int mid , int r){
        //统计
        int ans = 0;
        for(int i = l , j = mid + 1 ; i <= mid ; i++){
            while(j <= r && (long) nums[i] > (long) 2 * nums[j]){
                j++;
            }
            ans += j - mid - 1;
        }

        //排序
        int i = l , j = mid + 1;
        int k = l;
        while(i <= mid && j <= r){
            help[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];

        }
        while(i <= mid) help[k++] = nums[i++];
        while(j <= r)   help[k++] = nums[j++];
        for(int i = l ; i <= r ; i++)
            nums[i] = help[i];
        return ans;
    }
    int iteration(std::vector<int>& nums , int l , int r){
        if(l == r)  return 0;
        int mid = (l + r) >> 1;
        return iteration(nums , l , mid) + iteration(nums , mid + 1 , r) + merge(nums , l , mid , r);
    }
public:
    int reversePairs(std::vector<int>& nums) {
        int n = nums.size();
        return iteration(nums , 0 , n-1 );
    }
};


//还有一道逆序对的题
// https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/


class Solution {
private:
    int help[50001];
    int merge(std::vector<int>& record , int l , int mid , int r){

        int ans = 0;
        for(int i = l , j = mid + 1 ; i <= mid ; i++){
            while(j <= r && record[i] > record[j]){
                j++;
            }
            ans += j - mid - 1;
        }

        int i = l , j = mid + 1;
        int k = l;
        while(i <= mid && j <= r){
            help[k++] = record[i] <= record[j] ? record[i++] : record[j++];
        }

        while(i <= mid) help[k++] = record[i++];
        while(j <= r)   help[k++] = record[j++];

        for(int i = l ; i <= r ; i++)
            record[i] = help[i];
        return ans;
    }

    int iteration(std::vector<int>& record , int l , int r){
        if(l == r)  return 0;

        int mid = (l + r) >> 1;
        return iteration(record , l , mid) + iteration(record , mid + 1 , r) + merge(record , l , mid , r);
    }
public:
    int reversePairs(std::vector<int>& record) {
        int n = record.size() ;
        if(!n)  return 0;
        return iteration(record , 0 , n-1);
    }
};