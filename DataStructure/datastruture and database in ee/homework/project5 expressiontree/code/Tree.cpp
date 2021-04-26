//
// Created by 12638 on 2021/4/25.
//

#include "Tree.h"

/**

*initialization of each node

*param intNum indicates the int number stored in the node

*param doubleNum indicates the float number stored in the node

*param if flag == 1 means all the characters under this node is included in thebracket

*param intDoubleOpe decides whether the type of number stored in the node is a int ora float

*param leftPoint and rightPoint is the binary-branch of the parent node

**/


void nodeIntInit(Node *node,int num){
    node->intNum=num;
    node->flag=0;
    node->doubleNum=0;
    node->intDoubleOpe=1;
    node->leftPoint=nullptr;
    node->rightPoint=nullptr;
}



void nodeDoubleInit(Node *node,double num){
    node->intNum=0;
    node->flag=0;
    node->doubleNum=num;
    node->intDoubleOpe=2;
    node->leftPoint=nullptr;
    node->rightPoint=nullptr;

}
