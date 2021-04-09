#include <iostream>
#include <string>
#include <vector>
#include "HashTable.cpp"
#include <windows.h>
#include<ctime>
#pragma comment(lib,"winmm.lib")
using namespace std;
 
int main()
{
	time_t begin;
	time_t end;
    double ret;
    begin = clock();
	hashTable *pTable = new hashTable;
	cout << "insert Entry(1,11)..." << endl;
	pTable->insert(Entry(1,11));
	pTable->display();
	cout << "insert Entry(2,22)..." << endl;
	pTable->insert(Entry(2,22));
	pTable->display();
	cout << "insert Entry(3,33)..." << endl;
	pTable->insert(Entry(3,33));
	pTable->display();
	cout << "insert Entry(4,44)..." << endl;
	pTable->insert(Entry(4,44));
	(*pTable)[1]->_value = 101;//下标操作，返回值充当左值
	pTable->display();
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
pTable->insert(Entry(25,275));
pTable->insert(Entry(26,286));
pTable->insert(Entry(27,297));
pTable->insert(Entry(28,308));

	end=clock();
    ret=double(end-begin)/CLOCKS_PER_SEC;
    cout<<"runtime:   "<<ret<<endl;
	cout << endl << "delete Entry(1,11)..." << endl;
	pTable->remove(Entry(1,11));
	pTable->display();
	cout << "delete Entry(2,22)..." << endl;
	pTable->remove(Entry(2,22));
	pTable->display();
	cout << "delete Entry(3,33)..." << endl;
	pTable->remove(Entry(3,33));
	pTable->display();
 
	cout << "delete Entry(3,33)..." << endl;
	pTable->remove(Entry(3,33));
	pTable->display();

	delete pTable;
	getchar();
	return 0;
}
