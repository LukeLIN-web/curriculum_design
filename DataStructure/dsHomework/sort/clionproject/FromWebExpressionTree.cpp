////
//// Created by 12638 on 2021/4/11.
////
//#include<cstdio>
//#include<string>
//
//const int maxn = 1000 + 10;
//char expr[maxn];        //原表达式
//int str[maxn];            //转换后的表达式
//int lch[maxn + 1], rch[maxn + 1],op[maxn + 1];     //每个结点的左右子结点编号和字符
//bool is_alpha1[maxn], is_alpha2[maxn];        //是否为操作符或括号,前者对s数组，后者对op数组
//int nc = 0;         //结点数
//int cnt = 0;        //转换后字符串的长度
//
//// 把表达式exp转化成参数形式，并存到str中
//void analyse(char* expr)
//{
//    int len = strlen(expr);
//    int i = 0;
//    while(i < len)
//    {
//        if (!isdigit(expr[i]))
//        {
//            str[cnt] = expr[i++];
//            is_alpha1[cnt++] = true;
//        }
//        else
//        {
//            int tmp = 0;
//            while (isdigit(expr[i]))
//            {
//                tmp = tmp * 10 + expr[i] - '0';
//                i++;
//            }
//            str[cnt] = tmp;
//            is_alpha1[cnt++] = false;
//        }
//    }
//}
//
////表达式转表达式树
//int build_tree(int* s, int x, int y)
//{
//    int i, c1=-1, c2=-1, p=0;
//    int u;
//    if(y-x == 1)   //仅一个字符，建立单独结点
//    {
//        u = ++nc;
//        lch[u] = rch[u] = 0;
//        op[u] = s[x];
//        if (is_alpha1[x])  is_alpha2[u] = true;
//        return u;
//    }
//
//    for (i = x; i < y; i++)   //寻找根节点的位置
//    {
//        if(s[i] == '(' && is_alpha1[i])   p++;
//        if(s[i] == ')' && is_alpha1[i])   p--;
//        if((s[i] == '+' || s[i] == '-') && is_alpha1[i])   if (!p) c1 = i;
//        if((s[i] == '*' || s[i] == '/') && is_alpha1[i])    if (!p) c2 = i;
//    }
//    if (c1 < 0) c1 = c2;     //找不到括号外的加减号，就用乘除号
//    if(c1 < 0) return build_tree(s, x+1, y-1);     //整个表达式被一对括号括起来
//    u = ++nc;
//    lch[u] = build_tree(s, x, c1);
//    rch[u] = build_tree(s, c1+1, y);
//    op[u] = s[c1];
//    if (is_alpha1[c1])  is_alpha2[u] = true;
//    return u;
//}
//
////先序遍历
//void PreOrder(int root)
//{
//    if(!is_alpha2[root])  printf("%d ", op[root]);
//    else  printf("%c ", op[root]);
//
//    if (lch[root] > 0)  PreOrder(lch[root]);
//    if (rch[root] > 0)  PreOrder(rch[root]);
//}
//
////中序遍历
//void InOrder(int root)
//{
//    if (lch[root] > 0)  InOrder(lch[root]);
//
//    if (!is_alpha2[root])  printf("%d ", op[root]);
//    else  printf("%c ", op[root]);
//
//    if (rch[root] > 0)  InOrder(rch[root]);
//}
//
////后序遍历
//void PostOrder(int root)
//{
//    if (lch[root] > 0)  PostOrder(lch[root]);
//    if (rch[root] > 0)  PostOrder(rch[root]);
//
//    if (!is_alpha2[root])  printf("%d ", op[root]);
//    else  printf("%c ", op[root]);
//}
//
////根据表达式二叉树求值
//int cal(int root)
//{
//    int ans = 0;
//    int ch = op[root];
//    if (!is_alpha2[root])  return ch;
//    switch (ch)
//    {
//        case '+':  ans = cal(lch[root]) + cal(rch[root]); break;
//        case '-':  ans = cal(lch[root]) - cal(rch[root]); break;
//        case '*':  ans = cal(lch[root]) * cal(rch[root]); break;
//        case '/':  ans = cal(lch[root]) / cal(rch[root]); break;
//    }
//    return ans;
//}
//
////打印表达式二叉树
//void PrintTree(int root)
//{
//    int flag = 0;        //标记是否有左右子树
//    if (!is_alpha2[root])  printf("%d", op[root]);
//    else  printf("%c", op[root]);
//
//    if (lch[root] > 0)  flag += 1;
//    if (rch[root] > 0)  flag += 2;
//    if (flag == 0)  return;
//    if (flag == 1)        //只有左子树
//    {
//        printf("(");
//        PrintTree(lch[root]);
//        printf(", )");
//    }
//    if (flag == 2)        //只有右子树
//    {
//        printf("( ,");
//        PrintTree(rch[root]);
//        printf(")");
//    }
//    if (flag == 3)        //左右子树都有
//    {
//        printf("(");
//        PrintTree(lch[root]);
//        printf(",");
//        PrintTree(rch[root]);
//        printf(")");
//    }
//}
//
//int main()
//{
//
//    strcpy(expr, "(-2+323)*2");
//
//    analyse(expr);   //转化
//    build_tree(str, 0, cnt);        //建树
//
//    int root = 1;
// //  printf("先序遍历："); PreOrder(root); printf("\n");            //三种遍历
// //   printf("中序遍历："); InOrder(root); printf("\n");
////    printf("后序遍历："); PostOrder(root); printf("\n");
// //   printf("表达式二叉树："); PrintTree(root); printf("\n");        //打印表达式二叉树
//    InOrder(root);
//    printf("expression tree");
//    PrintTree(root);
//
//    int ans;
//    ans = cal(root);                //表达式求值
//    printf("thr result = %d\n", ans);
//
//    return 0;
//}