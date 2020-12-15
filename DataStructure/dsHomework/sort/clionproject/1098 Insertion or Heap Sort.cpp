//
// Created by 12638 on 2020/12/15.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>


using namespace std;
const int maxn=105;
int heap[maxn];
int heap_size=0;

void swaps(int &a,int &b){
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
}
void heap_down(int i){

}
void heap_pop(){

}

int main()
{
    int n,i;
    int num[maxn],num2[maxn];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&num2[i]);
    }
    int idx = 0;
    for(;idx < n-1 && num2[idx] <= num2[idx+1];idx++);
    int p  = idx+1;
    for(;p < n && num[p] ==   num2[p];p++);
    if(p == n){  // it is a insertion sort// we conduct a insertion
        sort(num2,num2+idx+2); //sort has first , don't contain second argument
        printf("Insertion Sort\n");
        cout << num2[0];
        for(i = 1;i < n;i++)
            cout << " "<< num2[i];
    }
    else{
        //heap_pop  swap(0, idx)
        //for(idx = n-1 ;idx > 0  && num2[idx] >= num2[idx-1];idx--); //we cannot find sorted region in this way
        //从n开始往前找，找第一个小于等于b[1]的数字b[p]
        for(idx = n-1 ;idx > 0  && num2[idx] >= num2[0];idx--); //idx is in the heap , after idx are sorted
        swaps(num2[0],num2[idx]);

        // we may need heap

        //  heap_down
    }
    return 0;
}