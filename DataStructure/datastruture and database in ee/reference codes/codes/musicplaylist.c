#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct _Music{
	int index;
	int freq;
} Music;

//列表排序的函数，最终获得按照频率排序的列表
void get_order(ListEntry *list, int index) {
	ListEntry *plist, *pmusic;
	Music *templ, *tempm;
	pmusic = list->next;
	
	while(pmusic != NULL) {	//获取data对应的music结构 
		tempm = pmusic->data;
		if(tempm->index == index)
			break;
		pmusic = pmusic->next;
	}
	if(pmusic == NULL) {
		printf("未找到对应结点\n");
		return;
	}
	plist = list->next;
	tempm = pmusic->data;
	tempm->freq++; 
	
	//开始查找播放频数正确的位置 
	while(plist != NULL) {
		templ = plist->data;
		if(templ->freq >= tempm->freq)	//从头开始向后查找，直到找到freq小于目标music的freq的内容 
			plist = plist->next;
		else {
			pmusic->prev->next = pmusic->next;	//解除其它结点到该节点的指针 
			if(pmusic->next != NULL) 
				pmusic->next->prev = pmusic->prev;	//如果pmusic已经指向最后一个结点，则无需此操作 
			
			plist->prev->next = pmusic;	//确立pmusic前一个结点为A 
			pmusic->prev = plist->prev;
			
			plist->prev = pmusic;	//确立pmusic和plist之间的指针 
			pmusic->next = plist;
			
			break;	//结束循环 
		} 
	}
}

//打印链表
void visit(ListEntry *list) {
	ListIterator *iter; //使用迭代器结构输出链表
	Music *node;
	iter = (ListIterator *)malloc(sizeof(ListIterator));
	list_iterate(&list->next, iter); 
	
	printf("遍历输出结果:\n");
	while(list_iter_has_more(iter)) {
		node = list_iter_next(iter);
		printf("index = %d, freq = %d\n", node->index, node->freq);
	}
}

//在列表尾部加入新的歌曲
ListEntry *add_song(ListEntry *dulist, int index, int freq) {
	Music *pmusic;
	pmusic = (Music *)malloc(sizeof(Music));
	pmusic->index = index;
	pmusic->freq = freq;
	return list_append(&dulist, pmusic);
}
//一个测试
int main(void) {
	ListEntry *dulist;  //有表头的双向链表
	dulist = (ListEntry *)malloc(sizeof(ListEntry));
    dulist->next = NULL;
    dulist->prev = NULL;
    //加入对象
	add_song(dulist, 0, 0);	
	add_song(dulist, 1, 0);	
	add_song(dulist, 2, 0);
	add_song(dulist, 3, 0);
	//执行排序
	get_order(dulist, 1);
	get_order(dulist, 1);
	get_order(dulist, 2);
	get_order(dulist, 2);
	get_order(dulist, 2);
	visit(dulist);  // 输出双向链表
	return 0;
}
