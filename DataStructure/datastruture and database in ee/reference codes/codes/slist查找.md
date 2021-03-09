### 查找
### （1）按序号查找
<pre><code>SListNode * slist_get(SListNode * list,int i);</code></pre>

**算法介绍：**从链表的第一个结点开始，判断当前结点是否为第$i$个。若是，返回该结点的指针，否则继续判断下一个结点，直到表结束。没有第$i$个结点时返回空。

程序：
<pre><code>SListNode * slist_get(SListNode * list, int i) {
    SListNode * p = list;
    int j = 1;
    while(p->next != NULL && i > j) {
        p = p->next;
        j++;
    }
    if(j == i)
        return p;
    else
        return NULL;
}</code></pre>
    
### （2）按值查找

<pre><code>SListNode * slist_find_data(SListNode * list,SListEqualFunc callback,SListValue data);</code></pre>

**算法介绍：**从链表的第一个结点开始，判断当前结点存储的值是否等于$data$，若是，返回该结点的指针，否则继续判断下一个结点，直到表结束。找不到时返回空。$callback$是比较链表中两个数据是否相等的函数。

程序：

<pre><code>SListNode * slist_find_data(SListNode * list, SListEqualFunc callback, SListValue data) {
    SListNode * rover;
    //遍历链表，直到找到存有指定数据的结点 
    for (rover = list; rover != NULL; rover = rover->next) {
        if (callback(rover->data, data) != 0) {
            return rover;
        }
    }
    return NULL;
}</code></pre>

两种算法的时间复杂度均为$O(n)$。