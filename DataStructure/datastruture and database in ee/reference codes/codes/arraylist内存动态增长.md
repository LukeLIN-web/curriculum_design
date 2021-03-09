### arraylist的内存自动增长

**算法介绍：**$arraylist$的内存自动增长是通过$arraylist$_$enlarge$函数和判断过程实现的。$arraylist$_$enlarge$函数可以实现将动态数组已分配的内存空间扩展为原来的2倍，整数$newsize$表示内存扩展后的数组长度，使用$realloc$函数对$data$重新进行内存分配，分配的空间大小等于$newsize$乘以结构$ArrayListValue$的大小，最后再使$arraylist$中的$data$指针指向新的空间$data$，$newsize$赋值给_$alloced$。算法的时间复杂度为$O(1)$。

<pre><code>//数组扩展 
static int arraylist_enlarge(ArrayList * arraylist) {
    ArrayListValue * data;
    unsigned int newsize;
    //将已分配的数组内存空间扩展为原来的2倍
    newsize = arraylist->_alloced * 2; 
    //给数组重新分配新的内存空间 
    data = realloc(arraylist->data, sizeof(ArrayListValue) * newsize);
    if (data == NULL) {
        return 0;
    } 
    else {
        //这里是将arraylist的data指针指向新的data空间，arraylist中的_alloced表示
        //已分配的内存空间，内存扩展后的newsize应赋值给_alloced
        arraylist->data = data;
        arraylist->_alloced = newsize;
        return 1;
    }
}</code></pre>

**算法思路：**

1. 定义一个数据类型指针和一个整数，并将整数赋值为_$alloced$的两倍。
2. 使用$realloc$对新的数据类型指针分配扩大的内存空间。
3. 将动态数组的数据类型指针指向新的地址，_$alloced$数值翻倍。

上面这个函数在向动态数组中插入数据时，通过判断来决定是否调用。下面是在动态数组指定下标位置插入数据的函数代码：

<pre><code>//在指定下标处插入数据 
int arraylist_insert(ArrayList * arraylist, unsigned int index, ArrayListValue data) {
    //检查下标是否越界 
    if (index > arraylist->length) {
        return 0;
    } 
    //数组分配的内存不足时，调用函数扩展内存 
    if (arraylist->length + 1 > arraylist->_alloced) {
        if (!arraylist_enlarge(arraylist)) {
            return 0;
        }
    }
    //向后移动数组的内容
    //把待插入位置及之后的数组内容后移一位
    memmove(&arraylist->data[index + 1],
            &arraylist->data[index],
            (arraylist->length - index) * sizeof(ArrayListValue));
    //在下标为index的位置插入数据 
    arraylist->data[index] = data;
    ++arraylist->length;
    return 1;
}</code></pre> 