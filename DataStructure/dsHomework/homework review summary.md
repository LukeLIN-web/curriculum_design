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

#### HW3



#### HW4

There exists a binary tree with 2016 nodes in total, and with 16 nodes having only one child.X

n0+n1+n2 =2016=1+0*n0+1*n1+2*n2 

发现除不尽. 

选择题的话,可以 画一个出来,然后看看.



#### HW5

In a binary search tree which contains several integer keys including 4, 5, and 6, if 4 and 6 are on the same level, then 5 must be their parent. X

不是能有两个5, 而是可以很高.



#### HW6

根据前序遍历为第一个, 然后找到中序遍历中的点,分成两块.

 选择题6

If a binary search tree of *N* nodes is complete, which one of the following statements is FALSE?

答案: C 选项 the maximum key must be at a leaf node.



#### HW 8:

不连通, 35个边. 

答案: 至少10个顶点

#### HW11

 Apply DFS to a directed acyclic graph, and output the vertex before the end of each recursion. The output sequence will be:

答案: reversely topologically sorted



#### HW 12

堆排序 extra space 复杂度为O(1);

#### HW13

题一If there are less than 20 inversions in an integer array, the Quick Sort will be the best method among Quick Sort, Heap Sort and Insertion Sort. 错的.  数组长度越大, 快排效果越好.

题二Among the following sorting methods, which ones will be slowed down if we store the elements in a linked structure instead of a sequential structure?

1 Insertion sort; 2. Selection Sort; 3. Bubble sort; 4. Shell sort; 5. Heap sort

链表查询较慢, 

答案: D Shell sort;  Heap sort是在数组中, heap本身在数组中, shell也是在数组中. 

题三 During the sorting, processing every element which is not yet at its final position is called a "run". Which of the following cannot be the result after the second run of quick sort?

快速排序每一轮的过程, 观察有几个元素在正确的位置, 每轮当分割点的元素一定会在正确的位置. 

答案: D 三个pivot

#### HW14

The average search time of searching a hash table with *N* elements is:

答案是D  cannot be determined