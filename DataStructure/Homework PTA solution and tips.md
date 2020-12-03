## 只写解法和注意点,代码网上有很多.

## 1.Evaluate Postfix Expression

Write a program to evaluate a postfix expression.  You only have to handle four kinds of operators: +, -, x, and /.

解法:

//如果遇到数字,用另一个数组记录这个数字,直到遇到下一个空格,就把数组里的东西转化为数字,并且清空数组.//把b截止使用atof函数 

//如果遇到 - 或+ , 如果下一个是数字,那就数组记录,如果下一个是空格,那就pop两个,加起来或减去. 

//如果遇到*或/,那就pop两个,如果top<1,那就不够,返回error,如果/0,那也error

//i++继续遍历,直到 '\0'

//如果 top为0, 那就输出数字, 否则就错误. 

**注意**: top是指向栈顶,还是栈顶上方一个空地址.

## 2.Pop Sequence

// m 从0 到6,是序列的循环变量,  m ==7时,序列就结束了,m is 序列的index, v从1到7, 是入栈的元素

​	// 首先, 保存输入序列,第一个data和1不同,那1入栈, 要入栈的元素2小于序列,那就继续入栈,直到大于序列.,如果栈满了还是和第一个不同,那就error

​	// 如果栈没满,peek = datam,那就pop出栈, 第二个和stack[top]相同,继续出栈,不相同,继续入栈,

​	// 直到判断到第N个,出栈成功,那就right.如果栈顶大于序列,那就error.中间栈满了或者top==-1了,那就error.

注意点: 

1. // st.peek 放在后面否则会有emptystack异常. 
2. System.out.println("判断序列data["+m); 来调试

判断题:

For a sequentially stored linear list of length *N*, the time complexities for deleting the first element and inserting the last element are *O*(1) and *O*(*N*), respectively.

答案是False

## 3.Isomorphic 同构树

为空 return 1. 

 是叶了,返回1. 

 否则判断子树 

给根结点, A左 =B左 && A右是否为B右. 如果是,返回1.如果不是返回0.

判断A右  =B左,  &&如果是,A左是否为B右

 A右  !=B左,返回0 ;

 如果分别只有一个,判断是否相等,是的话,返回1. 一个为两个一个为一个,返回0. (包括在上面的==情况) 

如果不等于, 0

## 4.Zigzagtree

二叉树zigzag遍历	

首先建立二叉树

/*build a Tree from postorder and inorder

​	后序遍历的最后一个数为根结点，根据这个根结点来划分中序遍历，将其分为左子树和右子树

​	②确定左右子树的中序遍历和后遍历中的界限,中序从0 - root为左, root+1 到最后为右. 后序0-root为左,root到postOrder.length-1 为右.

​	③递归调用

​	*/

然后zigzag,可以先简单用queue层次遍历,再加上stack来zigzag遍历.

/*要进行层次遍历，需要建立一个循环队列。先将二叉树头结点入队列，然后出队列，访问该结点，如果它有左子树

​	则将左子树的根结点入队:如果它有右子树，则将右子树的根结点入队。然后出队列，对出队结点访问，如此反复，直到队列为空为止。

​	z字形层次遍历是对层次遍历加上了一个限制条件（即相邻层，从左到右的遍历顺序相反），

​	我们取queue大小,就是上一层的结点数. for循环把这一层都加入进去,如果奇数层就第一个结点开始(因为上一层是偶数)先加右再加左.

​	如果偶数层就最后结点开始(因为上一层是奇数)先加左再加右.

​	一层结束深度增加,同时用一个栈,因为遍历下一层的数据 和输出这一层的数据  是刚好相反的..

​	data  arraylist是因为他最后不要空格, 所以全部保存了再输出. 不然stack其实就有正确答案了,最后多一个空格.

​	*/

## 5  judge red-black tree

