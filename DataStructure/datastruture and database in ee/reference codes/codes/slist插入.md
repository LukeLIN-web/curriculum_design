### 插入
**算法介绍：**设$p$指向单链表中某结点，$newnode$指向待插入的值为$data$的新节点。若将$\*newnode$插入到$\*p$的后面，如图？所示，进行的操作如下：

<pre><code>newnode->next = p->next;
p->next = newnode;</code></pre>   

注意操作的顺序不能交换。若将$\*newnode$插入到$\*p$的前面，需要找到$\*p$的前驱$\*q$，然后再在$\*q$之后插入$\*newnode$，如图？所示。设单链表头指针为$list$，进行的操作如下：

<pre><code>q = list;
while(q->next != p)
    q = q->next;     //找*p的前驱
newnode->next = q->next;
q->next = newnode;</code></pre>

后插操作的时间复杂度为$O(1)$，前插操作的时间复杂度为$O(n)$。但实际上我们更关心数据之间的逻辑关系，所以前插操作仍然可以先把$\*newnode$插入到$\*p$的后面，再将$p->data$与$newnode->data$交换。这样既满足了逻辑关系，也能使时间复杂度为$O(1)$。

<pre><code>//在单链表的第i个位置上插入值为data的结点
int slist_insert(SListNode *list,int i,datatype data);</code></pre>

**算法思路：**

1. 寻找第$i-1$个结点，若存在继续2，否则结束。
2. 申请新结点并赋值。
3. 将新结点插入，结束。

<pre><code>int slist_insert(SListNode * list,int i,datatype data) {
    SListNode * p, * newnode;
    p = slist_get(list,i - 1);    //查找第i-1个结点
    if(p == NULL)
        return 0;
    else {
        newnode = (SListNode *)malloc(sizeof(SListNode));    //申请结点空间
        newnode->data = data;
        newnode->next = p->next;
        p->next = newnode;
        return 1;
    }
}</code></pre>