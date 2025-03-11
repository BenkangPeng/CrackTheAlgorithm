/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// Definition for a binary tree node.
#include<vector>
using std::vector;
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
private:
    TreeNode* node[2000];
    int l = 0;
    int r = 0;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        node[r++] = root;
        vector<vector<int>> ans;
        while(l < r){
            int len =  r - l;
            vector<int> _ans;
            for(int k = 0; k < len; ++k){
                TreeNode* tmp = node[l++];
                _ans.push_back(tmp->val);
                if(tmp->left)   node[r++] = tmp->left;
                if(tmp->right)  node[r++] = tmp->right;
            }

            ans.push_back(_ans);
        }

        return ans;

    }
};
// @lc code=end

