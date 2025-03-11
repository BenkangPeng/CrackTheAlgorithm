#include<iostream>
class tree_node{

    tree_node(int val): val(val) , left_node(nullptr) , right_node(nullptr){}
    public:
        int val;
        tree_node* left_node;
        tree_node* right_node;    

    //先序遍历：中、左、右
    void pre_order(tree_node* head){
        if(head == nullptr) return;

        std::cout << head->val << " ";
        pre_order(head->left_node);
        pre_order(head->right_node); 
    }

    //中序遍历：左、中、右
    void in_order(tree_node* head){
        if(head == nullptr) return;

        in_order(head->left_node);
        std::cout << head->val << " ";
        in_order(head->right_node);
    }

    //后序遍历：左、右、中
    void pos_order(tree_node* head){
        if(head == nullptr) return;

        pos_order(head->left_node);
        pos_order(head->right_node);
        std::cout << head->val << " " ;
    }
};
//时间复杂度：O(N)
//空间复杂度：O(h)，h为树的高度