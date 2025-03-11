// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal

#include<iostream>
#include<vector>
#include<deque>
#include<memory>
struct TreeNode {
    int val;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, std::unique_ptr<TreeNode> left, std::unique_ptr<TreeNode> right) 
            : val(x), left(std::move(left)), right(std::move(right)) {}
};

class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(const std::unique_ptr<TreeNode>& root) {
        if(root == nullptr) return {};

        std::vector<std::vector<int>> ans;
        std::deque<const TreeNode*> Q;
        Q.push_back(root.get());
        bool reverse = false;
        while(!Q.empty()){
            int levelSize = Q.size();
            std::vector<int> levelValues;

            if(reverse){
                for(int i = levelSize-1; i >= 0; --i){
                    levelValues.push_back(Q[i]->val);
                }
            }
            else{
                for(const auto* node : Q){
                    levelValues.push_back(node->val);
                }
            }

            reverse = !reverse;
            for(int i = 0 ; i < levelSize ; ++i){
               const TreeNode* node = Q.front();
               Q.pop_front();
               if(node->left)   Q.push_back(node->left.get());
               if(node->right)  Q.push_back(node->right.get()); 
            }

            ans.push_back(levelValues);
        }
        return ans;
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
    auto ans = s.zigzagLevelOrder(root);
    for (const auto& level : ans) {
        for (int val : level) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}