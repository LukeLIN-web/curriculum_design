#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX(a,b) (a>b)?a:b
	

void main(){
   	int n = 0, i = 0,j = 0, k = 0,tmp = 0;
   	int Nv, Ne ; 
	scanf("%d", &Nv);
	scanf("%d", &Ne);
	for(i = 0;i < Ne;i++) {  // the number of edges are Ne
		int a, b,w;
		scanf("%d%d%d", &a,&b,&w);
		G[a][b] = G[b][a] = w;
	}
	scanf("%d", &k );  // k is number of the  sequence query
	for(j = 0;j < k;j++) {
	    scanf("%d", &tmp ); 
	   
	}
	
	
	
}
