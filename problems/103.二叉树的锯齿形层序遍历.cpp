/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */


// Definition for a binary tree node.
#include<vector>
#include<deque>
using std::deque;
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
    TreeNode* dq[2000];
    int l = 0, r = 0;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        dq[r++] = root;

        vector<vector<int>> ans;
        bool reverse = false;
        while(l < r){
            
            int i = reverse ? r-1 : l;
            int step = reverse ? -1 : 1;
            int len = r - l;
            vector<int> _ans;

            for(int k = 0; k < len; ++k){
                _ans.push_back(dq[i]->val);
                i += step;
            }
            
            for(int k = 0; k < len; ++k){
                TreeNode* _top = dq[l++];

                if(_top->left){
                    dq[r++] = _top->left;
                }
                if(_top->right){
                    dq[r++] = _top->right;
                }
            }

            reverse = !reverse;
            ans.push_back(_ans);
            
        }

        return ans;
    }
};
// @lc code=end

