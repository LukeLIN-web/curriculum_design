# DS and SQL in ee



### 第二周

栈 , 

**递归的实现是费空间的，进栈出栈也是费时的，如果可能，应将递归改为非递归，即采用循环方法来解决同一问题。如果一个函数中所有递归形式的调用都出现在函数的末尾，则称这样的递归为**尾递归。尾递归可以容易地改为迭代过程。因为当递归调用返回时，总是返回上一层递归调用语句的下一句语句处，在尾递归的情况下，正好返回函数的末尾，因此不再需要利用栈来保存返回地址，大多数现代的编译器会利用这种特点自动生成优化的代码。

编写一个计算器，使之具有：

- 能够处理小数
- 能够处理求余运算符（%）
- 能够处理单目运算符，例如乘方（^）
- 能够处理负数（选做）
- 能够处理exp,sin,cos,tan,ctan等常见函数（选做）

### 第三周

若数值为0的元素数目远远多于非0元素的数目时，则称该矩阵为稀疏矩阵(sparse matrix)；与之相反，若非0元素数目占大多数时，则称该矩阵为稠密矩阵。定义非零元素的总数比上矩阵所有元素的总数为矩阵的稠密度。稠密度小于等于0.05(或者10% 20%)时，则称该矩阵为**稀疏矩阵**。

在数值分析中经常出现一些阶数很高的稀疏矩阵。有时为了节省存储空间，可以对这类矩阵进行**压缩存储**。所谓压缩存储是指：为多个值相同的元只分配一个存储空间；对零元不分配空间。

假若值相同的元素或者零元素在矩阵中的分布有一定规律（如上三角矩阵、下三角矩阵、对角矩阵），则称该矩阵为**特殊矩阵**。下面分别讨论它们的压缩存储。



将三元组按行优先顺序，同一行中列号从小到大的规律排列成一个线性表，称为三元组表。以顺序存储结构来表示三元组表，则可得稀疏矩阵的一种压缩存储方式——**三元组顺序表**。

```
#define SMax 1024   /* 一个足够大的数 */

typedef double MatrixValue;

typedef struct {
    int row, col;   /* 非零元素的行、列 */
    MatrixValue val;  /* 非零元素值 */
} SPNode;   /* 三元组类型 */

typedef struct {
    int mu, nu, tu; /* 矩阵的行数、列数及非零元素的个数 */
    SPNode data[SMax+1];    /* 三元组表 */
} SPMatrix; /* 三元组表的存储类型 */
```

#### 稀疏矩阵 转置算法 

只要做到

- 将矩阵行、列维数互换
- 将每个三元组中的 ii 和 jj 相互调换
- 重排三元组次序，使mb中元素以B的行(A的列)为主序

*方法*：按M的列序转置

```
SPMatrix * sm_transpose1(SPMatrix * a) {
    SPMatrix * b;
    int p, q, col;
    b = (SPMatrix *)malloc(sizeof(SPMatrix));   /* 申请存储空间 */
    b->mu = a->nu;
    b->nu = a->mu;
    b->tu = a->tu;
    if(b->tu > 0) { /* 有非零元素则转换 */
        q = 0;
        for(col = 1; col <= a->nu; col++)   /* 按M的列序转换 */
            for(p = 1; p <= a->tu; p++) /* 扫描整个三元组表 */
                if(a->data[p].col == col) {
                    b->data[q].row = a->data[p].col;
                    b->data[q].col = a->data[p].row;
                    b->data[q].val = a->data[p].val;
                    q++;
                } 
    }
    return b;
}
```

上面是最容易想到的,但是效果不好. 

分析上述算法，主要的工作是在pp和colcol的两重循环中完成的，故算法的时间复杂度为O(nu⋅tu)O(nu⋅tu)，即和MM的列数及非零元的个数的乘积成正比。

一般矩阵转置算法：

```
for(col=0;col<n;col++)
    for(row=0;row<m;row++)
        n[col][row]=m[row][col];
```

时间复杂度：

T(n)=O(m∗n)T(n)=O(m∗n)

虽然节省了存储空间，但时间复杂度提高了，因此算法仅适用于tu<<mu×nu的情况。

#### 改进算法

空间换时间,

**目标** ：按照a.data中三元组的次序进行转置，并将转置后的三元组置b中恰当的位置。

**解决思路**:如果能预先确定矩阵M中每一列（即T中每一行）的第一个非零元在b.data中应有的位置，那么在对a.data中的三元组依次作转置时，便可直接放到b.data中恰当的位置上去。

**具体做法**：为了确定这些位置，在转置前，应先求得M的每一列中非零元的个数，进而求得每一列的第一个非零元在b.data中应有的位置。需要附设num和cpot两个向量。num[col]表示矩阵M中第col列中非零元的个数，cpot[col]指示M中第col列的第一个非零元在b.data中的恰当位置。

