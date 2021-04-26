//
// Created by 12638 on 2021/4/25.
//
#include "StrProcess.h"
#include <stack>
#include <iostream>
#include <cassert>
using namespace std;

int main() {
    struct Node* root;
    root = (struct Node*) malloc(sizeof(struct Node));
    //char  *s = (char*)"sin(0.5233333)";
    //char  *s = (char*)"exp(2)";
    //char *s = (char*)"2^3";
    char *s = (char*)"-2+3/1.5-(10*3)+40";
    //char  *s = (char*)"1%2-2+3*(4-5)";
    STRProcess(s,root);
    double result =calculate(root);
    cout << result <<endl;
    displayInOrder(root);
    return 0;
}

/**
*STRProcess can process a string to make it stored in the node of binary tree and split into two part
*and call the function itself in a recursive way
*str is the original input string and the root is the overall root of tree
**/
void STRProcess(char *str,Node *root){
    char front[MIDDLESIZE]={'\0'};                       // 设置一个前字符串数组用于存储分裂字符串的时候前半段字符串所存储的内容
    char back[MIDDLESIZE]={'\0'};                        // 设置一个后字符串数组用于存储分裂字符串的时候后半段字符串所存储的内容
    int min=10,temp=0,position=0,type=0,jump=0;
    int length = strlen(str);
    double tempDouble=0;
    int tempInt=0;
    stack<int> st ;
    assert(assertLine(str));                //判断整个表达式是否有输入错误
    if((type = isNumber(str)) > 0){                 //isNumber函数针对的是 判断该字符串是否只剩下数字字符以及小数点
        if(type==6){                        //返回值为6的话 说明表达式是含有sin cos tan exp等符号的函数，所以需要进行处理
            char tempArray[10]={'\0'};
            int localJump=0;
            int j=0;
            for(int i =0;i<length;i++){
                if(str[i]=='('){                //如果遇到了左括号，在sin（x）这样的函数当中，如果遇到了左括号就要把内容存储数组当中
                    localJump=1;
                    continue;
                }
                if(str[i]==')'){
                    localJump=1;
                    continue;
                }
                if(localJump){               //将sin函数 cos函数括号内的字符存储到数组当中
                    tempArray[j]=str[i];
                    j++;
                }
            }
            tempDouble=numProcess(tempArray);        //将字符串进行数字处理，转化为int或者float类型
            switch(str[0]){
                case 's':                            //如果首字母为s 说明是sin函数 调用math.h的sin函数
                    tempDouble=sin(tempDouble);
                    break;
                case 'c':                            //如果首字母为c第二个字母为o 说明是cos函数调用math.h的cos函数
                    if(str[1]=='o'){
                        tempDouble=cos(tempDouble);
                    }
                    else{
                        tempDouble=atan(tempDouble);     //如果首字母为c第二个字母为t 说明是ctan函数调用math.h的atan函数
                    }
                    break;
                case 't':                                     //如果首字母为t 说明是stan函数 调用math.h的tan函数
                    tempDouble=tan(tempDouble);
                    break;
                case 'e':                                //如果首字母为e 说明是exp函数 调用math.h的exp函数
                    tempDouble=exp(tempDouble);
                    break;
            }
            strcpy_s(root->expArray,20,str);
            nodeDoubleInit(root,tempDouble);
            root->flag=2;
            return;
        }
        if(type==5){                                 //返回值是5的话，说明整个字符是负的浮点数需要进行特殊处理
            for(int j=0;j<length-1;j++)
                str[j]=str[j+1];
            str[length-1]='\0';
            tempDouble=-numProcess(str);            //numProcess函数前面的负号正是证明了是负小数
            nodeDoubleInit(root,tempDouble);
            return;
        }
        if(type==4){                            //返回值是4的话 就说明了字符串是包含在括号内部的，需要进行曲括号处理
            for(int j=0;j<length-2;j++)
                str[j]=str[j+1];
            str[length-2]='\0';
            str[length-1]='\0';
            length=length-2;
            root->flag=1;
        }
        if(type==3){                       //返回值是3的话是负整数
            for(int j=0;j<length-1;j++)
                str[j]=str[j+1];
            str[length-1]='\0';
            tempDouble=-numProcess(str);
            tempInt=(int)tempDouble;
            nodeIntInit(root,tempInt);
            return;
        }                                 //minus
        if(type==2){                    //返回值是2的话就是浮点数
            tempDouble=numProcess(str);
            nodeDoubleInit(root,tempDouble);
            return;
        }                                  //float
        if(type==1){                    //返回值是1的话就是整数
            tempDouble=numProcess(str);
            tempInt=(int)tempDouble;
            nodeIntInit(root,tempInt);
            return;
        }
    }
    for(int i =0;i<length;i++){              //如果都不属于以上的情况，就说明整个字符串并未处理完全，还存在着很多运算符，需要进一步处理
        temp=operatorPriority(str[i]);
        if(temp==1&&i==0)
            continue;
        if(temp==3){
            st.push('(');
            jump=1;                                      //遇到左括号的话要把左括号进栈，并且把jump标志位置位1，使其跳过括号内的内容
        }
        if(temp==4){
            st.pop();     //如果遇到右括号的话就把左括号出栈，把标志位置为0，继续扫描
            if(st.empty())
                jump=0;
            continue;
        }
        if(jump==1)
            continue;
        if(temp!=0&&min>=temp){            //because we needthe first operator 找到最低优先级的第一个运算符
            min=temp;
            position=i;
        }
    }
    root->ope=str[position];           //记录下最小优先级运算符的位置
    root->intDoubleOpe=3;              //intDoubleOpe=3 指示着这个节点所存储的内容是运算符
    root->leftPoint=(Node*)malloc(sizeof(Node));         //运算符作为根节点，并开辟左节点
    root->rightPoint=(Node*)malloc(sizeof(Node));            //开辟右节点空间
    nodeIntInit(root->leftPoint,0);
    nodeIntInit(root->rightPoint,0);
    stringSplit(front,back,str,position);                   //将整个运算符分割成左右两部分，在运算符左边的就放在左节点下，在运算符右边的就放在右节点下
    STRProcess(front,root->leftPoint);                       //递归处理左节点和右节点
    STRProcess(back,root->rightPoint);
}

