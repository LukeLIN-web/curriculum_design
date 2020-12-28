//
// Created by 12638 on 2020/12/26.
// the longest computation task you could run,
// and find the total amount of valid starting time for a given computation task
/*
 * first line is analysis the server and calculate the longest time ,  then analysis each query.
 * the key point is that how can we sort by hours.
 * first sort each server,  the sort each server begin point.
 *  maxtime
Just traverse, the first one, the first a end, if there's another b, then temptime = bstat-astat
And then cycle the next one as well.
If not, then maxtime = aend-astat;
Recycling b. The algorithm should be nlogn's
 */
#include<string>
#include<iostream>
#include <utility>
#include<vector>
#include <map>
#include <algorithm>
#include <set>

#define SEC_PER_MIN 60
using namespace std;
class time{
public:
    time(int h,int m,int s); // have three para
    int hours;
    int minutes;
    int seconds;
};
time::time(int h, int m, int s):hours(h),minutes(m),seconds(s) {} // constructor
//define smaller a earlier, return 1. b earlier, return 0;
bool comp(const time &a, const time &b){
    if (a.hours >= b.hours){            // bigger is later.
        if (a.hours > b.hours) {
            return false;
        }//else if(a.hours == b.hours)
        else if (a.minutes < b.minutes) {
            return true;
        } else if (a.minutes > b.minutes) {
            return false;
        }// else if(a.minutes == b.minutes)
        else return a.seconds < b.seconds;
    } else return true;
}
int timeSub(const time &a, const time &b){   // a should later than  b
    return (a.hours-b.hours)*3600+(a.minutes-b.minutes)*60+(a.seconds-b.seconds);
}
class server{  //every pair
public:
    server(time start,time end,string name);
    time start;
    time end;
    string name;
    bool operator< (const server &b) const {  // sort by the starting time point ascending
        return comp(this->start, b.start); // true is earlier,  false;
    }
};
server::server(time start, time end, string name):start(start),end(end),name(std::move(name)) {} //init list

int main(){
    int sec,min,hours,left;
    int N,K,i;
    cin >> N >> K;
    string tempS;
    map<string,std::vector<time>> m1;
    char dev;
    for(i = 0;i < N;i++){ // input all the time point
        cin >>  tempS; //end when meet space
        cin >> hours;cin >> dev; // enter ':'
        cin >> min;cin >> dev; cin >> sec;
        std::vector<time> tmpV;
        time t1(hours,min,sec) ;// call the constructor to init the t1
        tmpV.clear();
        tmpV.push_back(t1);//record the hour, minute and seconds
        if(m1.empty()){ // if don't have any server, add directly,
            m1.insert(make_pair(tempS,tmpV)); //mapPerson.insert(pair < int,string > (1,"Jim"));
        }
        //else compare.
        else{ // find the map server then put the time into
            if(m1.find(tempS) == m1.end()){// returns an iterator to it if found,otherwise it returns an iterator to map::end.
                m1.insert(make_pair(tempS,tmpV));
            }
            else{
               m1.find(tempS)->second.push_back(t1);// finally we will sort vector
            }
        }
    }
    // it is difficult to change the vector in the map
    map<string,std::vector<time>>::iterator mapIt ;// define iterator as a global variable for change data
    std::vector<time> * vt;//pointer for change data
    for(mapIt = m1.begin();mapIt != m1.end();mapIt++)
    {
        vt = & mapIt->second;
        sort(vt->begin(),vt->end(),comp);//define a customer compare rule
    }
    // sort finished
 // we can use iterator,notice we need change value so don't use const iterator
 // sort default from small to big , sort finished in 12.28 23:26, we can
//        sort(vt->begin(),vt->end(),comp);//define a customer compare rule
//        // sort method actually does not take the number corresponding to the last address.
//        // vector，set，map,The values taken out by the end() of these containers are not actually the last values
    for(auto it : m1){
        vector<time>vt = it.second;
        for (auto & it2 : vt){
            cout << "hours: " << it2.hours << " min: " << it2.minutes << endl;
        } //sort(it.second.begin(),it.second.end());
    }
    // output the longest.
    //first we write down the beginning time of each server .
    // how to deal with switch from different servers?
    set<server> ser1;// store all the time block, each server has <start,end>
    for(auto it : m1){// move all into set. they will be sorted automatically.
        int count = it.second.size();
        for (int i = 0; i+1 < count;i += 2){
            cout << "hour: " << it.second[i].hours << " min: " << it.second[i].minutes << endl;// for debug
            ser1.insert(server(it.second[i], it.second[i + 1], it.first) );// insert into set
        }
    }
    //In fact, there is no need to distinguish between servers in the set, we can save first
    auto it = ser1.begin(); // traverse the set.
    auto itNext = std::next(it);// find next the beginning time .
    int tempT = 0;// tempT store current length of time.
    int maxT = 0;
    while (comp(itNext->start, it->end) && itNext != ser1.end() ) {  // if there is a block "itNext" start before the "it" end,
            tempT += timeSub(itNext->start, it->start);//tempT =
            it++;
            itNext = std::next(it);
        cout << "hour: " << it->start.hours << " min: " << it->start.minutes << endl;
    }// if don't have any block can continue
    tempT += timeSub(it->start, it->end);
    maxT = tempT;
    printf("%d\n",maxT);// the longest computation task you could run
    for(i = 0;i < K;i++ ){  // input the queries
        cin >> hours;
        cin >> dev; // enter ':'
        cin >> min;
        cin >> dev;
        cin >> sec;
        // todo: process the judgement
    }
    return 0;
}