[1135 Is It A Red-Black Tree(判断是否是红黑树)www.cnblogs.com![图标](https://pic3.zhimg.com/v2-a94ddbf603738f51d17d7732d322562e_180x120.jpg)](https://link.zhihu.com/?target=https%3A//www.cnblogs.com/keep23456/p/12507390.html)

首先我们根据前序表达式建立二叉树。然后判断是否为红黑树.

**如何判断二叉树。根据题目描述的性质，我们要进行如下三点判断** 
**1、根节点是否为正数** 
**2、节点为负数，节点的孩子是否为正数（这里判断当前节点的左右孩子是否为正数）** 
**3、从任一节点到叶子节点所有路径拥有相同的黑色节点** 

**此题包括二叉树的基本操作：BST建树、后序遍历求树高、先序遍历。**

**对于属性4，我使用递归，首先判断根，如果根为空，则返回正确，如果根为负，则判断左右值，如果根为正，则判断左子树和 正确的子树。**

​      **对于属性5，判断左路径和右路径的高度。 如果高度相同，则将判断两个子树。 如果它们不相同，那将是错误的。 查找高度的功能（如果为黑色，则为+1）。 注意，当判断发现高度的函数为空时，则无需写left == null或right == null判断，无需编写四种情况。**

我自己设计一些样例,发现不对,因为不是二叉树,或者不是红黑树,前序遍历不能确定一颗二叉树,.

改写成C，那就 一个是没有bool类型和max函数，一个是scanf需要占位符\n和&i，而不是nextint。

## 6 Percolate Up and Down

题目其实不难, 但是还是写了好久, 有一个错误, 每个值都要思考,写多了还是挺费脑子的.

//  最小堆的插入维护和删除维护 不断比较交换儿子与父亲的值。直到p小于0或者子节点大于父节点. 

void PercolateUp( int p, PriorityQueue H ){ 



//已经把叶节点存到【1】了 

//调整的过程是不断比较父亲与儿子的值，这里左右儿子都要比较，如果发现父节点大于子节点，父节点就下去. 

void PercolateDown( int p, PriorityQueue H ){



## 7.并查集

union by height   depth at most log2N+1

union by size   size用负数表示 ， 结点深度不会超过logN,

初始化：  把所有都设为－1，从 1开始设置，方便对应

union：  先找到根，然后数量相加，小的指向大的根。

大的根 + 小的根  = 总数量

  －3+ －2

find  如果是根（s【x】是负数），就返回x， 否则就去寻找根，还可以路径压缩。 return  s【x】 = Find（s【x】）



## 8.Bonus-2Social Clusters

int course[1010] ={ 0 };// at most 1000 hobbies init 

/*0. 每个社交圈的结点号是人的编号，而不是课程。课程是用来判断是否处在一个社交圈的。

\1. course[t]表示任意一个喜欢t活动的人的编号。

if当前的课程t，之前并没有人喜欢过，

then : course[t] = i，i为喜欢course[t]当前人的编号

例如1号喜欢3号活动，那就course【3】 = 1； 

\2. findFather(course[t])就是喜欢这个活动的人所处的社交圈子的根结点，

if 当前的课程t，之前有人喜欢过

then 合并根结点和当前人的编号的结点i。即Union(i, findFather(course[t]))，把它们处在同一个社交圈子里面



then // 输出总共几个簇,然后每个簇多少人. 

 再遍历一遍每个人，看看他们分属于那个集合，并给相应集合的人数+1

\3. isRoot[i]表示编号i的人是不是它自己社交圈子的根结点，

如果等于0表示不是根结点，如果不等于0，每次标记isRoot[findFather(i)]++，那

么isRoot保存的就是如果当前是根结点，那么这个社交圈里面的总人数

\4. isRoot中不为0的编号的个数cnt就是社交圈圈子的个数

最后遍历一遍看每个人是否 

\5. 把isRoot从大到小排列，输出前cnt个，就是社交圈人数的从大到小的输出顺序

*/