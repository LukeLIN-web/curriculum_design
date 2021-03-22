/* 舞伴问题：
	假设在周末舞会上，男士们和女士们进入舞厅时，各自排成一队。跳舞开始时，依次从男队和女队的队头上各出一人配成舞伴。
若两队初始人数不相同，则较长的那一队中未配对者等待下一轮舞曲。

	在算法中，假设男士和女士的记录存放在一个数组中作为输入，然后依次扫描该数组的各元素，并根据性别来决定是进入男队
还是女队。当这两个队列构造完成之后，依次将两队当前的队头元素出队来配成舞伴，直至某队列变空为止。此时，若某队仍有等
待配对者，算法输出此队列中等待者的人数及排在队头的等待者的名字，他（或她）将是下一轮舞曲开始时第一个可获得舞伴的人。
 */

/* 使用arraylist解决舞伴问题 */
#include<stdio.h>
#include "arraylist.h"

/* 存储人物信息的结构 */
typedef struct {
	char name[20]; 
	char sex;	/* "M"表示男士，"F"表示女士 */
}Person;

/* 对数组进行舞伴配对 */
void dance_partner(Person dancer[], int num){
	ArrayList *malelist, *femalelist;
	Person *person = dnacer;
	malelist = arraylist_new(5);	/* 男士队列初始化 */
	femalelist = arraylist_new(5);	/* 女士队列初始化 */
	int i;
	
	/* 将数组中的人物信息加入队列 */
	for (i = 0; i <= num - 1; i++) {
		if (dancer[i].sex == 'F') {
			person = &dancer[i];
			arraylist_append(femalelist, person);   /* 女士加到队尾 */
		} else {
			person = &dancer[i];
			arraylist_append(malelist, person);     /* 男士加到队尾 */
		}
	}
	
	/* 将男女配对后输出 */
	printf("The dancing partner are: \n\n");
	/* 每次男女队头人物配对，输出名字并从队列移除，直到某一队为空 */
	while (femalelist->length != 0 && malelist->length != 0) {
	    person = femalelist->data[0];
		printf("%s \t", person->name);
		arraylist_remove(femalelist, 0);	/* 女士输出后从队列移除 */
		person = malelist->data[0];
		printf("%s\n", person->name);
		arraylist_remove(malelist, 0);	/* 男士输出后从队列移除 */
	}
	
	/* 输出剩下队列中的人数以及队首人物名字 */
	if (femalelist->length != 0) {
		printf("\nThere are %d women waiting for the next round.\n", femalelist->length);
		person = femalelist->data[0];	/* 取队首 */
		printf("%s will be the first to get a partner. ", person->name);    /* 输出队首人物的名字 */
	}

	else if (malelist->length != 0) {
		printf("\nThere are %d men waiting for the next round.\n", malelist->length);
		person = malelist->data[0];	/* 取队首 */
		printf("%s will be the first to get a partner. ", person->name);    /* 输出队首人物的名字 */
	}
}

/* 测试 */
int main(void){
	Person dancer[] = {{"Rose", 'F'}, {"Bill", 'M'}, {"James", 'M'}, {"Andy", 'M'}, 
						{"Mike", 'M'}, {"Jane", 'F'}, {"Jack", 'M'}, {"Amy", 'F'}};
	dance_partner(dancer, 8);
}