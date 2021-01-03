#include<stdio.h>
#include<math.h> 


#define Eigen_N 4

int n;
int id[Eigen_N];
float key[Eigen_N];// 7.0,2.0,1.0,8.0,5.0 ,0.0, 4.0,3.0,9.0
float mat[9]={1.0 ,2.0,   3.0 ,2.0, 1.0 ,  3, 3, 3, 6.0};
float EigVal[4],EigVec[Eigen_N*Eigen_N],tmpEigVec[Eigen_N*Eigen_N]; // tmpEigVec�ĳ�һά �ᱨ�� 
//extern void cmpEigVal(double* Key, int x,int y);
// extern void initEigVec(float * EigVec, int n  ); 
// extern void initEigVec2(float * EigVec, int *sp  ); 
// extern float geter(int a, int b, float *matrix  ); 
// extern float setter(int a, int b,float val, float *matrix  ); 
// extern int setEigval(int i, int *id,float* val, float *matrix  ); 
// extern int saveId(int *id,float* key, float *matrix  ); 
// extern int Trace(int *id,float* key, float *matrix  ); 
/*
	int cmpEigVal(int x,int y)
	{
		return key[x]>key[y];
	}
*/
// input n=3, matrix mat[9] , EigVal[4] ={0},EigVec = {0 }  , ouput EigVal and EigVec; 
void Find_Eigen(int n,float *b,float *EigVal,float *EigVec)
{
	float a[16];
	static int sp[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
	int i;
	int	j ;
	int	count;
	float eps;
	int lim;
	a[5] = b[0] ;
	a[6] = b[1];
	a[7] =b[2];
	a[9] =b[3];
	a[10] = b[4];
	a[11] =	b[5] ;
	a[13] =b[6];
	a[14] =b[7] ;
 	a[15] =	b[8];
	n = 3;
	 for (i=1;i<=n;i++)
	 {
	 	for (j=1;j<=n;j++)
	 	{
	 		EigVec[i*Eigen_N+j]=0;
	 	}
	 } 
	//initEigVec(EigVec,16);
	
	for (i = 1;i <= n;i++) 
	{
		EigVec[i*Eigen_N+i]=1.0;
	}
	//initEigVec2(EigVec,sp);
	count = 0;
	while (1){
		float mx_val, Apq,App,Aqq,theta,sint,cost,sin2t,cos2t,temp;
		int row_id,col_id,p,q;
		// In .s file , we could input  array [mx_val,rowid] , a[], output an array [mx_val, rowid, col_id] 
 		//ͳ�Ƶ�������
		int max[3];//max save [mx_val, rowid, col_id] 
		count++;
		mx_val = 0;
		//�Ҿ���ֵ����Ԫ�� 
		for (i = n-1;i>=1;i--)
		{
			for (j = n ;j >= i+1;j--)
			{
				//temp = geter(i,j,a);
                temp = a[i*4+j];
				if (fabs(temp) > mx_val) 
				{
					mx_val = fabs(temp);
					row_id = i;
					col_id = j;
				}
			}
		}
					// row_id save the mx_val 's row and column   in out ,save fabs in tmp , then send tmp in FindMax.s file
		//FindMax(max,a,3); 
		eps =  0.00001;// refresh, otherwise eps and lim may change in the process 
		lim = 100;
		if (mx_val < eps || count > lim) 
		{
			break;
		}
		// if(max[0] <eps) ||count> lim )
		//������ת�任 
		p = row_id;
		q = col_id; 
		// p ,and q save the val row and colum
		// p = max[1] , q= max[2] ;  
		
		// float App[3] ={Apq,App,Aqq}; 
		// float args[4] = { sint,cost,sin2t,con2t};
		// Apq = geter(p,q,a);
		// App = geter(p,p,a);
		// Aqq = geter(q,q,a);
		Apq = a[p*Eigen_N+q];
		App = a[p*Eigen_N+p];
		Aqq = a[q*Eigen_N+q];
		// fillApp(4,mat,App,max);
		theta = 0.5*atan2(-2.0*Apq,Aqq-App);
		//theta = 0.5*atan2(-2.0*App[0],App[2]-App[1]);
		sint = sin(theta);
		cost = cos(theta); 
		//args[0] = sint,args[1] = cost;
		sin2t = sin(2.0*theta);
		cos2t = cos(2.0*theta);
		//args[2] =sin2t,args[3] = cos2t;
		// operation1(App,args,a,max);
		
		//a[p*Eigen_N+p] = App*cost*cost + Aqq*sint*sint + 2.0*Apq*cost*sint;
		//temp = App*cost*cost + Aqq*sint*sint + 2.0*Apq*cost*sint;
		//setter(p,p,temp,a);
        a[p*Eigen_N+p] = App*cost*cost + Aqq*sint*sint + 2.0*Apq*cost*sint;
		a[q*Eigen_N+q] = App*sint*sint + Aqq*cost*cost - 2.0*Apq*cost*sint;
		a[p*Eigen_N+q] = 0.5*(Aqq - App)*sin2t + Apq*cos2t;
		a[q*Eigen_N+p] = 0.5*(Aqq - App)*sin2t + Apq*cos2t;
		for (i=1;i<=n;i++)
		{
			if (i != p && i != q)
				{
					float  u ;
					float v;
					u =  a[p*Eigen_N+i];
					v = a[q*Eigen_N+i];
					a[p*Eigen_N+i] = u*cost+v*sint;
					a[q*Eigen_N+i] = v*cost-u*sint;
					u = a[i*Eigen_N+p];
					v = a[i*Eigen_N+q];
					a[i*Eigen_N+p] = u*cost+v*sint;
					a[i*Eigen_N+q] = v*cost-u*sint;
					// operation1(i,args,a,max);
				}
		}
	
	// 	for (i=1;i<=n;i++)
	// 	{
	// 	float u;
	// 	float v;
	// 	u=EigVec[i*Eigen_N+p];
	// 	v =EigVec[i*Eigen_N+q];
	// 	EigVec[i*Eigen_N+p]=u*cost+v*sint;
	// 	EigVec[i*Eigen_N+q]=v*cost-u*sint;
	// 	}
		
	}
//������ֵ���� 
	for (i=1;i<=n;i++) 
	{
		id[i]=i;
		key[i]=a[i*Eigen_N+i];
	}			
	// save id and key
	// saveId(id,key,a);

	for (i=1;i<=n;i++)
	{
		EigVal[i] = a[id[i]*Eigen_N+id[i] ] ;
		//i = setEigval(i,id,EigVal,a); // execute it will change i , we need return  i   
		for (j = 1;j<=n;j++)
		{
			tmpEigVec[j*4+i]  = EigVec[j*Eigen_N+id[i] ];
		}
	}
	for (i = 1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			EigVec[i*Eigen_N+j] = tmpEigVec[i*4+j];
		}
	}
	//��������Ϊ������ 	
} 

int main(){
	int i,j ;
	//scanf("%d",&n);
//	for (i=1;i<=n;i++)
//		for (j=1;j<=n;j++)
//			scanf("%lf",&mat[i][j]);
	Find_Eigen(3,mat,EigVal,EigVec);
	// print all results.
	// printf("EigenValues = ");
	// for (i=1;i<=n;i++)
	// {
	// 	printf("%lf ",EigVal[i]);
	// }
	// printf("\nEigenVector =\n");
	// for (i=1;i<=n;i++)
	// {
	// 	for (j=1;j<=n;j++)
	// 	{
	// 		printf("%lf",EigVec[i*Eigen_N+j]);
	// 		if(j == n )
	// 		{
	// 			printf("%c",'\n');
	// 		} 
	// 		else
	// 		{
	// 			printf("%c",' ');
	// 		}	
	// 	}
	// }
	return 0;
	
}