int operatorPriority(char ope){
    int priority=0;
    if(ope >= 48 && ope <= 57)
        priority=0;
    switch(ope){
        case '+': case '-':                 //如果当前字符为 加减号的话，其优先级最低，为1
            priority=1;
            break;
        case '*': case '/': case '%':       //如果当前符号为 * % %的话 就是优先级为2
            priority=2;
            break;
        case '(' :
            priority=3;
            break;
        case ')' :
            priority=4;
            break;
        case '^':                           //乘方的优先级较高为5
            priority=5;
            break;
        case '.':                           //小数点的优先级为6
            priority=6;
            break;
    }
    return priority;
}

void stringSplit(char *front,char *back,char *origin,int position){       //该函数的作用就是讲整个字符串根据中间运算符所在的位置，把字符串分割为两个字字符串
    int length=strlen(origin);
    for(int i=0;i<position;i++){
        front[i]=origin[i];
    }
    for(int j=0;j<length-position-1;j++){
        back[j]=origin[j+position+1];
    }
}
/**
    isNumber tells the type of the string
     if the return number is 1 means it is a integer 2 stand for the float 3 stand for minus int  4 stand for bracket expression 5 stand forthe minus float
     and 6 stands for the math function like sin and cos
**/
int isNumber(char *str){                    //if the return number is 1 means it is a integer 2 stand for the float 3 stand for minusint  4 stand for bracket expression 5stand for the minus float
    int doubleFlag=0;
    int flag=1;                             //6 stands for the math function
    int jump=0;
    char Left[5];
    int length = strlen(str);
    stack<char> st ;
    left(Left,str,4);
    if( !(strcmp(Left,"sin(")&&strcmp(Left,"cos(")&&strcmp(Left,"tan(")&&strcmp(Left,"ctan")&&strcmp(Left,"exp(")))
        return 6;//一样就返回0. 所以用与非逻辑, 有0 出1
    if(str[0]=='('){
        st.push('(');
        jump=1;
    }
    for(int j=1;j<length;j++){
        if(str[j]=='('){
            st.push('(');
            jump=1;
        }
        if(str[j]==')'){
            st.pop();
            if(st.empty())
                jump=0;
            if(j==length-1)
                return 4;
            continue;
        }
        if(jump==1)
            continue;
        if(str[j]=='.'){
            doubleFlag=1;
            continue;
        }
        if(str[j]>='0'&&str[j]<='9') {
        }
        else{
            flag=0;
            break;
        }
    }
    if(flag==0)
        return 0;
    else{
        if(str[0]=='-'&&doubleFlag==0)
            return 3;
        if(str[0]=='-'&&doubleFlag==1)
            return 5;
        if(doubleFlag==1)
            return 2;
        return 1;
    }
}

char *left(char *dst, char *src, int n) {
    char *p = src;
    char *q = dst;
    int len = strlen(src);
    if (n > len) n = len;
    while (n--)
        *(q++) = *(p++);
    *(q++) = '\0';
    return dst;
}
double numProcess(char *str){                   //该函数的作用就是判断字符串里面是否有小数点号，如果有就按小数点的处理方法，把字符串转化为小数，如果没有，就把字符转化为整数
    double intPart=0;
    double doublePart=0;
    int position=strlen(str);
    int temp1;
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='.'){
            position=i;
            break;
        }
    }
    for(int j=position-1,k=0;j>=0;j--,k++){
        temp1=str[j]-'0';
        intPart=intPart+temp1*pow(10,k);
    }
    for(int m=position+1,n=-1;m<strlen(str);m++,n--){
        temp1=str[m]-'0';
        doublePart=doublePart+temp1*pow(10,n);
    }
    return intPart+doublePart;
}
int assertLine(char *str){
    int leng=strlen(str);
    int count=0;
    stack<char> st ;
    for(int i=0;i<leng;i++){

        switch(str[i]){
            case '(':
                st.push('(');
                break;
            case ')':
                st.pop();
                break;
            case '+': case '-': case '*': case '/': case '%': case '^':
                count++;
                break;
            default:
                count=0;
                break;
        }
        if(count==3)
            return 0;
    }
    return st.empty() ? 1 : 0;
}
