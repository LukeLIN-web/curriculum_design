#include <iostream>
#include <string>
#include <vector>
#include "HashTable.cpp"
using namespace std;
 
int main()
{
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
