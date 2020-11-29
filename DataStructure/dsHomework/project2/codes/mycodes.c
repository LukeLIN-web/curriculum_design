#include<stdio.h>


//Dijkstra ÿ����Ŀǰ��ԭ������ĵ㣬���м���������ͬ�Ļ�ȡ����һ��������ʵ�ȼ�����⼸����Ҳ�� 
// distance save the distance from the node to root;
const int INF = 0x3fffffff;
int Nv, G[1010][1010], distance[1010], query[1010];
int Dijkstra(int root){
    int i,min = INF, j,tmp;
    for(i = 0;i< 1010;i++){
    	distance[i] = INF;
	}
	int log[1010] = {0};
	distance[root] = 0; 
	printf("init finished \n");
	for(i = 0; i < Nv; i++){
		min = INF;
		printf("begin find min \n");
		for(j = 1;j <= Nv;j++){
			if(log[j] != 0 && distance[j] < min){
				min = distance[j];
				printf("%d\n",min);
			}
		}
		printf("search min finished\n");//�����ѯ�Ľڵ�query[i]��ԭ��ľ�����min
		printf("min = %d j = %d Nv = %d query[0] = %d\n",min,j,Nv,query[i]);
		// Nv  =5 is correct, query[0] = 5  is correct ,
		if(distance [query[i]]  == min ){
			tmp = query[i] ; 
			printf("%d\n",tmp);
		}
		else{
			return 0; //�� query ����Ҫ��� Dijkstra sequence������ false
		}
		//�����ڽӵ��ԭ��ľ���
		if(!log[tmp]){
			log[tmp] = 1 ;
		}
		printf("begin update distance\n");
		for(j = 1 ; j < Nv+1;j++){
			if( log[j] != 0   &&  G[tmp][j] && distance[j] > distance[tmp] + G[tmp][j]    ){
				distance[j] = distance[tmp] + G[tmp][j];  	//update distance from j to root;
				printf("%d\n",j);
			}
		}
	}
	return 1 ;

}
int main()
{
    int  Ne, v,u, distance, K,i,j,judge;
    //scanf("%d%d", &Nv, &Ne);
    Nv = 5, Ne = 7;
G[1][2] = G[2][1] = 2;
G[1][5] = G[5][1] = 1;
G[2][3] = G[3][2] = 1;
G[2][4] = G[4][2] = 1;
G[2][5] = G[5][2] = 2;
G[3][5] = G[5][3] = 1;
G[3][4] = G[4][3] = 1;
//    for (int i = 0; i < Ne; i++){
//        scanf("%d%d%d", &u, &v, &distance);
//        G[u][v] = G[v][u] = distance;
//    }
    //scanf("%d",&k);
    K = 1;
	for (i = 0; i < K; i++){
        for (j = 0; j < Nv; j++) {
			scanf("%d", &query[j]);
    	}
		judge = Dijkstra(query[0]);
		
        printf("%s\n", judge ? "Yes" : "No");
    }
    return 0;
}
