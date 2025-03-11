// 236. https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/

#include<iostream>
#include<memory>
// Definition for a binary tree node.
struct TreeNode {
    int val;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(const std::unique_ptr<TreeNode>& root, const std::unique_ptr<TreeNode>& p, const std::unique_ptr<TreeNode>& q) {
        if(root == nullptr || root == p || root == q){
            return root.get();
        }

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        if(l == nullptr && r == nullptr){
            return nullptr;
        }
        if(l != nullptr && r != nullptr){
            return root.get();
        }

        return l != nullptr ? l : r;
    }
};


std::unique_ptr<TreeNode> createTree(){
    auto root = std::make_unique<TreeNode>(3);
    root->left = std::make_unique<TreeNode>(9);
    root->right = std::make_unique<TreeNode>(20);
    root->right->left = std::make_unique<TreeNode>(15);
    root->right->right = std::make_unique<TreeNode>(7);

    return root;
}

int main(){
    auto root = createTree();
    Solution s;

    auto res = s.lowestCommonAncestor(root, root->right->left, root->right->right);

    if(res){
        std::cout << res->val << std::endl;
    }
    else{
        std::cout << "NULL" << std::endl;
    }

    return 0;
}