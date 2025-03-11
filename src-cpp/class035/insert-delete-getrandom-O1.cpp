// https://leetcode.cn/problems/insert-delete-getrandom-o1/

// insert、delete方法，hast table就能做到O(1)
// 随机得到一个数：考虑将所有数紧凑地放到一个数组中，通过rand()函数产生随机的、等概率的idx，从而得到等概率的数
// 但要注意，delete一个数时，其他元素的索引也要做调整，以保证getrandom方法的等概率


#include<vector>
#include<cstdlib>
#include<unordered_map>
class RandomizedSet {
private:
    std::unordered_map<int , int> map;
    std::vector<int> arr;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(map.find(val) != map.end()){
            return false;
        }
        else{
            map[val] = arr.size();
            arr.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(map.find(val) == map.end())  return false;

        int val_idx = map[val];//获取待删除元素的idx
        map[arr.back()] = val_idx;//将arr中最后一个元素在map中的key-val的val改成待删除元素的idx
        arr[val_idx] = arr.back();//待删除元素在arr中修改成arr.back()，即将最后一个元素提到待删除元素的位置
        arr.pop_back();//删除arr最后一个元素
        map.erase(val);//删除元素
        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};


int main()
{
    // ["RandomizedSet","insert","remove","remove","insert","getRandom","remove"]
    // [[],[3],[3],[0],[3],[],[0]]
    RandomizedSet rs;
    rs.insert(3);
    rs.remove(3);
    rs.remove(0);
    rs.insert(3);
    rs.getRandom();
    rs.remove(0);
}
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */