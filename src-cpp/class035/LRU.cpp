// 146. https://leetcode.cn/problems/lru-cache/
// 这道题就是来模拟cache 的least recently used替换策略
// 用哈希表来进行键值对的存储、修改与查找 std::unordered_map<int , double_node*>
// 用双向链表存储数据上次访问的时序：链表尾表示最近访问的数据，链表头表示最远访问的数据

// get方法直接从哈希表中得到数据，并将该数据对应的结点移到链表尾，以表示最近访问
// put方法修改（或添加）哈希表中的数据，同时修改链表记录最近访问数据，但要注意：当cache容量已满且需要加入新元素时，
// 需要覆盖链表头结点(最远访问)代表的数据，并将新数据记为最近访问

#include<iostream>
#include<unordered_map>
class double_node{
    public:
        int key , value;
        double_node *next = nullptr ;
        double_node *last = nullptr ;

        double_node(int key , int value): key(key) , value(value){}
};

class double_list{
    public:
        double_node *head = nullptr;
        double_node *tail = nullptr;

        void add_node(double_node* new_node){
            if(head == nullptr){//链表为空(cache为空)，放在尾部
                head = new_node;
                tail = new_node;
            }
            else{
                tail->next = new_node;
                new_node->last = tail;
                tail = new_node;
            }
        }

        void move_to_tail(double_node* used_node){//将命中的数据used_node放到链表尾，以表示最近访问
            if(tail == used_node)   return;

            if(head == used_node){
                used_node->next->last = nullptr;
                head = used_node->next;//头结点发生变化
            }
            else{
                used_node->last->next = used_node->next;
                used_node->next->last = used_node->last;
            }

            tail->next = used_node;
            used_node->last = tail;
            used_node->next = nullptr;
            tail = tail->next;
        }

        void delete_head(){
            double_node* _head = head;

            if(head == tail){//只有一个结点，再删就空了
                head = tail = nullptr;
                delete _head;
            }
            else{
                _head->next->last = nullptr;
                head = head->next;
                delete _head;
            }

        }

};


class LRUCache {
    private:
        int capacity;
        double_list node_list;
        std::unordered_map<int , double_node*> map;

    public:
        LRUCache(int capacity): capacity(capacity) {

        }
        
        int get(int key) {
            if(map.find(key) != map.end()){
                double_node* data = map[key];
                node_list.move_to_tail(data);//当前结点被访问一次，放在链表最后，表示最近访问
                return data->value;
            }
            else{
                return -1;
            }
        }
        
        void put(int key, int value) {
            if(map.find(key) != map.end()){//在cache中找到了这个数据，只需修改，并记录最近访问
                double_node* data = map[key];//表示cache命中的数据
                data->value = value;
                node_list.move_to_tail(data);
            }
            else{//cache中没有该数据，添加该数据，并注意当前cache capacity是否已满，是否需要进行数据的覆盖
                if(map.size() == capacity){//cache已满，需要进行数据覆盖
                    map.erase(map.find(node_list.head->key));
                    node_list.delete_head();
                }

                double_node* new_data = new double_node(key,value);
                node_list.add_node(new_data);
                map[key] = new_data;
            }
        }
    };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// 上面的方法不符合modern C++风格,而且手动控制内存太复杂
class LRUCache2{
    
}
int main()
{

    // ["LRUCache","put","put","get","put","get","put","get","get","get"]
    // [[2],[1,0],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
    LRUCache cache(2);
    cache.put(1,0);
    cache.put(2,2);
    std::cout << cache.get(1) << std::endl;
    cache.put(3,3);

    std::cout << cache.get(2) << std::endl;
    cache.put(4,4);
    std::cout << cache.get(1) << std::endl;
    std::cout << cache.get(3) << std::endl;
    std::cout << cache.get(4) << std::endl;


}