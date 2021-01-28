#include<stdio.h>

int main(){
	int i ,j;
	int n = 20;
	int number[20] = {99, 21, 11,3, 2,
		4 ,25,	12, 4 ,2 ,
		35,30, 7,	2, 4 ,
		2,13, 4 ,2 ,-1};
	int temp;
	for (i=n-1;i > 0;i--)
			{
				for (j = 1 ;j <= i ;j++)
				{
					if(number[j] <= number[j-1]){   // 从小到大排序  ,每一次放一个最大的在i处. 
						temp = 	number[j] ;
						number[j]  = number[j-1] ;
						number[j-1] = temp ; 
					}
				}
			}
	for (i = 0; i<20; i++)
		printf("%d ", number[i]);
}


