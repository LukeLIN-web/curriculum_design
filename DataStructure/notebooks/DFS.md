# DFS的应用



```cpp
visited[V] = true;
for(each W adjacent to V){
    if(!visited[W])
        DFS(W);
}
```



## 双连通性biconnectivity

一个双连通component is a maximal biconnected subgraph

1 去掉后不再连通, 那1就是割点ariticulation point.

#### 找到双连通component 

Using depth first search to obtain a spanning tree of G

随意从某一个顶点开始, 



back edge

## 判断是否是割点

note : if u is an ancestor of v, then Num(u) < Num(v).

root is 割点 , <=> 他有at least 两个孩子

其他vertex u是一个割点, <=> u  has at least 1 child. and 不可能 move down 至少一步 and jump up to u的祖先. 

或者  u  has at least 1 child 并且low(child) >= num(u)

##### low的定义

 计算一个low  ,back回去最小的值是多少.

可以直接返回到root, low就是0 .

 

num的值是编号的.

spinning tree 生成每个low 的值, 然后判断是否是割点.

```cpp
try all vertex u, if u hasnt been visited, DFS(u)

DFS(u), initiate num[u] = low[u] = DFSCount

  try all neighbor v of u

    if v is free, DFS(v)

      low[u] = min(low[u], low[v])

      check the condition

    else low[u] = min(low[u], num[v])
```





## Euler circuits

一笔画问题,

### Euler tour , 一笔画完

刚好有两个是奇数的,

### Euler circuit  一笔画完并且结束在起点

每个顶点有偶数个度



可以用一个链表记录路径, 一个指针指向最后scanned的边.

T = O(|E|+|V|)  , 边全部一遍, 顶点不止一遍

Hamiliton cycle是一个NP问题