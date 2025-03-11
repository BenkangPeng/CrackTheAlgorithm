// 337. 打家劫舍


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
    int yes = 0;//对于一棵树，偷头结点时的最大收益
    int no = 0;//不偷头结点时的最大收益

    void f(TreeNode* head){
        if(head == nullptr){
            yes = 0;
            no = 0;
        }
        else{
            int y = head->val;//偷head时，收益为y = head->val
            int n = 0;
            f(head->left);//运行这一行后，yes和no会被改成偷/不偷head->left时的最大收益
            y += no;//偷head时，不能偷head->left, 那么偷head时，向左偷时收益y = y + no
            n += std::max(yes, no);

            f(head->right);
            y += no;
            n += std::max(yes, no);
 
            yes = y;
            no = n;
        }
    }
public:
    int rob(TreeNode* root) {
        f(root);
        return std::max(yes, no);
    }
};
// @lc code=end

