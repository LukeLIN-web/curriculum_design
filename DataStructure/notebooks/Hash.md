# Hash



符号表 symbol table = 字典, 编译器看看字典里类型. 比如int a.



collision:  两个hash到一起了.

元素个数n = 10, 

loading density factor λ = 10/(26*2)   26 是 bucket.  2 是slot个数.

hash 应该是 unbiased ,uniform, 最好每个概率相等. 

keep a list of all keys that hash to same value 



### 3 separate chaining 

#### create an empty table

```

申请
先申请thelists和tablesize.
tablesize = 一个素数
thelists = malloc(sizeof(list)* tablesize)




```

find a key from hash table 

insert a key 

```
find// 计算了一次hash函数,速度要求高或许可以少调用一次hash.
如果find不到
malloc (sizeof(struct ListNode));

L = H->TheLists[Hash(Key,H->tablesize)];
```

让loading density factor λ  = 1 ,也就是减少bucket空余, table size接近元素个数.



### 4 哈希碰撞（hash collision）的解决方式

#### open addressing开放寻址法

不产生下一个list, 而是找另一个cell. 

```
while collision{
index = hash(key)+f(i);
如果table满了, break;
i++;
}

```

linear probing( 探查性的)

线性探查. f(i) = i;

平方探查 f(i) = i^2;

- 线性探测器（Linear Probing）
- 二次探测法（Quadratic Probing）
- 随机探测法
- 双散列（Double hashing）
- 再哈希法
- 建立一个公共溢出区

