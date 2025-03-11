/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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

// @lc code=start
class Solution {
public:
    int minDepth(TreeNode* root) {
       if(root == nullptr)  return 0;
       
       if(root->left == nullptr){
            return minDepth(root->right) + 1;
       }

       if(root->right == nullptr){
            return minDepth(root->left) + 1;
       }

       int l = minDepth(root->left);
       int r = minDepth(root->right);
       return l < r ? l+1 : r+1;
    }
};
// @lc code=end

