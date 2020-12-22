# 排序SORTING

hash排序不通过比较, 



### 插入排序

从第一个元素开始，该元素可以认为已经被排序;

取出下一个元素，在已经排序的元素序列中从后向前扫描；

如果该元素（已排序）大于新元素，将该元素的值赋值给新元素；循环此步骤,直到不大于新元素;

一趟出来前面变为有序,再选取下一个元素;

把A[j-1] 往后移动, 插入

最坏情况O(N^2)

最好 线性





一个array中平均的逆序对是 N(N-1)/4 个, 最多 N(N-1)/2个.



### SHELLsort

希尔排序(Shell's Sort)是插入排序的一种又称“缩小增量排序”（Diminishing Increment Sort），
是直接插入排序算法的一种更高效的改进版本。希尔排序是非稳定排序算法。
由于多次插入排序，我们知道一次插入排序是稳定的，不会改变相同元素的相对顺序，但在不同的插入排序过程中，相同的元素可能在各自的插入排序中移动，最后其稳定性就会被打乱，所以shell排序是不稳定的。

过程： 第一个和加步长个交换，  然后看看 +2 步长 往前交换，然后看看 +3 步长 往前交换  到底了
然后第二个，  加1 步长往前交换，  然后看看 +2 步长往前交换。
也就是所有距离为d1的倍数的记录放在同一个组中。先在各组内进行直接插入排序；

定义增量 h1 < h2 <  ... <ht

hk-sort at each phase 

h5  , 一次五个五个移动

注意不能推翻之前 步长做的sort.

'最坏 O(N^2)

Hibbard 增量序列.

最坏O( N^(3/2) ) 

平均O( N^(5/4) ) 

#### 优劣

不需要大量的辅助空间，和归并排序一样容易实现。希尔排序是基于插入排序的一种算法， 在此算法基础之上增加了一个新的特性，提高了效率。
希尔排序的时间的时间复杂度为O(  )，希尔排序时间复杂度的下界是n*log2n。希尔排序没有快速排序算法快 O(n(logn))，
因此中等大小规模表现良好，对规模非常大的数据排序不是最优选择。但是比O(  )复杂度的算法快得多。并且希尔排序非常容易实现，
算法代码短而简单。 此外，希尔算法在最坏的情况下和平均情况下执行效率相差不是很多，与此同时快速排序在最坏的情况下执行的效率会非常差。
专家们提倡，几乎任何排序工作在开始时都可以用希尔排序，若在实际使用中证明它不够快，再改成快速排序这样更高级的排序算法. 



### heapsort

堆排序空间为O（1）
就是提取最大， 然后堆向下， 然后提取最大， 然后堆向下。

不需要额外的空间,  先build heap

```c
  for(i = N/2;i>=0; i-- )
      PercDown(A,i,N);// build heap
 for(i= n-1; i>0 ; i--){
     swap(A[0],A[i]);// deletemax 取出来就.
     PercDown(A,0,i)
 }
```

O(N loglogN)



### mergesort 归并排序

递归分成小任务, 然后合起来.  需要O(N) 额外空间   作为临时数组

 time complexity : O(N)

void Msort{

Msort(前一半)  //递归不断拆成2个, 然后合起来. 

Msort(后一半) // T(N/2)

Merge(两个)  //O(N)

}



归并排序的效率达到了巅峰：时间复杂度为O(nlogn)，这是基于比较的排序算法所能达到的最高境界.
公式：T[n]=2T[n/2]+O(n);
最终得出结果为：T[n]=O(nlogn); 
因为不管元素在什么情况下都要做出这些步骤，所花销的时间是不变的，所以该算法的最优时间复杂度和最差时间复杂度以及平均复杂度是一致的：O（nlogn）。
$$
T(N ) = 2^k(N/2^k) +k*O(N)
= N*T(1) +logN*O(N)
=O(N+NlogN)
$$
也有iterative version. 



归并排序是一种稳定的算法（即在排序过程中大小相同的元素能够保持排序前的顺序，3212升序排序结果是1223，排序前后两个2的顺序不变），这一点在某些场景下至关重要
归并排序是最常用的外部排序方法（当待排序的记录放在外存上，内存装不下全部数据时，归并排序仍然适用.）在external sorting很有用. 例如 在把多个外存磁盘阵列 合起来读取到一个存储空间的算法.

#### 缺点：

拷贝比较慢, 而且需要额外的空间, 不适合internal sorting,  归并排序需要O(n)的辅助空间，而与之效率相同的快排和堆排分别需要O(logn)和O(1)的辅助空间，在同类算法中归并排序的空间复杂度略高

### quicksort

实践中最快的排序算法.

选取一个作为pivot ,

best case T(N ) =  O(N logN )

pivot = A[0]   is a wrong way 

a safe maneuver : pivot is a random  . but generation is time expensive 

median elminate wrong way 5% time. 

小数组 N<20 , insertion sort比quick sort 更快.  if(i+cutoff)< right  qsort  else qsort



### Sorting 大结构

不交换所有变量而是交换指向结构的指针.

table sort.



### a general lower bound for sorting

Ω(N logN)

N个元素, N!个不同结果, 

thus, 决策树 必须有N! leaves 

高度是K, 
$$
N! <= 2^{k-1}
$$
=>  k>= log(N!)+1
$$
N! >= (N/2)^{(N/2)}   =>  log(N!) >= (N/2)log{(N/2)}
$$


### bucket sort and radix sort



bucket sort 建1000个桶 , 

radix sort 建10个桶, 按最低位排序.  然后按十位排序. 按百位 T= O(P+B) P是pass  = 3 pass,

B 是bucket 的数量, B =  10 . 在线性时间内排序.



MSD  most significant digit sort  4个桶,每个桶可以独立排

LSD 必须在前一次排序基础上排序.

LSD总是比MSD快吗? 不一定

