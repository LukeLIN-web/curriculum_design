
 
typedef struct Node{
	int coef;//系数 
	int exp;//指数 
	struct Node *next;
} *List;



List read(List L);
void print(List L);
// gain the sum of two polynomial
List getSum(List L1,List L2);
// gain the mutiplication of two polynomial
List getMuti(List L1,List L2);






