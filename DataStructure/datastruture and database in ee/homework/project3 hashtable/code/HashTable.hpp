#pragma once
#include <iostream>
using namespace std;
 
typedef int KeyType;
struct Entry{
	KeyType _key;
	int _value;
	Entry(KeyType k=0, int v=0):_key(k),_value(v){}
};// 定义键值对
 
class hashTable{
public:
	hashTable();
	~hashTable();
 
	void clear();//清除hashTable所有元素
	bool find(const Entry& e);//true：成功；false:失败
	bool insert(const Entry& e);//true：成功；false:失败
	bool remove(const Entry& e);//true：成功；false:失败
	Entry* operator[](const KeyType& key);//若不存在键值为key的元素，则返回NULL
	void display();//逐条打印hashTable信息
protected:
	int hashFunction(const KeyType& key);//示例采用简单的映射关系，返回(key%_capacity)
	bool find(const KeyType& key);//按键值访问
	void rehash();//当载荷因子(_size/_capacity)大于0.7时，重新散列
	int nextPrime();//p=n^2-n+41, n<41
	int _primeN;//代表上面公式的n,在rehash中会逐渐变大
private:
	Entry **_pTable;// 保存每个key入口
	int _size;//哈希表中元素的个数
	int _capacity;//哈希表的容量
	int _pos;//当前访问的元素位置
};