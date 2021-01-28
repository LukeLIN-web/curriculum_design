#include <math.h>
#include <stdio.h>
extern int cmpEigVal(int * Key, int x,int y);
extern void initEigVec(float * EigVec, int N);
extern void initEigVec2(int * EigVec, int N);
extern void FindMax(int *max,int* mat,int N);
extern void fillApp(int N,int* mat,int *App,int*max);
extern void operation1(int *sp,float *args,float *a,int *max); 
extern void operation2(int *sp,float *args,float *a,int *max);
// warning: can't move the sequence input to .s file, it will be a disaster

static int sp[30];
//extern void brmul(float *a, float *b, float *c);
#define Veclength 16

// int main(){
// 	//float d=3.0;
// 	int i,maxval ;
// 	//int key[N] = {1.0,0.0,1.0 ,1.0 ,1.0 ,2.0 ,3.0 ,4.0 ,2.0};
// 	int mat[16]={0,0,0,0,0,3, 2, 4 ,0,2, 0 ,2,0, 4 ,2 ,3};
// 	float EigVec[Veclength] = {-1,2,2,2,2,3, -1, 4 ,0,2, 0 ,2,0, 4 ,2 ,3};
// 	int max[3] = {0,-1,-1};
// 	int App[3] = {0};
// 	float args[10] = { 0.5,0.8,0.2,0.3};
// 	sp[0] = i ;
// 	//fillApp(4,mat,App,max);
// 	//FindMax(key,mat,3); // max in r0, a in r1, n=3 in r2
// 		initEigVec(EigVec,Veclength);
// 	//	initEigVec2(EigVec,1);
// 	// i = cmpEigVal(key,1,2); //compare the float in assemble will have error
// 	//operation1(App,args,a);
// 	// i = sp[0];
// 	// operation2(sp,args,mat);
// 	return 0;
// }
