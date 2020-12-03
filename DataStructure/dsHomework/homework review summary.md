# 考试复习



### homework1

1.The major task of algorithm analysis is to analyze the time complexity and the space complexity. √ 

2.The Fibonacci number sequence {*F**N*} is defined as: *F*0=0, *F*1=1, *F**N*=*F**N*−1+*F**N*−2, *N*=2, 3, .... The time complexity of the function which calculates *F**N* recursively is Θ(*N*!).    X

3.递归方程：T(n) = 3T(n/3) + 1, n>1, T(1) = 1

应该是3的logN 次, 时间复杂度为 N. 

### homework2

1.For a sequentially stored linear list of length *N*, the time complexities for deleting the first element and inserting the last element are *O*(1) and *O*(*N*), respectively.    X 

 a sequentially stored linear list of length ,顺序存储的线性表支持随机存取，所以查询的时间是常数时间，但插入需要把后面每一个元素的位置都进行调整，所以是线性时间。 插入最后一个 时间为O(1).

2.If a linear list is represented by a linked list, the addresses of the elements in the memory must be consecutive(连续的). X 

3, 循环队列, 不能 rear == front. 队列满时rear == front -1. enqueue时rear增加, dequeue front 增加.

#### HW4

There exists a binary tree with 2016 nodes in total, and with 16 nodes having only one child.X

n0+n1+n2 =2016=1+0*n0+1*n1+2*n2 

选择题的话,可以 画一个出来,然后看看.



HW5

In a binary search tree which contains several integer keys including 4, 5, and 6, if 4 and 6 are on the same level, then 5 must be their parent. X

不是能有两个5, 而是可以很高.