#include<stdio.h>
#include<math.h> 
//using namespace std; 
#define Eigen_N 4

const double eps=1e-5;
const int lim=100;
int n=3,id[Eigen_N];
double key[Eigen_N],mat[Eigen_N*Eigen_N]={0,0,0,0,0,3.0, 2.0, 4.0 ,0,2.0,0.0, 2.0,0, 4.0 ,2.0 ,3.0},EigVal[Eigen_N],EigVec[Eigen_N*Eigen_N],tmpEigVec[Eigen_N][Eigen_N]; // tmpEigVec�ĳ�һά �ᱨ�� 
//extern void cmpEigVal(double* Key, int x,int y);
//	extern void initEigVec(int * EigVec, int Eigen_N);
/*
	int cmpEigVal(int x,int y)
	{
		return key[x]>key[y];
	}
*/
void Find_Eigen(int n,double *a,double *EigVal,double *EigVec)
{
	int i, j , count=0;; 
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			EigVec[i*Eigen_N+j]=0;
		}
	} 
	  ////	initEigVec(EigVec,16);
	
	for (i = 1;i <= n;i++) 
	{
		EigVec[i*Eigen_N+i]=1.0;
	}
	// initEigVec2(EigVec,1);
	
	while (1){
		double mx_val=0, Apq,App,Aqq,theta,sint,cost,sin2t,cos2t;
		int row_id,col_id,p,q;
		// In .s file , we could input  array [mx_val,rowid] , a[], output an array [mx_val, rowid, col_id] 
 		//ͳ�Ƶ�������
		int max[3];//max save [mx_val, rowid, col_id] 
		count++;
		//�Ҿ���ֵ����Ԫ�� 
		for (i=n-1;i>=1;i--)
		{
			for (j = n ;j >= i+1;j--)
			{
				if (fabs(a[i*Eigen_N+j]) > mx_val) 
				{
					mx_val = fabs(a[i*Eigen_N+j]);
					row_id = i;
					col_id = j;
				}
			}
		}
					// row_id save the mx_val 's row and column   in out ,save fabs in tmp , then send tmp in FindMax.s file
		//FindMax(max,a,3); 
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
		
		a[p*Eigen_N+p] = App*cost*cost + Aqq*sint*sint + 2.0*Apq*cost*sint;
		a[q*Eigen_N+q] = App*sint*sint + Aqq*cost*cost - 2.0*Apq*cost*sint;
		a[p*Eigen_N+q] = a[q*Eigen_N+p] = 0.5*(Aqq - App)*sin2t + Apq*cos2t;
		
		for (i=1;i<=n;i++)
		{
			if (i!=p&&i!=q)
				{
					double u=a[p*Eigen_N+i],v=a[q*Eigen_N+i];
					a[p*Eigen_N+i] = u*cost+v*sint;
					a[q*Eigen_N+i] = v*cost-u*sint;
					u = a[i*Eigen_N+p];
					v = a[i*Eigen_N+q];
					a[i*Eigen_N+p] = u*cost+v*sint;
					a[i*Eigen_N+q] = v*cost-u*sint;
					// operation1(i,args,a,max);
				}
		}
	/*������������ 
		for (int i=1;i<=n;i++)
		{
		double u=EigVec[i*Eigen_N+p],v=EigVec[i*Eigen_N+q];
		EigVec[i*Eigen_N+p]=u*cost+v*sint;EigVec[i*Eigen_N+q]=v*cost-u*sint;
		}
	}*/
//������ֵ���� 
	for (i=1;i<=n;i++) 
	{
		id[i]=i,key[i]=a[i*Eigen_N+i];
	}			
	for (i=1;i<=n;i++)
	{
		EigVal[i] = a[id[i]*Eigen_N+id[i] ] ;
		for (j=1;j<=n;j++)
		{
			tmpEigVec[j][i]  = EigVec[j*Eigen_N+id[i] ];
		}
	}
	for (i = 1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			EigVec[i*Eigen_N+j] = tmpEigVec[i][j];
		}
	}
	//��������Ϊ������ 	
	}
} 

int main(){
	int i,j ;
	//scanf("%d",&n);
	
//	for (i=1;i<=n;i++)
//		for (j=1;j<=n;j++)
//			scanf("%lf",&mat[i][j]);
//	
	Find_Eigen(n,mat,EigVal,EigVec);
//	printf("EigenValues = ");
//	for (i=1;i<=n;i++)
//	{
//		printf("%lf ",EigVal[i]);
//	}
//	printf("\nEigenVector =\n");
//	for (i=1;i<=n;i++)
//	{
//		for (j=1;j<=n;j++)
//		{
//			printf("%lf",EigVec[i*Eigen_N+j]);
//			if(j == n )
//			{
//				printf("%c",'\n');
//			} 
//			else
//			{
//				printf("%c",' ');
//			}
//			
//		}
//	}
	return 0;
}

