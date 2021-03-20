//
// Created by 12638 on 2021/3/19.
//
#include <iostream>
#include <vector>
using namespace std;
//int main(){
//
//
//
//    return 0 ;
//}
int main(){
    vector<vector<bool>> mat;
    char c;
    int i  = 0 , j = 0  ;
    vector<bool> vt;
    ; // 到底怎么样算读完了???? 救命
    c = getchar();
    int size;
    while(c != '\n') {
        if (c == '1') {
            vt.push_back(true);
        }
        if (c == '0') {
            vt.push_back(false);
        }
        if(c == ';') {
            mat.push_back(vt);
            vt.clear();
        }
        c = getchar();
    }
    mat.push_back(vt);// 获得mat


    return 0 ;
}



//class people{
//public:
//    long arriveTime;
//    long payDuration;
//    long fin;
//};

//int main(){
//    int n;
//    vector<people> a ;
//    char tmp;
//    cin >> n ; // n 个人
//    people first{};
//    cin >> first.arriveTime;
//    cin >> tmp;
//    cin >> first.payDuration;
//    first.fin = first.payDuration + first.arriveTime;//这里会跑飞, 为什么呢?
//    a.push_back(first);
//    for(int i = 1 ; i < n ; i ++ ){
//        people p{};
//        cin >> p.arriveTime;
//        cin >> tmp;
//        int j;
//        cin >> j ;
//         p.payDuration = j ;
//        if(p.arriveTime  < a[i-1].fin ){
//            p.fin = a[i-1].fin + p.payDuration;
//        }
//        else{
//            p.fin = p.arriveTime + p.payDuration;
//        }
//        a.push_back(p);
//    }
//    long sum = 0 ;
//    for(int i = 0 ; i < n ; i ++ ) {
//        sum += a[i].fin - a[i].arriveTime;
//    }
//    cout << sum;
//    return 0 ;
//}
//int main() {
//    int n, tmp;
//    cin >> n;
//    vector<int> a ;
//    vector<int> b ;
//    for(int i = 0 ; i < n ; i ++){
//        cin >> tmp;
//        a.push_back(tmp);
//    }
//    for(int i = 0 ; i < n ; i ++){
//        cin >> tmp;
//        b.push_back(tmp);
//    }
//    if(n <= 2) {
//        cout << -1;
//        return 0;
//    }
//    int i  = 0, j, k ;
//    int min = 3000000;//选最小
//    bool flag = false;
//    // 快慢指针
//    while(i < n){
//        j = i + 1;
//        while(j < n && a[i] > a[j] ) j++;
//        while(j < n){
//            if(a[i] < a[j]) {
//                k = j + 1;
//                while (k < n && a[j] > a[k]) k++;
//                while (k < n) {
//                    if(a[j] < a[k]) {
//                        if (b[i] + b[j] + b[k] < min) {
//                            min = b[i] + b[j] + b[k];
//                            flag = true;
//                        }
//                    }
//                    k++;
//                    while (k < n && a[j] > a[k]) k++;
//                }
//            }
//            j++;
//            while(j < n && a[i] > a[j] ) j++;
//        }
//        i++;
//        if(flag){
//            while(i < n && b[i] > b[i-1] ) i++; // i saved, bigger than j can not
//        }
//        flag = false;
//    }
//    if(min != 3000000)
//        cout << min ;
//    else
//        cout << -1;
//    return 0;
//}