#ifndef __INVERSE_H__
#define __INVERSE_H__

#define inverse_N 9
#define inverse_n 3

extern int inv_swaprow(int k, int isk, float *a);
extern int inv_swapcol(int k, int jsk, float *a);
extern int inv_stepone(int k, float al, float *a, int *sp);
extern int inv_steptwo(int k, float *a, int *sp);
extern int inv_stepthree(int k, float al, float *a, int *sp);
extern int inv_rebuildrow(int k, int jsk, float *a);
extern int inv_rebuildcol(int k, int isk, float *a);
extern void brmulInASM(float *a, float *b, float *c, int *sp);

int inverse(float *input, float *result);
int brmul(float *input1, float *input2, float *result);

#endif
