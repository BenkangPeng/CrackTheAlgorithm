/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
#include<algorithm>

// @lc code=start
class Solution {
private:
    int yes;
    int no;
    void f(TreeNode* root){
        if(root->left == nullptr && root->right == nullptr){
            yes = root->val;
            no = 0;
        }
        else{
            int y = root->val;
            int n = 0;

            if(root->left){
                f(root->left);
                y += no;
                n += std::max(yes, no);
            }

            if(root->right){
                f(root->right);
                y += no;
                n += std::max(yes, no);
            }

            yes = y;
            no  = n;
        }
    }
public:
    int rob(TreeNode* root) {
        f(root);
        return yes > no ? yes : no;
    }
};
// @lc code=end

