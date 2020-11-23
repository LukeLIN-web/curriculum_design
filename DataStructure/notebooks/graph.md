## 图

### 定义

G::= graph, V = V(G) ::=  finite nonempty set of vertices(顶点), E = E(G) = finite set of edges.



##### 限制:

1. 不用考虑多重边.
2. 不用考虑自循环.(i-> i 是不可能的)

##### 基本术语

完全图 complete graph 

有最多的边. 边的数量有向图是 n(n-1)  无向图是 n(n-1)  /2

vi -> vj

vi is adjacent to vj, vj is adjacent(与…毗连的；邻近的) from vi; 

<vi , vj> is incident(事件) on vi and vj;

联通分量: 

无向图的极大连通子图称为G的**连通分量**( Connected Component)。任何[连通图](https://baike.baidu.com/item/连通图)的连通分量只有一个，即是其自身，非连通的[无向图](https://baike.baidu.com/item/无向图)有多个连通分量。 



连通图: 每一个顶点都是connected.  

强连通图:   有向图每一个顶点都是互相可以有路径到达



in degree  进来的边

out degree 出去的边

一个图所有degree 加起来/2 就是总边数

##### 图的表示

数组法

```c
adj_mat[i][j] = 1 ;
    //无向图,adj_mat是对称的,可以存在数组中.

```

链表法  adjacent list

```c
// 有向图可以看出outdegree,需要 求indegree
//建立一个 反向的lists
```

adjacent multilists

一条边 数据结构为  {mark, v1,v2}

mark可以用来看这条边有没有统计过



##### 定义

partial order::=  一个precedence relation both 传递而且irreflexive自反.(i-> i 是不可能的)

DAG 图 Directed Acyclic Graph : 有向的非循环图.

topological(拓扑) order:  前置的,在linear order上也是在前面

topological order是不唯一的

**Test an AOV for feasibility, and generate a topological order if possible.**

```c
void Topsort( Graph G )
{   int  Counter;
    Vertex  V, W;
    for ( Counter = 0; Counter < NumVertex; Counter ++ ) {
	V = FindNewVertexOfDegreeZero( );
	if ( V == NotAVertex ) {
	    Error ( “Graph has a cycle” );   break;  }
	TopNum[ V ] = Counter; /* or output V */
	for ( each W adjacent from V )
	    Indegree[ W ] – – ;
    }
}
//T = O( |V|2 )

```

不用每次都搜索一遍,

改进: **Keep all the unassigned vertices of degree 0 in a special box (queue or stack).**

```c
void Topsort( Graph G )
{   Queue  Q;
    int  Counter = 0;
    Vertex  V, W;
    Q = CreateQueue( NumVertex );  MakeEmpty( Q );
    for ( each vertex V )
	if ( Indegree[ V ] == 0 )   Enqueue( V, Q );
 //然后基于队列操作
    while ( !IsEmpty( Q ) ) {
	V = Dequeue( Q );
	TopNum[ V ] = ++ Counter; /* assign next */
	for ( each W adjacent to V )
	    if ( – – Indegree[ W ] == 0 )  Enqueue( W, Q );
    }  /* end-while */
    if ( Counter != NumVertex )
	Error( “Graph has a cycle” );
    DisposeQueue( Q ); /* free memory */
}
//最后所有都在topological sort
```

### 最短路径算法

#### single source 最短路径

从0开始找,宽度优先

把距离为0的点都找了.记录下来,然后



