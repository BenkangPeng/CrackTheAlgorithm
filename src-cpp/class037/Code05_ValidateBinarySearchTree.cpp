// 98. https://leetcode.cn/problems/validate-binary-search-tree/description/

//方法一，中序遍历二叉树，判断是否升序（很慢）
//方法二，遍历记录子树最大最小值，很快


/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
#include<stack>
#include<climits>
#include<algorithm>
// @lc code=start
class Solution{
private:
    int _max;
    int _min;
    bool valid = true;
public:
    bool isValidBST(TreeNode* root){
        if(root == nullptr){
            _min = INT_MAX;
            _max = INT_MIN;
            return true;
        }
        else{
            bool L = isValidBST(root->left);
            int lmin = _min;
            int lmax = _max;

            bool R = isValidBST(root->right);
            int rmin = _min;
            int rmax = _max;

            _max = std::max(lmax, std::max(rmax, root->val));
            _min = std::min(rmin, std::min(rmin, root->val));

            return L && R && root->val < rmin && root->val > lmax;

        }
    }
};

// @lc code=end

