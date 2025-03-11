//  https://leetcode.cn/problems/binary-tree-level-order-traversal/
#include<queue>
#include<vector>
#include<iostream>
#include<unordered_map>
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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        TreeNode* head = root;
        std::queue<TreeNode*> Q;
        std::unordered_map<TreeNode* , int> levels;
        std::vector<std::vector<int>> ans;
        Q.push(head);
        levels[head] = 0;
        // ans.push_back({});
        while(! Q.empty()){
            TreeNode* cur = Q.front();
            Q.pop();
            int level = levels[cur];
            if(ans.size() == level){
                ans.push_back({});
            }
            ans.back().push_back(cur->val);
            
            if(cur->left != nullptr){
                Q.push(cur->left);
                levels[cur->left] = level + 1;
            }
            if(cur->right){
                Q.push(cur->right);
                levels[cur->right] = level + 1;
            }
        }

        return ans;
    }
};
//不使用哈希表，结点所处的层数是可以由Q.size()得出的
class Solution2 {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        TreeNode* head = root;
        std::queue<TreeNode*> Q;
        std::vector<std::vector<int>> ans;
        Q.push(head);
        while(!Q.empty()){
            int len = Q.size();
            ans.push_back({});
            for(int i = 0 ; i < len ; i++){//这一层就len - 1个结点
                TreeNode* tmp = Q.front();
                Q.pop();
                ans.back().push_back(tmp->val);
                if(tmp->left)   Q.push(tmp->left);
                if(tmp->right)  Q.push(tmp->right);
            }
        }

        return ans;
    }
};

//加速 用数组取代队列
class Solution3 {
private:
    TreeNode* Q[2001];
    int l = 0 , r = 0;
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        TreeNode* head = root;
        std::vector<std::vector<int>> ans;
        Q[r++] = head;

        while(l < r){
            int len = r - l;
            std::vector<int> _ans;
            for(int i = 0 ; i < len ; i++){
                TreeNode* tmp = Q[l++];
                _ans.push_back(tmp->val);
                if(tmp->left)   Q[r++] = tmp->left;
                if(tmp->right)  Q[r++] = tmp->right;
            }
            ans.push_back(_ans);
        } 

        return ans;
    }
};