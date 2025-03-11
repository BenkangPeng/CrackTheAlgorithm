// https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed/description/
// 这道题和上一道思路差不多，但是允许重复元素，因此哈希表设置成std::unordered_map<int , std::unordered_set<int>>
// 用unordered_set存储多个索引


#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<cstdlib>
class RandomizedCollection {
private:
    std::unordered_map<int , std::unordered_set<int>> map;
    std::vector<int> arr;
public:
    RandomizedCollection() {

    }
    
    bool insert(int val) {
        map[val].insert(arr.size());
        arr.push_back(val);
        return map[val].size() == 1;

    }
    
    bool remove(int val) {
        if(map.find(val) == map.end()){
            return false;
        }
        else{

            int idx = *(map[val].begin());
            arr[idx] = arr.back();
            
            map[val].erase(idx);
            map[arr[idx]].erase(arr.size() - 1);
            
            if(idx < arr.size() - 1){//去排除一个特例：idx = 0 , arr.size() = 1
                map[arr[idx]].insert(idx);
            }

            if(map[val].size() == 0){
                map.erase(val);
            }
            
            arr.pop_back();

            return true;
        }
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

int main()
{
    RandomizedCollection rc;
    rc.insert(0);
    rc.remove(0);
    rc.insert(-1);
    rc.remove(0);
    rc.getRandom();
    rc.getRandom();
    rc.getRandom();
    rc.getRandom();
    rc.getRandom();
    rc.getRandom();
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */