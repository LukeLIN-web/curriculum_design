//
// Created by 12638 on 2020/12/26.
// the longest computation task you could run,
// and find the total amount of valid starting time for a given computation task
/*
 * first line is analysis the server and calculate the longest time ,  then analysis each query.
 * the key point is that how can we sort by hours.
 * first sort each server,  the sort each server begin point.
 *  首先把每个服务器排好,根据时 ,然后分, 然后秒 ,然后  再把服务器开始的时间排好. 你要找最长,那就先看开始的时间,
 */
#include<string>
#include<iostream>
#include<vector>
#include <map>
#include <algorithm>

#define SEC_PER_MIN 60
using namespace std;
class time{
    int hours;
    int minutes;
    int seconds;
};
int main(){
    int sec,min,hours,left;
    int N,K,i;
    cin >> N >> K;
    string tempS;
    map<string,std::vector<int>> m1;
    char dev;
    for(i = 0;i < N;i++){ // input all the time point
        cin >>  tempS; //end when meet space
        cin >> hours;
        cin >> dev; // enter ':'
        cin >> min;
        cin >> dev;
        cin >> sec;
        std::vector<int> tmpV;
        tmpV.clear();
        tmpV.push_back(hours*3600+min*60+sec);
        if(m1.empty()){ // if don't have any server, add directly,
          //mapPerson.insert(pair < int,string > (1,"Jim"));
            m1.insert(make_pair("Anna",tmpV));
        }
        //else compare.
        else{ // find the map server then put the time into
            if(m1.find(tempS) == m1.end()){// returns an iterator to it if found, otherwise it returns an iterator to map::end.
                m1.insert(make_pair("Anna",tmpV));
            }
            else{
               m1.find(tempS)->second.push_back(hours*3600+min*60+sec);// finally we will sort vector
            }
        }
    }
    for(auto it : m1){ // we can use iterator
        cout << it.first <<" " <<endl;//sort default from small to big
        sort(it.second.begin(),it.second.end());//sort方法实际上最后一位地址对应的数是不取的，
        // vector，set，map这些容器的end()取出来的值实际上并不是最后一个值
    }

    min=sec/SEC_PER_MIN;
    hours= sec/ SEC_PER_MIN;
    left=sec%SEC_PER_MIN;
    printf("%d,%d,%d\n",sec,min,left);
    scanf("%d",&sec);
    return 0;
}

