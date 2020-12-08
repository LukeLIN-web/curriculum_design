# 排序SORTING

hash排序不通过比较, 



### 插入排序

把A[j-1] 往后移动, 插入

最坏情况O(N^2)

最好 线性





一个array中平均的逆序对是 N(N-1)/4 个, 最多 N(N-1)/2个.



### SHELLsort

定义增量 h1 < h2 <  ... <ht

hk-sort at each phase 

h5  , 一次五个五个移动

注意不能推翻之前 步长做的sort.

'最坏 O(N^2)



Hibbard 增量序列.

最坏O( N^(3/2) ) 

平均O( N^(5/4) ) 