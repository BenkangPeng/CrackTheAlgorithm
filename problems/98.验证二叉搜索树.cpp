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
    long min;
    long max;
    bool isBST = true;
public:
    bool isValidBST(TreeNode* root){
        if(root == nullptr){
            min = LONG_MAX;
            max = LONG_MIN;//空树一定满足BST

            return true;
        }

        bool lok = isValidBST(root->left);
        long lmin = min;
        long lmax = max;

        bool rok = isValidBST(root->right);
        long rmin = min;
        long rmax = max;
        if(lmax >= root->val || rmin <= root->val){
            isBST = false;
            return false;
        }

        min = (lmin < root->val) ? (lmin < rmin ? lmin : rmin) : (root->val < rmin ? root->val : rmin);
        max = (rmax > root->val) ? (rmax > lmax ? rmax : lmax) : (root->val > lmax ? root->val : lmax);


        return lok && rok && (root->val > lmax) && (root->val < rmin);
    }
};


//中序遍历
class Solution2 {
private:
    std::stack<int> st;
    bool BST = true;
    void InorderTravere(TreeNode* head){
        if(head == nullptr) return;

        InorderTravere(head->left);
        if(!st.empty() && head->val <= st.top()){
            BST = false;
        }
        st.push(head->val);
        InorderTravere(head->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        InorderTravere(root);
        return BST;
    }
};
// @lc code=end

