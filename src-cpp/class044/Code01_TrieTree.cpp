#include<array>
#include<memory>
#include<string>
class TrieNode{

public:
    int pass;
    int end;
    std::array<TrieNode*, 26> next;

    TrieNode(): pass(0), end(0){}

    TrieNode(int _pass, int _end): pass(_pass), end(_end){}

};

class TrieTree{

public:
    std::shared_ptr<TrieNode> root = std::make_shared<TrieNode>();

    void insert(const std::string& word){
        TrieNode* ptr = root.get();
        ++(ptr->pass);

        for(auto ch: word){
            TrieNode* next = ptr->next[ch-'a'];
            if(next == nullptr){
                next = std::make_unique<TrieNode>(1, 0).get();
                ptr = next;
            }
            else{
                ptr = next;
                ++(ptr->pass);
            }
        }

        ++(ptr->end);

    }

    int numOfString(){
        return root->pass;
    }

    int numOfPrefix(const std::string& prefix){
        auto ptr = root.get();

        for(auto ch: prefix){
            TrieNode* next = root->next[ch - 'a'];
            if(next == nullptr){
                return 0;
            }

            ptr = next;
        }

        return ptr->pass;
    }

    bool exit(const std::string& word){
        TrieNode* ptr = root.get();
        
    }
};