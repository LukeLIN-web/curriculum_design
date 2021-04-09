#include <iostream>
#include <string>
#include <vector>
#include "HashTable.cpp"
#include <windows.h>
#include<ctime>
#pragma comment(lib,"winmm.lib")
using namespace std;



int main(){
	//DWORD start, end;
	time_t begin;
	time_t end;
    double ret;
    begin = clock();
	hashTable *pTable = new hashTable;
pTable->insert(Entry(1,11));
pTable->insert(Entry(2,22));
pTable->insert(Entry(3,33));
pTable->insert(Entry(4,44));
pTable->insert(Entry(5,55));
pTable->insert(Entry(6,66));
pTable->insert(Entry(7,77));
pTable->insert(Entry(8,88));
pTable->insert(Entry(9,99));
pTable->insert(Entry(10,110));
pTable->insert(Entry(11,121));
pTable->insert(Entry(12,132));
pTable->insert(Entry(13,143));
pTable->insert(Entry(14,154));
pTable->insert(Entry(15,165));
pTable->insert(Entry(16,176));
pTable->insert(Entry(17,187));
pTable->insert(Entry(18,198));
pTable->insert(Entry(19,209));
pTable->insert(Entry(20,220));
pTable->insert(Entry(21,231));
pTable->insert(Entry(22,242));
pTable->insert(Entry(23,253));
pTable->insert(Entry(24,264));
pTable->insert(Entry(25,275));
pTable->insert(Entry(26,286));
pTable->insert(Entry(27,297));
pTable->insert(Entry(28,308));
//pTable->insert(Entry(29,319));
//pTable->insert(Entry(30,330));
//pTable->insert(Entry(31,341));
//pTable->insert(Entry(32,352));
//pTable->insert(Entry(33,363));
//pTable->insert(Entry(34,374));
//pTable->insert(Entry(35,385));
//pTable->insert(Entry(36,396));
//pTable->insert(Entry(37,407));
//pTable->insert(Entry(38,418));
//pTable->insert(Entry(39,429));
//pTable->insert(Entry(40,440));
//pTable->insert(Entry(41,451));
//pTable->insert(Entry(42,462));
//pTable->insert(Entry(43,473));
//pTable->insert(Entry(44,484));
//pTable->insert(Entry(45,495));
//pTable->insert(Entry(46,506));
//pTable->insert(Entry(47,517));
//pTable->insert(Entry(48,528));
//pTable->insert(Entry(49,539));
//pTable->insert(Entry(50,550));
//pTable->insert(Entry(51,561));
//pTable->insert(Entry(52,572));
//pTable->insert(Entry(53,583));
//pTable->insert(Entry(54,594));
//pTable->insert(Entry(55,605));
//pTable->insert(Entry(56,616));
//pTable->insert(Entry(57,627));
//pTable->insert(Entry(58,638));
//pTable->insert(Entry(59,649));
//pTable->insert(Entry(60,660));
//pTable->insert(Entry(61,671));
//pTable->insert(Entry(62,682));
//pTable->insert(Entry(63,693));
//pTable->insert(Entry(64,704));
//pTable->insert(Entry(65,715));
//pTable->insert(Entry(66,726));
//pTable->insert(Entry(67,737));
//pTable->insert(Entry(68,748));
//pTable->insert(Entry(69,759));
//pTable->insert(Entry(70,770));
//pTable->insert(Entry(71,781));
//pTable->insert(Entry(72,792));
//pTable->insert(Entry(73,803));
//pTable->insert(Entry(74,814));
//pTable->insert(Entry(75,825));
//pTable->insert(Entry(76,836));
//pTable->insert(Entry(77,847));
//pTable->insert(Entry(78,858));
//pTable->insert(Entry(79,869));
//pTable->insert(Entry(80,880));
//pTable->insert(Entry(81,891));
//pTable->insert(Entry(82,902));
//pTable->insert(Entry(83,913));
//pTable->insert(Entry(84,924));
//pTable->insert(Entry(85,935));
//pTable->insert(Entry(86,946));
//pTable->insert(Entry(87,957));
//pTable->insert(Entry(88,968));
//pTable->insert(Entry(89,979));
//pTable->insert(Entry(90,990));
//pTable->insert(Entry(91,1001));
//pTable->insert(Entry(92,1012));
//pTable->insert(Entry(93,1023));
//pTable->insert(Entry(94,1034));
//pTable->insert(Entry(95,1045));
//pTable->insert(Entry(96,1056));
//pTable->insert(Entry(97,1067));
//pTable->insert(Entry(98,1078));
//pTable->insert(Entry(99,1089));
    end=clock();
    ret=double(end-begin)/CLOCKS_PER_SEC;
    cout<<"runtime:   "<<ret<<endl;
	pTable->display();
	delete pTable;
	getchar();//鍋滀笅鏉ョ瓑寰?
	return 0;
}
