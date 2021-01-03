//#include <stdlib.h>
//#include <math.h>
//#include <stdio.h>

#include "inverseANDbrmul.h"
//#define inverse_N 9
//#define inverse_n 3

//extern int inv_swaprow(int k, int isk, float *a);
//extern int inv_swapcol(int k, int jsk, float *a);
//extern int inv_stepone(int k, float al, float *a, int *sp);
//extern int inv_steptwo(int k, float *a, int *sp);
//extern int inv_stepthree(int k, float al, float *a, int *sp);
//extern int inv_rebuildrow(int k, int jsk, float *a);
//extern int inv_rebuildcol(int k, int isk, float *a);
//extern void brmulInASM(float *a, float *b, float *c, int *sp);

//int inverse(float *input, float *result);
//int brmul(float *input1, float *input2, float *result);

int inverse(float *input, float *result) {
	//static float c[inverse_N]={0.0,0.0,0.0 ,0.0 ,0.0 ,0.0 ,0.0 ,0.0 ,0.0};
  	//static float a_org[inverse_N]={1.0,0.0,1.0 ,1.0 ,1.0 ,2.0 ,3.0 ,4.0 ,2.0};
	static float a[inverse_N]={0.0,0.0,0.0 ,0.0 ,0.0 ,0.0 ,0.0 ,0.0 ,0.0};
	static int sp[30];
	static int is[inverse_N], js[inverse_N];
	//int inverse_n=3;
	int i, j;
	int k, l;
	int change;
	float d, p;

	for (i=0; i<inverse_N; i++)
		a[i]=input[i];
	/*scanf("%d", &inverse_n);
	if (inverse_n > 0) {
		n2 = inverse_n * inverse_n;
		for (i = 0; i < n2; i++)
			scanf("%f", &a[i]);
	} else {
		return 1;
	}*/

	//printf("MAT A IS:\inverse_n");
	/*for (i = 0; i < inverse_n; i++) {
		for (j = 0; j < inverse_n; j++) {
			//printf("%13.4lf", a[inverse_n * i + j]);
			b[inverse_n * i + j] = fabs(a[inverse_n * i + j]);
			a_org[inverse_n * i + j]=a[inverse_n * i + j];
		}

		printf("\inverse_n");
	}*/

	//-------------------------------------i = brinv(a, inverse_n);
	

	for (k = 0; k <= inverse_n - 1; k++) {
		//------------选主元
		//d = choosemax(k, b, is, js);

		d = 0.0;
		for (i = k; i <= inverse_n - 1; i++)
			for (j = k; j <= inverse_n - 1; j++) {
				l = i * inverse_n + j;
				p = a[l];
				if(p<0) p=-p;//p=fabs(a[l])
				if (p > d) {
					d = p;
					is[k] = i;
					js[k] = j;
				}
			}  
		//--------------选主元结束
		
		
		//----------判断是否为奇异矩阵
		if (d + 1.0 == 1.0) {
			//printf("%d %d %d", k, i, j);
			//printf("err**not inv\inverse_n");
			return (1);
		}
		//----------判断结束
		
		//行交换
		change = is[k];
		k=inv_swaprow(k, change, a);
/*		if (is[k] != k)
			for (j = 0; j <= inverse_n - 1; j++) {
				u = k * inverse_n + j;
				v = is[k] * inverse_n + j;
				p = a[u];
				a[u] = a[v];
				a[v] = p;
			}*/
		//列交换
		change = js[k];
		k=inv_swapcol(k, change, a);
/*		if (js[k] != k)
			for (i = 0; i <= inverse_n - 1; i++) {
				u = i * inverse_n + k;
				v = i * inverse_n + js[k];
				p = a[u];
				a[u] = a[v];
				a[v] = p;
			}  */
			
		//m(k, j) = m(k, j) / m(k, k)，j = 0, 1, ..., inverse_n-1；j != k
		l = k * inverse_n + k;
		p= 1.0 / a[l];
		a[l]=p;

		k=inv_stepone(k, p, a, sp);
/*		for (j = 0; j <= inverse_n - 1; j++)
			if (j != k) {
				u = k * inverse_n + j;
				a[u] = a[u] * a[l];
			} */
			
		//m(i, j) = m(i, j) - m(i, k) * m(k, j)，i, j = 0, 1, ..., inverse_n-1；i, j != k
		k=inv_steptwo(k, a, sp);
/*		for (i = 0; i <= inverse_n - 1; i++)
			if (i != k)
				for (j = 0; j <= inverse_n - 1; j++)
					if (j != k) {
						u = i * inverse_n + j;
						a[u] -= a[i * inverse_n + k] * a[k * inverse_n + j];
					} */
					
		//m(i, k) = -m(i, k) * m(k, k)，i = 0, 1, ..., inverse_n-1；i != k
		l = k * inverse_n + k;
		p=-a[l];
		k=inv_stepthree(k, p, a, sp);
/*		for (i = 0; i <= inverse_n - 1; i++)
			if (i != k) {
				u = i * inverse_n + k;
				a[u] = -a[u] * a[l];
			}   */
		
	}

	for (k = inverse_n - 1; k >= 0; k--) {
		change = js[k];
		k=inv_rebuildrow(k, change, a);
/*		if (js[k] != k)
			for (j = 0; j <= inverse_n - 1; j++) {
				u = k * inverse_n + j;
				v = js[k] * inverse_n + j;
				p = a[u];
				a[u] = a[v];
				a[v] = p;
			}    */
		//列交换，恢复行变换
		change = is[k];
		k=inv_rebuildcol(k, change, a);
/*		if (is[k] != k)
			for (i = 0; i <= inverse_n - 1; i++) {
				u = i * inverse_n + k;
				v = i * inverse_n + is[k];
				p = a[u];
				a[u] = a[v];
				a[v] = p;
			}  */
		//行交换，恢复列变换
	}
	
	
	
	//---------------------------------------brinv end
	
	
	//if (i == 0) {

/*		printf("\nMAT A- IS:\inverse_n");
		for (i = 0; i < inverse_n; i++) {
			for (j = 0; j < inverse_n; j++)
				printf("%13.4lf", a[inverse_n * i + j]);
			printf("\inverse_n");
		}

		printf("\nMAT AA- IS:\inverse_n"); */

		//------------------------------brmul(b, a, inverse_n, inverse_n, inverse_n, c);
		//brmul(a, a_org, c, sp);
/*	for (i = 0; i <= inverse_n - 1; i++)
		for (j = 0; j <= inverse_n - 1; j++) {
			u = i * inverse_n + j;
			c[u] = 0.0;
			for (l = 0; l <= inverse_n - 1; l++)
				c[u] += a[i * inverse_n + l] * b[l * inverse_n + j];	// 矩阵乘法
		}   */
		
		
		//------------------------------brmul end
		
/*		for (i = 0; i < inverse_n; i++) {
			for (j = 0; j < inverse_n; j++)
				printf("%13.4lf", c[inverse_n * i + j]);
			printf("\inverse_n");
		}
	}*/
	for (i=0; i<inverse_N; i++)
		result[i]=a[i];
	

	return 0;
}

int brmul(float *input1, float *input2, float *result){
	static float c[inverse_N]={0.0,0.0,0.0 ,0.0 ,0.0 ,0.0 ,0.0 ,0.0 ,0.0};
	static int sp[30];
	int i;

	brmulInASM(input1, input2, c, sp);
	for (i=0; i<inverse_N; i++)
		result[i]=c[i];
	
	return 0;
}
