/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root == nullptr || root == p || root == q){
            return root;
        }

        TreeNode* target = root;
        while(target != nullptr){
            if(p->val < target->val && q->val < target->val){
                target = target->left;
            }
            else if(p->val > target->val && q->val > target->val){
                target = target->right;
            }
            else return target; 
        }

        return nullptr;
    }
};
// @lc code=end

