/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */

#include<string>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<memory>
#include<iostream>
using std::string;
using std::unordered_map;
using std::unordered_set;
// @lc code=start

class bucket{
public:
    int times;
    std::unordered_set<std::string> strSet;
    bucket(int t):times(t){}
    bucket(int t, const std::string& str):times(t){
        strSet.insert(str);
    }
};
class AllOne {
public:
    std::unordered_map< std::string, std::list<std::unique_ptr<bucket>>::iterator > map;

    std::list<std::unique_ptr<bucket>> L;

public:
    AllOne() {
        auto it1 = std::make_unique<bucket>(0,"");
        auto it2 = std::make_unique<bucket>(INT_MAX,"");
        L.push_back(std::move(it1));
        L.push_back(std::move(it2));
    }
    
    void inc(string key) {
        if(map.find(key) != map.end()){//find the key
            auto it = map[key];
            int _times = (*it)->times;//origin times
            (*it)->strSet.erase(key);

            auto next = std::next(it);

            if((*next)->times == _times + 1){//if bucket with _times+1 exists
                (*next)->strSet.insert(key);
                map[key] = next;
            }
            else{
                auto new_bucket = std::make_unique<bucket>(_times+1, key);
                map[key] = L.insert(next, std::move(new_bucket));
            }

            if((*it)->strSet.empty()){
                L.erase(it);
            }
            

        }
        else{//key isn't in L, then add key into the bucket times = 1
            auto first = std::next(L.begin());
            if((*first)->times == 1){
                (*first)->strSet.insert(key);
                map[key] = first;
            }
            else{
                auto new_bucket = std::make_unique<bucket>(1, key);
                map[key] = L.insert(first, std::move(new_bucket));
            }
        }
    }
    
    void dec(string key) {
        if(map.find(key) != map.end()){
           auto it = map[key];
           int t = (*it)->times;
           (*it)->strSet.erase(key);
           
           auto prev = std::prev(it);
           if((*it)->strSet.empty()){
                L.erase(it);
           }

           if((*prev)->times == t - 1){
                (*prev)->strSet.insert(key);
                map[key] = prev;
           }
           else{
                int _t = t - 1;
                auto new_bucket = std::make_unique<bucket>(_t, key);
                map[key] = L.insert(std::next(prev), std::move(new_bucket));
           }
        }
        else{
            throw std::domain_error("want to decrease a non-exist string");
        }
    }
    
    string getMaxKey() {
        auto theLast = std::prev(L.end());
        auto the2Last = std::prev(theLast); 
       return *((*the2Last)->strSet.begin()); 
    }
    
    string getMinKey() {
        auto first = L.begin();
        auto second = std::next(first);
        return *((*second)->strSet.begin());
    }

    void print_bucket(){
        for(auto it = L.begin(); it != L.end(); ++it){
            std::cout << (*it)->times << " ";
            for(auto str : (*it)->strSet){
                std::cout << str << " ";
            }

            std::cout << std::endl;
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end




int main(){
    AllOne A;
    A.inc("hello");
    A.inc("hello");

    A.print_bucket();

    std::cout << A.getMaxKey() << std::endl;
    std::cout << A.getMinKey() << std::endl;
    A.inc("leet");
    std::cout << A.getMaxKey() << std::endl;
    std::cout << A.getMinKey() << std::endl;

    return 0;
}