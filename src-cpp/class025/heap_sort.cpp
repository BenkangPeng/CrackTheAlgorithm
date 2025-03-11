// 测试链接：https://leetcode.cn/problems/sort-an-array/description/


// 当前结点索引为i
// 父结点索引为 (i - 1) / 2
// 左孩子：2i + 1 , 右孩子：2i + 2

#include<iostream>
#include<vector>
class heap{
private:
    void swap(int& a , int& b){
        int t = a;
        a = b;
        b = t;
    }
public:
    //heap_insert 、heapify时间复杂度为O(logN)
    //因为N个结点的完全二叉树层数(高度)为logN
    void heap_insert(std::vector<int>& arr , int i){
        // 在i 位置插入一个数，向上调整，维护大根堆
        while(arr[i] > arr[(i - 1) / 2]){
            swap(arr[i] , arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapify(std::vector<int>& arr , int i , int size){
        //i位置的数发生变化，变小了
        //向下调整，维护大根堆

        int l = 2 * i + 1;//左孩子索引
        while(l < size){

			int best = ( l + 1 < size && arr[l + 1] > arr[l] ) ? l + 1 : l;
            
            best = arr[best] > arr[i] ? best : i;
            if(best == i)   break;

            swap(arr[best] , arr[i]);
            i = best;
            l = 2 * i + 1;  
        }
    }


    	// 从顶到底建立大根堆，O(n * logn)
        // 依次弹出堆内最大值并排好序，O(n * logn)
        // 整体时间复杂度O(n * logn)
        void heap_sort1(std::vector<int>& arr){
            int n = arr.size();

            for(int i = 0 ; i < n ; i++){
                heap_insert(arr , i);//从顶到底建立大根堆
            }

            while(n > 1){
                swap(arr[0] , arr[--n]);
                heapify(arr , 0 , n);
            }

        }


        // 从底到顶建立大根堆，O(n)
        // 依次弹出堆内最大值并排好序，O(n * logn)
        // 整体时间复杂度O(n * logn)

        void heap_sort2(std::vector<int>& arr){
            int n = arr.size();

            for(int i = n - 1 ; i >= 0 ; i--){
                heapify(arr , i , n);
            }

            while(n > 1){
                swap(arr[0] , arr[--n]);
                heapify(arr , 0 , n);
            }
        }
};




int main()
{
    // std::vector<int> arr = { 4 , 3 , 2 , 1 , 2 , 0 , 1};
    // arr[1] = 1;
    // heap H;
    // H.heapify(arr , 1 , 7);
    
}