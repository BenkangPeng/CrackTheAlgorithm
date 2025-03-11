
// 113. https://leetcode.cn/problems/path-sum-ii/description/

/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include<vector>
using std::vector;
// @lc code=start
class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> ans;

    void f(TreeNode* cur, int targetSum, int preSum){
        if(cur->left == nullptr && cur->right == nullptr){
            //leaf node
            if(cur->val + preSum == targetSum){
                path.push_back(cur->val);
                ans.push_back(path);
                path.pop_back();
            }
        }
        else{
            path.push_back(cur->val);
            if(cur->left){
                f(cur->left, targetSum, preSum + cur->val);
            }
            if(cur->right){
                f(cur->right, targetSum, preSum + cur->val);
            }
            path.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       if(root != nullptr){
            f(root, targetSum, 0);
            return ans;
       }

       return ans;

    }
};
// @lc code=end

