//
// Created by 12638 on 2021/4/25.
//
#include "Tree.h"
#include "display.h"
#ifndef CLIONPROJECT_STRPROCESS_H
#define CLIONPROJECT_STRPROCESS_H
int operatorPriority(char ope);

void STRProcess(char *str,Node *root);
void stringSplit(char *front,char *back,char *origin,int position);
int isNumber(char *str);
double numProcess(char *str);
char * left(char *dst,char *src, int n);

int assertLine(char *str);

#endif //CLIONPROJECT_STRPROCESS_H
