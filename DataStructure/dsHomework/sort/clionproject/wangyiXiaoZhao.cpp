//
// Created by 12638 on 2021/3/27.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> hui ;

int main(){
    string start,end;
    cin >> start;
    cin >>end;
//    int end = 0;
//    for(){
//        end = end + atoi(it);
//    }
//    for( int i = 0 ; i < sqrt(double(end)) end; )

    return 0 ;
}

bool huiwen(string str){
    if(str.empty()) return 0;
    int slow = 0,fast = str.length();
    //if first = last
    while(slow <= fast){
        cout << str[fast];
        if(str[slow] == str[fast]){
            slow++;
            fast --;
        }
        else{
            return false;
        }
    }
    return true;
}
