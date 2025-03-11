// 哈希集合 hast set
// https://leetcode.cn/problems/contains-duplicate/
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> my_hash_set;
        for(auto it : nums){
            if(my_hash_set.find(it) != my_hash_set.end())   return true;
            my_hash_set.insert(it);
        }

        return false;
    }
};


// 哈希表
// https://leetcode.cn/problems/two-sum/description/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> map;
        int n = nums.size() , x = 0;
        for(int i = 0 ; i < n ; i++){
            x = nums[i];
            if(map.find(target - x) != map.end()){
                return {i , map[target - x]};
            }
            else{
                map[x] = i;
            }
        }

        return {-1 , -1};
    }
};