{cpot[1]=1;

{cpot[col]=cpot[col−1]+num[col−1]	2≤col≤a.nu

```
#define CMax 512    /* 一个足够大的列数 */

SPMatrix * sm_transpose2(SPMatrix * a) {
    SPMatrix* b;
    int i, j, k;
    int num[CMax+1], cpot[CMax+1];
    b = (SPMatrix *)malloc(sizeof(SPMatrix));
    b->mu = a->nu;
    b->nu = a->mu;
    b->tu = a->tu;
    if(b->tu > 0) { /* 有非零元素则转换 */
        for(i = 1; i <= a->nu; i++)
            num[i] = 0;
        for(i = 1; i <= a->tu; i++) {   /* 求矩阵M中每一列非零元素的个数 */
            j = a->data[i].col;
            num[j]++;
        }
        cpot[1] = 1;         
        for(i = 2; i <= a->nu; i++)
            cpot[i] = cpot[i-1]+num[i-1];
        for(i = 1; i <= a->tu; i++) {   /* 扫描三元组表 */
            j = a->data[i].col; /* 当前三元组的列号 */
            k = cpot[j];    /* 当前三元组在T.data中的位置 */
            b->data[k].row = a->data[p].col;
            b->data[k].col = a->data[p].row;
            b->data[k].val = a->data[p].val;
            cpot[j]++;
        }
    }
    return b;
} 
```

快速算法仅比前一个算法多用了两个辅助向量。从时间上看，算法中有4个并列的单循环，循环次数分别为nu和tu，因而总的时间复杂度为O(nu+tu)。在M的非零元个数tu和mu×nu等数量级时，其时间复杂度为O(mu×nu)，和经典算法的时间复杂度相同。

**三元组表特点**：

三元组顺序表又称有序的双下标法，它的特点是，非零元在表中按行序有序存储，因此便于进行依行顺序处理的矩阵运算。然而，若需按行号存取某一行的非零元，则需从头开始进行查找。

#### 行逻辑连接的顺序存储

为了便于随机存取任意一行的非零元，则需知道每一行的第一个非零元在三元组表中的位置。为此，可将上节快速转置矩阵的算法中创建的，指示“行”信息的辅助数组cpot固定在稀疏矩阵的存储结构中。称这种“带行链接信息”的三元组表为行逻辑链接的顺序表，其类型描述如下：

```
typedef struct {
    SPNode data[SMax];  /* 三元组表 */
    int rpos[RMax+1];   /* 各行第一个非零元的位置表 */
    int mu,nu,tu;   /* 矩阵的行数、列数和非零元个数 */
} RLSMatrix;
```



#### 矩阵乘法

**矩阵的乘法就是矩阵a的第一行乘以矩阵b的第一列，各个元素对应相乘然后求和作为第一元素的值**

**两个稀疏矩阵相乘的乘积不一定是稀疏矩阵。**

```
C初始化；
if(C是非零矩阵) {    /* 逐行求积 */
    for(arow = 1; arow <= A.mu; arow++) {   /* 处理M的每一行 */   
        ctemp[] = 0;    /* 累加器清零 */ 
        计算C中第arow行的积并存入ctemp[]中;
        将ctemp[]中非零元压缩存储到C.data中; 
    }
}
```



#### 稀疏矩阵链式存储结构

**当矩阵的非零元个数和位置在操作过程中变化较大时，就不宜采用顺序存储结构来表示三元组的线性表。**

**由于非零元的插入或删除会引起**A.data中元素的移动。为此，对这种类型的矩阵，采用链式存储结构表示三元组的线性表更为恰当。

**十字链表**

设行指针数组和列指针数组，分别指向每行、列第一个非零元。

**其中：row域存储非零元素的行号；col域存储非零元素的列号；v域存储本元素的值；right是行指针域，用来指向本行中下一个非零元素；down是列指针域，用来指向本列中下一个非零元素。**

节省空间也可以不要头节点,判断一下null. 

因为非零元素结点的值域是datatype类型，而在表头结点中需要一个指针类型才能把表头结点链成一个单循环链表。为了使整个结构的结点一致，我们规定表头结点和其它结点有同样的结构，因此该域用一个联合来表示

```
typedef double MatrixValue;

typedef struct OLNode {
    int row, col;   /* 该非零元的行和列下标 */
    MatrixValue val;    /* 该非零元的值 */
    struct OLNode *down, *right;    /* 该非零元所在行表和列表的后继链域 */ 
} OLNode, *OLink;

typedef struct {
    OLNode *rhead, *chead;  /* 行表头和列表头的指针 */ 
    int mu, nu, tu; /* 矩阵的行数、列数及非零元个数 */ 
} OList;    /* 十字链表矩阵结构 */
```

建立 十字链表A

首先输入的信息是：m（A的行数），n（A的列数），t（非零项的数目），紧跟着输入的是t个形如（i,j,aij）的三元组。

算法的设计思想：

- 首先建立每行（每列）只有头结点的空链表，并建立起这些头结点拉成的循环链表；
- 然后每输入一个三元组（i，j，aij），则将其结点按其列号的大小插入到第i个行链表中去，同时也按其行号的大小将该结点插入到第j个列链表中去。
- 在算法中将利用一个辅助数组 hd[s+1]，hd[i]指向第i行(第i列)链表的头结点。这样做可以在建立链表时随机地访问任何一行（列），为建表带来方便。

```
OList olink_create(int mu, int nu, int tu) {    /* 建立十字链表 */
    OList olist;
    OLink p, q;
    int i, row, col;
    MatrixValue val;
    olist.rhead = (OLNode *)malloc(sizeof(OLNode)*mu);
    for(i = 0; i < mu; i++)
        olist.rhead[i].right = NULL;
    olist.chead = (OLNode *)malloc(sizeof(OLNode)*nu);
    for(i = 0; i < nu; i++)
        olist.chead[i].down = NULL;
    olist.tu = tu;
    olist.mu = mu;
    olist.nu = nu;
    for(i = 1; i <= tu; i++) {
        printf("请输入行号，列号，数值：");
        scanf("%d,%d,%lf", &row, &col, &val);//作业不用写用户输入, 就设置好. 
        p = olnode_setvalue(row, col, val);
        q = &(olist.rhead[row-1]);
        while(q->right != NULL && q->right->col < col)  /* 将p插入行链中 */
            q = q->right;         
        p->right = q->right;
        q->right = p;
        q = &(olist.chead[col-1]);
        while(q->down != NULL && q->down->row < row)   /* 再将p插入列链中 */
            q = q->down;
        p->down = q->down;
        q->down = p;
    }
    return olist;
}
```



#### 十字链表稀疏矩阵加法

因此当B加到A上时，对A十字链表的当前结点来说，对应下列四种情况：

- 改变结点的值
- 删除一个结点
- aij不变
- 插入一个新结点

**整个运算从矩阵的第一行起逐行进行。对每一行都从行表的头结点出发，分别找到A和B在该行中的第一个非零元素结点后开始比较，然后按四种不同情况分别处理。**

```
OL_SPMatrix olsm_mult(OL_SPMatrix A, OL_SPMatrix B) {
    OL_SPMatrix M;
    OLink p, q, qa, qb, pre;     
    int i, j;
    ElementType x;
    if(A.nu != B.mu) {  /* 判断A矩阵列数是否等于B矩阵行数 */
        printf("Error:Size mismatch");
        return M;
    }
    M.mu = A.mu; 
    M.nu = B.nu;
    M.rhead = (OLNode *)malloc(sizeof(OLNode)*M.mu);
    for(i = 0; i < M.mu; i++)
        M.rhead[i].right = NULL;
    M.chead = (OLNode *)malloc(sizeof(OLNode)*M.nu);
    for(i = 0; i < M.nu; i++)
        M.chead[i].down = NULL;  
    for(i = 1; i <= M.mu; i++) {
        pre = &(M.rhead[i-1]);
        for(j = 1; j <= M.nu; j++) {
            qa = A.rhead[i-1].right;
            qb = B.chead[j-1].down;
            x = 0;
            while(qa != NULL && qb != NULL) {   
                if(qa->col < qb->row)
                    qa = qa->right;
                else if(qa->col > qb->row)
                    qb = qb->down;
                else {  /* 有列号与行号相同的元素才相乘 */
                    x = x+qa->val*qb->val;
                    qa = qa->right;
                    qb = qb->down;
                }
            }
            if(x) {
                p = olnode_setvalue(i, j, x);
                pre->right = p; /* 将p插入到第i行中 */
                pre = p;
                q = &(M.chead[j-1]);
                while(q->down != NULL)
                    q = q->down;
                q->down = p;    /* 将p插入到第j列中 */
            }
        }
    }
    return M;
}
```

作业: 用十字链表存储结稀疏矩阵，并完成：

- 清晰的注释
- 遍历十字链表（输出矩阵到屏幕）
- 矩阵的转置、相加
- 矩阵相乘
- 用实例验证上面功能的正确性

实际上计算用lapack 和 blas库. 只有存储的时候可能自己写个存储的代码.



### 第四周



#### 怎么学习新语言

首先学习的话 你就把官方的文档给通读一遍,至少你要知道可以去哪里找api,

然后呢 你要用这个语言 实现一个具体的任务

 我们是要模仿 因为我们不知道最佳的实践是什么

#### 怎么选择库:

首先呢 看用的人多不多 然后呢看，有没有相关的功能,看看他的开发团队多不多,看看他用的库是不是和我们用的库平时用的库差不多



#### Rust:

老师用idea写rust, 文档甚至还会编译的时候 会检查会不通过

结构体怎么做哈希啊？一般是用她的地址,那就用这些内容进行哈希，如果你要判断内容的话，要重载

基数排序的话，就先用最后一位，然后再用第二位，然后再用第三位 