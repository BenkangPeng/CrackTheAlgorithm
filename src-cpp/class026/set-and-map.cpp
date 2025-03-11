// 有序表
// cpp中有序表可以用std::set , std::map实现
// 这两个数据结构在插入、删除过程中都会保持有序、无重复
// 不同于std::unordered_map插入删除时间复杂度O(1)，std::set、std::map时间复杂度为O(logn) (基于红黑树实现)

#include <iostream>
#include <map>
#include <set>
#include<queue>
#include<string>

// bool comparator(const int& a , const int& b){
//     return a < b;
// }

struct MyComparator {
    bool operator()(const int& a, const int& b) const {
        return a > b; // 通过反向比较来创建小根堆
    }
};

int main() {
    // 使用 std::map
    std::map<std::string, int> myMap;
    myMap["apple"] = 1;
    myMap["banana"] = 2;
    myMap["cherry"] = 3;

    for (const auto &pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }// 按键的顺序(字典序)输出

    // 使用 std::set
    std::set<int> mySet;
    mySet.insert(3);
    mySet.insert(3);//std::set会自动去重
    mySet.insert(1);
    mySet.insert(2);

    for (const int &value : mySet) {
        std::cout << value << " ";
    }
    std::cout << std::endl;


    //cpp中也有内置的堆,使用std::priority_queue实现的,默认大根堆(java中默认是小根堆)
    std::cout << "---------------" << std::endl;

    std::priority_queue<int> max_heap;
    max_heap.push(1); 
    max_heap.push(1); 
    max_heap.push(2); 
    max_heap.push(2); 
    max_heap.push(3); 
    max_heap.push(4); 
    max_heap.push(5); 

    std::cout << "the size of heap:" << max_heap.size() << std::endl;
    while(!max_heap.empty()){
        std::cout << max_heap.top() << ' ';
        max_heap.pop();
    }//从大到小打印出来，而非堆的遍历顺序
    // std::priority_queue的目的就是方便获取优先级最大的值
    // push 、 pop时间复杂度O(logn) , top()：O(1)


    std::cout << std::endl << "use comparator to define min_heap" << std::endl;

    std::priority_queue<int , std::vector<int> , MyComparator> my_min_heap;

    my_min_heap.push(1); 
    my_min_heap.push(1); 
    my_min_heap.push(2); 
    my_min_heap.push(2); 
    my_min_heap.push(3); 
    my_min_heap.push(4); 
    my_min_heap.push(5); 


    while(!my_min_heap.empty()){
        std::cout << my_min_heap.top() << ' ';
        my_min_heap.pop();
    }
    return 0;
}

