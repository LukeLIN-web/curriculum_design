//
// Created by 12638 on 2021/3/19.
//
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main(){
    int n, tmp;
    cin >> n;
    vector<int> a ;
    for(int i = 0 ; i < n ; i ++){
        cin >> tmp;
        a.push_back(tmp);
    }
    int k = 0;
    for(int i = 0; i < n ; i ++){
        int sq = sqrt()
    };



    return 0 ;
}
int main() {
    int n, tmp;
    cin >> n;
    vector<int> a ;
    vector<int> b ;
    for(int i = 0 ; i < n ; i ++){
        cin >> tmp;
        a.push_back(tmp);
    }
    for(int i = 0 ; i < n ; i ++){
        cin >> tmp;
        b.push_back(tmp);
    }
    if(n <= 2) {
        cout << -1;
        return 0;
    }
    int i  = 0, j, k ;
    int min = 3000000;//选最小
    bool flag = false;
    // 快慢指针
    while(i < n){
        j = i + 1;
        while(j < n && a[i] > a[j] ) j++;
        while(j < n){
            if(a[i] < a[j]) {
                k = j + 1;
                while (k < n && a[j] > a[k]) k++;
                while (k < n) {
                    if(a[j] < a[k]) {
                        if (b[i] + b[j] + b[k] < min) {
                            min = b[i] + b[j] + b[k];
                            flag = true;
                        }
                    }
                    k++;
                    while (k < n && a[j] > a[k]) k++;
                }
            }
            j++;
            while(j < n && a[i] > a[j] ) j++;
        }
        i++;
        if(flag){
            while(i < n && b[i] > b[i-1] ) i++; // i saved, bigger than j can not
        }
        flag = false;
    }
    if(min != 3000000)
        cout << min ;
    else
        cout << -1;
    return 0;
}