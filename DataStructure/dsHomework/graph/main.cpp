#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<queue>
using namespace std;
/*
本题是PAT上顶级1003，考察的知识点其实只有一个，最大流问题。
用基于广度优先搜索的Edmonds-Karp算法求解。题目意思就是说求解最多能从地球站发送出去的最大人数，
在到达目的星球（MAR）上途径每一个行星（不包括MAR）上都没有收留多余游客的能力，到达的游客必须运送出去。
那么可以将EAR视为源点s，MAR视为汇点，是一个单源点单汇点的最大流问题
*/
unordered_map<string,int>trans;//将字符串转换为数字，由0开始编号
vector<Edge>edges;//储存边
vector<int>graph[1005];//整个图，其中graph[i][j]表示结点i的第j条边在edges数组中的序号




/*插入边，起点为from，终点是to，容量为cap ,
首先找找这个边在不在无序map, 如果不在 ,那就insert一个 , 通过tran的size,就可以获得他的大小
利用构造函数, 在edges中创建边.  同时在 图中插入边,以及初始化一个反向边.
*/
void insertEdge(string&from,string&to,int cap){//插入边，起点为from，终点是to，容量为cap

}
/*
1. 首先把所有残余网络初始化为0,广度优先遍历查找从源点到达汇点的增广路
然后定义一个数组 a,a[i]代表从源点到i的最大流通量，即每次源点开始搜索，
最后的a[n]就是从源点到汇点的最大流通量，
2.遍历x节点的每一条边.如果当前边的终点的残量为0且容量大于流量,
那么更新最短路树上到达结点p[i]的边在edges数组中的序号, p中记录终点 graph中的序号
 更新源点到该终点的残量
 3.

在每一次搜索完成之后，如果a[n]==0，说明已经没有剩余可以流通的量了，直接return
 */
int MaxFlow(int s,int t){//最大流算法,s为源点,
    return 0 ;
}
int main(){
    string from,to;
    int n,cap;
    cin>>from>>to;
    cin>>n;
    trans[from]=0;
    trans[to]=1;
    while(n--){
        cin>>from>>to>>cap;// use cin >>string will error in clion because I use include<string.h>,change to <string> can solve it
        insertEdge(from,to,cap);
    }
    printf("%d",MaxFlow(0,1));
    return 0;
}

