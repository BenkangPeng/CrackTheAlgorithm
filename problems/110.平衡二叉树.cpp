/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
#include<cmath>
// @lc code=start
class Solution {
private:
    bool balance = true;

    int height(TreeNode* cur){
        if(!balance || cur == nullptr){//不平衡时可以随意返回一个值，再继续递归求高度已经无意义了
            return 0;
        }
        else{
            
            int lh = height(cur->left);
            int rh = height(cur->right);
            if(abs(lh-rh) > 1){
                balance = false;
            }
            return lh > rh ? lh+1 : rh+1;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
       if(root == nullptr){
            return true;
       }
       
       height(root);
       return balance;
    }
};
// @lc code=end

