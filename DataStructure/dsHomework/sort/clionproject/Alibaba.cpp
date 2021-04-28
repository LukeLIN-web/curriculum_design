//
// Created by 12638 on 2021/4/27.
//
#include <queue>
#include <deque>
#include <iostream>
using namespace std;

int main(){
    deque<char> dq;
    int time = 100;
    char ball = 'A';
    for(int i = 1 ; i < time ; i ++){  //模拟跑100秒
        for(int j = 0; j < 10 ; j ++){
            dq.emplace_back(ball);
            if(ball == 'Z')
                ball = 'A';
            else
                ball++;
            //cout << ball << endl;
        }
        if( i%2 == 0 ){
            for(int j = 0; j < 5 ; j ++){
                dq.pop_front();
            }
        }
    }
    return 0;
}
