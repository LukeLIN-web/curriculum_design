



#### 断言

assert() 会对表达式`expression`进行检测：

- 如果`expression`的结果为 0（条件不成立），那么断言失败，表明程序出错，assert() 会向标准输出设备（一般是显示器）打印一条错误信息，并调用 abort() 函数终止程序的执行。
- 如果`expression`的结果为非 0（条件成立），那么断言成功，表明程序正确，assert() 不进行任何操作。

##### 智能指针

owner-> 

this->



lambda function 作为third argument to the std::sort() function .

implicitly隐含

```cpp
void TestHelloObject::processEvent()
{
    DPRINTF(TestHello, "Test Hello World! Processing the event!\n");
}

```

:: 是这个类下面的一个成员或者方法
声明了一个类A，类A里声明了一个成员函数void f()，但没有在类的声明里给出f的定义，那么在类外定义f时，就要写成void A::f()，表示这个f()函数是类A的成员函数。例如：
:  是继承这个类.

```cpp
TestHelloObject::TestHelloObject(TestHelloObjectParams *params) :
    SimObject(params), event(*this),
    myName(params->name),
    latency(params->time_to_wait),
    timesLeft(params->number_of_fires)
{
    DPRINTF(TestHello, "Created the test hello object with the name %s\n", myName);
}


```

这个叫初始化列表
就是调用构造函数时“构造函数:成员变量(初始值),成员变量(初始值)”的形式来对类中的成员变量进行赋值



##### 数据域

具有protected访问控制级别的[成员](https://baike.baidu.com/item/成员/3793854)是半公开的，外界无法直接访问这个控制级别的成员，但是[派生类](https://baike.baidu.com/item/派生类/9589520)的base[指针](https://baike.baidu.com/item/指针/2878304)（在c++中也可用[引用](https://baike.baidu.com/item/引用/184603)访问）可以获得访问能力。protected与[private](https://baike.baidu.com/item/private/940196)基本相似，只有在继承时有较大的区别。[继承](https://baike.baidu.com/item/继承/18871246)的类可以访问protected成员，但是不能访问private成员。



### STL库



#### map

unordered系列的容器。unordered_map记录元素的hash值，根据hash值判断元素是否相同。map相当于java中的TreeMap，unordered_map相当于HashMap。无论从查找、插入上来说，unordered_map的效率都优于hash_map，更优于map；而空间复杂度方面，hash_map最低，unordered_map次之，map最大。

```cpp
unordered_map<string,double>
18     myrecipe,
19     mypantry = {{"milk",2.0},{"flour",1.5}};
20 
21     /****************插入*****************/
22     pair<string,double> myshopping ("baking powder",0.3);
23     myrecipe.insert (myshopping);                        // 复制插入
24     myrecipe.insert (make_pair<string,double>("eggs",6.0)); // 移动插入
25     myrecipe.insert (mypantry.begin(), mypantry.end());  // 范围插入
26     myrecipe.insert ({{"sugar",0.8},{"salt",0.1}});    // 初始化数组插入(可以用二维一次插入多个元素，也可以用一维插入一个元素)
27     myrecipe["coffee"] = 10.0;  //数组形式插入
```



可以通过key 擦除, 



emplace_back() 和 push_back() 效果一样.

区别就在于底层实现的机制不同。push_back() 向容器尾部添加元素时，首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素）；而 emplace_back() 在实现时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程。



#### unordered_map 容器

| 成员方法 | 功能                                               |
| -------- | -------------------------------------------------- |
| begin()  | 返回指向容器中第一个键值对的正向迭代器。           |
| end()    | 返回指向容器中最后一个键值对之后位置的正向迭代器。 |
| bucket_count()     | 返回当前容器底层存储键值对时，使用桶（一个线性链表代表一个桶bucket）的数量。 |
| max_bucket_count() | 返回当前系统中，unordered_map 容器底层最多可以使用多少bucket。 |
| bucket_size(n)     |                       返回第 n 个bucket中存储键值对的数量。 |
| bucket(key)        |                  返回以 key 为键的键值对所在bucket的编号。 |

```cpp
pair<string,double> myshopping ("baking powder",0.3);
     myrecipe.insert (myshopping);                        // 复制插入
    myrecipe.insert (make_pair<string,double>("eggs",6.0)); // 移动插入
     myrecipe.insert (mypantry.begin(), mypantry.end());  // 范围插入
     myrecipe.insert ({{"sugar",0.8},{"salt",0.1}});    // 初始化数组插入(可以用二维一次插入多个元素，也可以用一维插入一个元素)
    myrecipe["coffee"] = 10.0;  //数组形式插入
```

通常，如果 *N* 是常数且很小，我们可以简单地使用一个数组将键存储在同一个桶中。如果 *N* 是可变的或很大，我们可能需要使用`高度平衡的二叉树`来代替。



#### std::advance

advance() 函数用于将迭代器前进（或者后退）指定长度的距离，

其中 it 指的是目标迭代器，n 通常为一个整数。

需要注意的是，如果 it 为输入迭代器或者前向迭代器，则 n 必须为一个正数，即表示将 it 右移（前进） n 个位置；反之，如果 it 为双向迭代器或者随机访问迭代器，则 n 为正数时表示将 it 右移（前进） n 个位置，n 为负数时表示将 it 左移（后退） n 个位置。

另外，根据 it 类型是否为随机访问迭代器，advance() 函数底层采用了不同的实现机制：

- 当 it 为随机访问迭代器时，由于该类型迭代器支持 p+n 或者 p-n（其中 p 就是一个随机访问迭代器）运算，advance() 函数底层采用的就是 it+n 操作实现的；
- 当 it 为其他类型迭代器时，它们仅支持进行 ++ 或者 -- 运算，这种情况下，advance() 函数底层是通过重复执行 n 个 ++ 或者 -- 操作实现的。


值得一提的是，advance() 函数定义在`<iterator>`头文件，并位于 std 命名空间中。因此，程序在使用该函数之前，应包含

```c++
#include <iterator>
```

advance() 函数本身不会检测 it 迭代器移动 n 个位置的可行性，如果 it 迭代器的移动位置超出了合理范围，it 迭代器的指向将无法保证，此时使用 *it 将会导致程序崩溃。

#### std::next

```cpp
#include <iostream> 

#include <iterator> 

#include <vector>

 int main() {    
 std::vector<int> v{1,2,3};    *// 返回 第二个元素（begin的第一个后继)*    

auto nx = std::next(v.begin());    *// 2*    

std::cout << *nx << std::endl;  
auto nx = std::next(it, 2);// it  -- 迭代指针

//   n  -- 向前进的元素个数，缺省默认为1 ,

  return 0; }
```



#### std::prev

使用方法与next相似，不同的是prev返回的是it的第n个前驱迭代指针



#### auto

```c++
1  auto a=1;
2  auto b='a';
3  auto s="abdc";
4  auto c;//这样使用时错误的，系统无法自动推断出变量类型
5   //下面为迭代指针使用，很方便
6  vector<int> vec;
7  auto it=vec.begin();
//定义变量时放在变量前，无需知道具体变量类型，系统可自行推断类型，减少编程工作，特别是在模板使用时，使用更方便。
1  template<typename InputIterator>
2     TreeNode *creatTree(InputIterator in_beg,InputIterator in_end...)
3     {
4        .....
5         auto inRootPos=find(in_beg,in_end,val);
6        ......
7     }
```

