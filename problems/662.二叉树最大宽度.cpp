/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
private:
    TreeNode* node[3000];
    unsigned node_id[3000];
    int l = 0, r = 0;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        node[r] = root;
        node_id[r] = 1;
        r++;

        int maxWidth = 0;
        while(l < r){
            int width = node_id[r-1] - node_id[l] + 1; 
            maxWidth = width > maxWidth ? width : maxWidth;

            int num_this_level = r - l;//number of nodes in this level
            for(int k = 0; k < num_this_level; ++k){
                //pop all the nodes of this level
                TreeNode* tmp = node[l];
                if(tmp->left){
                    node[r] = tmp->left;
                    node_id[r] = node_id[l] << 1;
                    ++r;
                }
                if(tmp->right){
                    node[r] = tmp->right;
                    node_id[r] = (node_id[l] << 1) + 1;
                    ++r;
                }
                ++l;
            }
        }

        return maxWidth;
    }
};
// @lc code=end

