// https://www.luogu.com.cn/problem/P1177
// acm风格

#include<iostream>
#define MAXN 100000

int arr[MAXN];
int help[MAXN];

void merge(int l , int mid , int r){
    
    int i = l , j = mid + 1;
    int k = l;
    while(i <= mid && j <= r){
        help[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    }

    while(i <= mid) help[k++] = arr[i++];
    while(j <= r)   help[k++] = arr[j++];

    for(int i = l ; i <= r ; i++){
        arr[i] = help[i]; 
    }
}
void merge_sort(int l , int r){
    if(l == r)  return;

    int mid = (l + r) >> 1;
    merge_sort(l , mid);
    merge_sort(mid + 1 , r);
    merge(l , mid , r);
}


int main()
{
    int N;
    std::cin >> N;
    for(int i = 0 ; i < N ; i++){
        scanf("%d" , &arr[i]);
    }

    merge_sort(0 , N-1);

    for(int i = 0 ; i < N ; i++){
        printf("%d " , arr[i]);
    }
    return 0;
}
