//  104. https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
//  111. https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/

#include<cmath>
#include<iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root == nullptr ? 0 : std::max(maxDepth(root->left) , maxDepth(root->right)) + 1;
    }

    int minDepth(TreeNode* root){
        if(root == nullptr) return 0;
        if(root != nullptr && !root->left && !root->right)  return 1;

        int left_depth = 0x7fffffff , right_depth = 0x7fffffff;
        if(root->left != nullptr){
            left_depth = minDepth(root->left) + 1;
        }
        if(root->right){
            right_depth = minDepth(root->right) + 1;
        }

        return std::min(left_depth , right_depth);
    }

};