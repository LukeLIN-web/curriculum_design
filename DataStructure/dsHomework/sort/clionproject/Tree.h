//
// Created by 12638 on 2021/4/25.
//
#include <stdlib.h>

#include <stdio.h>

#include <string.h>
#ifndef CLIONPROJECT_TREE_H
#define CLIONPROJECT_TREE_H

#define MAXSIZE 40

#define MIDDLESIZE 20



typedef struct Node Node;




struct Node{
    Node *leftPoint;

    Node *rightPoint;

    int intNum;

    double doubleNum;

    char ope;

    char expArray[10];

    int flag;             //toindicate the expression contain bracket if flag==2 sin flag==3 cos flag==4 tan flag==5 exp flag==6 ctan

    int intDoubleOpe;      //1means int 2 means double 3 means Ope

};



void nodeIntInit(Node *node,int num);

void nodeDoubleInit(Node *node,double num);

#endif //CLIONPROJECT_TREE_H
