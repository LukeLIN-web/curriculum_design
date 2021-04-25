//
// Created by 12638 on 2021/4/25.
// 对整棵树的中缀输出以及结果的计算，递归删除整个树

#include <assert.h>

#include<math.h>

#include "display.h"


/**
*displayInOrder function can express the regular order of the formula
*param root is the fundamental root of the whole binary tree
**/
void displayInOrder(Node *root){
    if(root->flag==2){                  //如果flag为2的时候 就可以输出存在expArray里面的表达式了
        printf("%s",root->expArray);
        return;
    }
    if(root->flag==1)     //如果flag为1 说明该节点下所有的内容都是在一个括号里面的 所以在中序遍历节点下的内容时先输出一个左括号
        printf("(");
    if(root->leftPoint!=NULL)      //中序遍历中，左节点的内容时最先遍历的，所以先遍历左节点的内容
        displayInOrder(root->leftPoint);
    if(root->intDoubleOpe==1)          //如果intDoubleOpe为1 表示该节点内存储的数据为int类型 输出%d
        printf("%d",root->intNum);
    if(root->intDoubleOpe==2)          //如果intDoubleOpe为2 表示该节点内存储的数据为float类型 输出%f
        printf("%f",root->doubleNum);
    if(root->intDoubleOpe==3)          //如果intDoubleOpe为3 表示该节点内存储的数据为char类型 输出%c 就是运算符
        printf("%c",root->ope);
    if(root->rightPoint!=nullptr)
        displayInOrder(root->rightPoint);       //中序遍历中右节点的内容是最后遍历的 所以遍历右节点的内容
    if(root->flag==1)
        printf(")");      //在最后结束的时候再输出一个右括号
}

/**
*calculate function can calculate the result of the formula stored in the binary tree
*param root is the fundamental root of the whole binary tree
**/

double calculate(Node *root){
    if(root->leftPoint==NULL&&root->rightPoint==NULL){            //如果该节点的左右都是空指针，则需要返回该节点所存储的值，如果inDoubleOpe为1的话，返回值应该为int，如果是2的话 返回值为floa
        if(root->intDoubleOpe==1)
            return root->intNum;
        if(root->intDoubleOpe==2)
            return root->doubleNum;
    }

    if(root->leftPoint!=NULL&&root->rightPoint!=NULL){
        switch(root->ope){
            case '+':                                                                       //如果子节点是加号，则将左右节点的计算结果想加，如果是负号则把左右节点的结果相减，如果是乘号，则把左右节点结果相乘
                return calculate(root->leftPoint)+calculate(root->rightPoint);          //如果是/ 号，就把左右结果相除
            case '-':
                return calculate(root->leftPoint)-calculate(root->rightPoint);
            case '*':
                return calculate(root->leftPoint)*calculate(root->rightPoint);
            case '/':
                return calculate(root->leftPoint)/calculate(root->rightPoint);
            case '%':
                assert(root->leftPoint->intDoubleOpe!=2&&root->rightPoint->intDoubleOpe!=2);    //求余符号两边都是要整数，所以需要assert函数来测试，然后将左右节点结果求余
                return (int)calculate(root->leftPoint)%(int)calculate(root->rightPoint);
            case '^':
                return pow(calculate(root->leftPoint),calculate(root->rightPoint));             //如果是乘方，则把左右节点结果进行乘方运算
            default:
                return 0.1;
        }
    }
    else{
        return 0.1;
    }
}


void recursiveDelete(Node *root) {
    if (root->leftPoint == NULL&&root->rightPoint == NULL) {
        free(root);
        root = NULL;
        return;
    }
    recursiveDelete(root->leftPoint);
    root->leftPoint = NULL;
    recursiveDelete(root->rightPoint);
    root->rightPoint = NULL;
}
