#include <cmath>
#include "HashTable.hpp"
 
hashTable::hashTable(){
	_size = 0;
	_capacity = 3;//初始化hashtable容积为3
	_pTable = new Entry*[_capacity];
	for(int i=0; i<_capacity; i++)
		_pTable[i] = NULL;
	_primeN = 1;
}
 
hashTable::~hashTable()
{
	clear();
}
 
void hashTable::clear(){
	delete []_pTable;
	_size = 0;
	_capacity = 0;
}
 
int hashTable::nextPrime(){
	if(_primeN > 41)
		exit(-1);
	int prime = std::pow(_primeN*1.0,2) - _primeN + 41;//根据公式计算下一个大小
	_primeN = _primeN << 1;
	return prime;
}
 
int hashTable::hashFunction(const KeyType& key) {//一种简单的哈希函数 ,为了未来改进封装一下.
	return key%_capacity;
}
 
bool hashTable::find(const Entry& e){
	return find(e._key);
}
 
bool hashTable::find(const KeyType& key){
	_pos = hashFunction(key);
	if(_pTable[_pos]==NULL)
		return false;
	for(int i=0; i<=_capacity; i++){
		_pos = (_pos+i)%_capacity;//采用开放地址, 解决冲突,尝试_pos, _pos+1, _pos+2...
		if(_pTable[_pos]!=NULL && _pTable[_pos]->_key==key){
			return true;
		}
	}
		return false;
}
 
bool hashTable::insert(const Entry& e){
	if((_size*1.0)/_capacity > 0.7)//装载因子大于0.7，重新散列
		rehash();
	if(find(e))//如果e已经存在hashTable中，返回false
		return false;
	_pTable[_pos] = new Entry(e);//当前位置插入e
	_size++;//hashTable规模增1
	return true;
}
 
bool hashTable::remove(const Entry& e){
	if(find(e)){//e存在hashTable中，执行删除操作，hashTable规模减1
		delete _pTable[_pos];//回收内存
		_pTable[_pos]=NULL;//置空指针
		_size--;//hashTable规模减1
		return true;
	}
	return false;//否则返回false
}
 
Entry* hashTable::operator[](const KeyType& key){
	if(find(key))
		return _pTable[_pos];
	else
		return NULL;
}
 
void hashTable::rehash(){//重新散列
	Entry **pTableOld = new Entry*[_size];
	for(int i=0; i<_capacity; i++)//遍历hashTable，备份所有有效的元素
		if(_pTable[i] != NULL)
			pTableOld[i] = new Entry(*_pTable[i]);
	delete []_pTable;
	_capacity = nextPrime();//hashTable增容到下一个素数
	_pTable = new Entry*[_capacity];
	for(int i=0; i<_capacity; i++)
		_pTable[i] = NULL;
	int sizeOld = _size;
	_size = 0;
	for(int i=0; i<sizeOld; i++)//将之前所有的元素逐一插入
		insert(*pTableOld[i]);
}
 
void hashTable::display()
{
	cout << "capacity=" << _capacity <<",size="<<_size<<endl;
	for(int i=0; i<_capacity; i++)
		if(_pTable[i]!=NULL)
			cout<<"key="<<_pTable[i]->_key<<",value="<<_pTable[i]->_value<<endl;
}
