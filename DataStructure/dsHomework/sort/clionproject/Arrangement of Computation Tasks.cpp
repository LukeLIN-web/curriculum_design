//
// Created by 12638 on 2020/12/26.
// the longest computation task you could run,
// and find the total amount of valid starting time for a given computation task
/*
 * first line is analysis the server and calculate the longest time ,  then analysis each query.
 * the key point is that how can we sort by hours.
 * first sort each server,  the sort each server begin point.
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
    int hours;int minutes;int seconds;
};
time::time(int h, int m, int s):hours(h),minutes(m),seconds(s) {} // constructor
//define smaller a earlier, return 1. b  earlier, return 0;
bool comp(const time &a, const time &b){  // equal time will return true, We judge it earlier so we can link them.
    if (a.hours > b.hours)
        return false;               // bigger is later.
    else  if (a.hours < b.hours) {
            return true;
        }
    else{            //else if(a.hours == b.hours)
        if(a.minutes < b.minutes) {
            return true;
        } else if(a.minutes >b.minutes ){
            return false;
        }
        else{
            if (a.seconds >= b.seconds) {
                return false;// same time return false. such as sample 13:00:00
            }else  return true;
        }
    }
}
int timeSub(const time &a, const time &b){   // a should later than  b
    return (a.hours-b.hours)*SEC_PER_MIN*SEC_PER_MIN+(a.minutes-b.minutes)*SEC_PER_MIN+(a.seconds-b.seconds);
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

int main() {
    int sec, min, hours, N, K, i;
    cin >> N >> K;
    string tempS;
    map<string, std::vector<time>> m1;
    char dev;
    for (i = 0; i < N; i++) { // input all the time point
        cin >> tempS;cin >> hours;cin >> dev; //end when meet space
        cin >> min;cin >> dev;cin >> sec;// enter ':'
        std::vector<time> tmpV;
        time t1(hours, min, sec);// call the constructor to init the t1
        tmpV.clear();
        tmpV.push_back(t1);//record the hour, minute and seconds
        if (m1.empty()) { // if don't have any server, add directly,
            m1.insert(make_pair(tempS, tmpV)); //mapPerson.insert(pair < int,string > (1,"Jim"));
        }
            //else compare.
        else { // find the map server then put the time into
            if (m1.find(tempS) ==
                m1.end()) {// returns an iterator to it if found,otherwise it returns an iterator to map::end.
                m1.insert(make_pair(tempS, tmpV));
            } else {
                m1.find(tempS)->second.push_back(t1);// finally we will sort vector
            }
        }
    }// it is difficult to change the vector in the map
    map<string, std::vector<time>>::iterator mapIt;// define iterator as a global variable for change data
    std::vector<time> *vt;//pointer for change data
    for (mapIt = m1.begin(); mapIt != m1.end(); mapIt++) {
        vt = &mapIt->second;
        sort(vt->begin(), vt->end(), comp);//define a customer compare rule
    }// sort finished, we can use iterator,notice we need change value so don't use const iterator
    // sort default from small to big , sort finished in 12.28 23:26, we can
//    for(auto it : m1){
//        vector<time>vt = it.second;
//        for (auto & it2 : vt){
//            cout << "hours: " << it2.hours << " min: " << it2.minutes << endl;
//        } //for debug
//    }// before there, is all  correct  10:58 12/30

    //first we write down the beginning time of each server .
    set<server> ser1;// store all the time block, each server has <start,end>
    for (auto it : m1) {// move all into set. they will be sorted automatically.
        int count = it.second.size();// the number of one server's all time point
        for (int i = 0; i + 1 < count; i += 2) {
            cout << "hour: " << it.second[i].hours << " min: " << it.second[i].minutes << endl;// for debug
            ser1.insert(server(it.second[i], it.second[i + 1], it.first));// insert into set
        }
    }// before there, is all  correct  10:59 12/30
    //In fact, there is no need to distinguish between servers in the set, we now save , may delete it in the future
    // output each query results
    auto it = ser1.begin(); // traverse the set.
    auto itNext = std::next(it);// find next the beginning time .
    vector<int> block;
    it = ser1.begin(); // traverse the set.
    itNext = std::next(it);// find next the beginning time .
    while (itNext != ser1.end()) { // traverse all block
        int qTmp = 0;// query tmp store current length of time.
        while (itNext != ser1.end() &&
               comp(itNext->start, it->end)) {  // if there is a block "itNext" start before the "it" end,
            while (itNext != ser1.end() && comp(itNext->end, it->end)) { // itNext end before it end,  cannot ignore
                  // can process the query
                    block.push_back( timeSub(itNext->end, itNext->start) );// the total number of valid time points for starting the task.
                // add then jump out the itNext
                itNext++; //traverse all "it contains "
            }
            // have processed all "it contains ".
            if (itNext != ser1.end() && comp(itNext->start, it->end)) {   // itNext can link after the it 这一段连起来的算完.
                qTmp += timeSub(itNext->start, it->start);//tempT
                it = itNext;
                itNext = std::next(it);
            }
            cout << "hour: " << it->start.hours << " min: " << it->start.minutes << endl;
            cout << "itNext->start next hour: " << itNext->start.hours << " min: " << itNext->start.minutes << endl;
        }// if don't have any block can continue
        qTmp += timeSub(it->end, it->start);// finished the link
        block.push_back(qTmp);// push the link block
        it = itNext; itNext++;// continue traverse
    }//
    sort(block.begin(),block.end());
    printf("%d\n", block.back());//output the the longest computation task you could run
    // the index of vector , then we compare them with query  the length of one link
    for(i = 0;i < K;i++ ){  // input the queries
        cin >> hours;cin >> dev; // enter ':'
        cin >> min;cin >> dev;cin >> sec;// enter ':'
        int QueryL = timeSub(time(hours,min,sec),time(0,0,0));
        int total = 0;
        for(int i : block){
            if(QueryL < i)
                total += i- QueryL+1;
        }
        printf("%d\n",total);
    }
    return 0;
}

