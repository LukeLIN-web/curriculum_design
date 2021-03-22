#include <stdio.h>
#include "lqueue.h"

/* 记录人物信息的结构 */
typedef struct {
	char name[20];
	char sex;   /* "M""F"分别表示男士和女士 */
}Person;

/* 对数组进行舞伴配对 */
void dance_partner(Person dancer[], int num) {
	ListEntry *malelist = NULL, *femalelist = NULL;
	Person *person;
	int i;
	/* 将数组中的人物信息加入队列 */
	for (i = 0; i <= num - 1; i++) {
		person = &dancer[i];
		if(dancer[i].sex == 'F')
			lqueue_push(&femalelist, person);	/* 女士加到队尾 */
		else
			lqueue_push(&malelist, person);	/* 男士加到队尾 */
	}
	printf("The dancing partner are: \n\n");
	/* 每次男女队头人物配对，输出名字并从队列移除，直到某一队为空 */
	while (!lqueue_is_empty(femalelist) && !lqueue_is_empty(malelist)) {
		person = lqueue_pop(&malelist); /* 队首男士离开队列 */
		printf("%s \t", person->name);
		person = lqueue_pop(&femalelist);   /* 队首女士离开队列 */
		printf("%s\n", person->name);
	}
    /* 输出剩下的队列中的人数以及队首人物名字 */
	if (!lqueue_is_empty(femalelist)) {
		printf("\nThere are %d women waiting for the next round.\n", lqueue_length(femalelist));
		person = lqueue_peek(femalelist);
		printf("%s will be the first to get a partner. ", person->name);
	}
	else if (!lqueue_is_empty(malelist)) {
		printf("\nThere are %d men waiting for the next round.\n", lqueue_length(malelist));
		person = lqueue_peek(malelist);
		printf("%s will be the first to get a partner.", person->name);
	}
}

int main(void){
	Person dancer[] = {{"Rose", 'F'}, {"Bill", 'M'}, {"James", 'M'}, {"Andy", 'M'}, 
						{"Mike", 'M'}, {"Jane", 'F'}, {"Jack", 'M'}, {"Amy", 'F'}};
	dance_partner(dancer, 8);
	return 0;
} 