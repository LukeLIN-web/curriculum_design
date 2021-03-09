### 删除
**算法介绍：**设$p$指向单链表中某结点，要删除$\*p$。如图？所示，要删除$\*p$,首先要找到$\*p$的前驱结点$\*q$，然后再进行如下操作：
<pre><code>q->next = p->next;
free(p);
</code></pre>

操作的时间复杂度为$O(n)$。若要删除$\*p$的后继结点，则可以直接完成：

<pre><code>s = p->next;
p->next = s->next;
free(s);</code></pre>

操作的时间复杂度为$O(1)$。

<pre><code>//删除单链表的第i个结点
sint slist_delete_node(SListNode * list,int i);</code></pre>

**算法思路:**

1. 寻找第$i-1$个结点，若存在继续2，否则结束。
2. 若存在第$i$个结点则继续3，否则结束。
3. 删除第$i$个结点，结束。

<pre><code>int slist_delete_node(SListNode * list,int i) {
    SListNode * p, * s;
    p = slist_get(list,i - 1);    //查找第i-1个结点
    if(p == NULL)
        return -1;
    else if(p->next == NULL)
        return -1;
    else {
        s = p->next;            //s指向第i个结点
        p->next = s->next;      //从链表中删除
        free(s);                //释放内存
        return 1;
    }
}

//删除一个结点 ,成功删除返回非零数，结点不存在返回零
int slist_remove_node(SListNode ** list, SListNode * node);      

int slist_remove_node(SListNode ** list, SListNode * node) {
    SListNode * rover;
    if (*list == NULL || node == NULL) {
        return 0;
    }
    if (*list == node) {            //删除头结点的情况操作不同 
        *list = node->next;
    } 
    else {
        rover = *list;
        //在链表中搜索待删除结点的前一个结点
        while (rover != NULL && rover->next != node) {
            rover = rover->next;
        }
        if (rover == NULL) {
            return 0;
        } 
        else {
            rover->next = node->next;
        }
    }
    free(node);        //释放结点内存 
    return 1;
}</code></pre>