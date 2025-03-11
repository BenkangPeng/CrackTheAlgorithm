/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include<memory>
#include<list>
#include<unordered_map>
struct node{
    int key;
    int value;
    node(int k, int v): key(k), value(v){}
};


class LRUCache {
private:
    std::list<std::unique_ptr<node>> L;
    std::unordered_map<int, std::list<std::unique_ptr<node>>::iterator> map;
    int capacity; 
public:
    LRUCache(int capacity):capacity(capacity) {}
    
    int get(int key) {
        if(map.find(key) != map.end()){//key-value in cache
            auto it = map[key];
            int value = (*it)->value;
            L.splice(L.end(), L, it);
            return value;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){//in cache
            auto it = map[key];
            (*it)->value = value;
            L.splice(L.end(), L, it);
        }
        else{//not in cache
            if(map.size() == capacity){// cache is full and replacement occur
                auto lru_node = std::move(L.front());
                map.erase(lru_node->key);
                L.pop_front();
            }

            auto new_node = std::make_unique<node>(key,value);
            L.push_back(std::move(new_node));
            map[key] = --L.end();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

