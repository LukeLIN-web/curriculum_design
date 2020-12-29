



#### 断言

assert() 会对表达式`expression`进行检测：

- 如果`expression`的结果为 0（条件不成立），那么断言失败，表明程序出错，assert() 会向标准输出设备（一般是显示器）打印一条错误信息，并调用 abort() 函数终止程序的执行。
- 如果`expression`的结果为非 0（条件成立），那么断言成功，表明程序正确，assert() 不进行任何操作。

##### 智能指针

owner-> 

this->

shared_ptr也是对auto_ptr的一种改进，它的思路是，使用引用计数来管理指针。如果一个指针被多次使用了，那么引用计数就加一，如果减少一次使用，引用计数就减一。当引用计数变为0，那就可以真正地删除指针了。引用计数法的优点就是算法简单（在C++中只要几行代码就实现了），但是效率不高，且有循环引用这个巨大的坑。



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



   1 如果你需要高效的随即存取，而不在乎插入和删除的效率，使用vector 
   2 如果你需要大量的插入和删除，而不关心随即存取，则应使用list 
   3 如果你需要随即存取，而且关心两端数据的插入和删除，则应使用deque

#### map

https://www.w3cschool.cn/cpp/cpp-fu8l2ppt.html

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

emplace_back() 和 push_back() 效果一样.

区别就在于底层实现的机制不同。push_back() 向容器尾部添加元素时，首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素）；而 emplace_back() 在实现时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程。

怎么修改map的值?

最多的方法是先用eraser函数擦除，可以通过key 擦除, 然后我们再进行赋值

不要局部变量,其实全局变量设iterator也可以修改,用一个指针.

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



#### set

**为何map和set的插入删除效率比用其他序列容器高？**

大部分人说，很简单，因为对于关联容器来说，不需要做内存拷贝和内存移动。

- set以RBTree作为底层容器
- 所得元素的只有key没有value，value就是key
- 不允许出现键值重复
- 所有的元素都会被自动排序,利用set内部默认的compare函数，将整数从小到大排序，将字符串按字母序进行排序。
- 不能通过迭代器来改变set的值，因为set的值就是键, **set的元素可以插入、删除，但是不可更改。**

Set和Vector的区别在于Set不包含重复的数据。Set和Map的区别在于Set只含有Key，而Map有一个Key和Key所对应的Value两个元素。

我要让他按特定的排序, 该如何?

方法一: 可以通过定义结构体(或类)，并在其中重载()运算符，来自定义排序函数。然后，在定义set的时候，将结构体加入其中.

或者方法二,重载小于号, 重载要点：

 1 两个const

 2 两个不同的类必须能比较出大小来 

为什么不用重载等号set也能去重？

因为由A<B false ，B<A false 可推出A==B



#### vector

vector排序, 用自定义的结构体进行sort算法

这时候需要自己定义个比较函数，因为sort算法是基于容器中的元素是可以两两比较的，然后从小到大排序，所以要自定义怎么样才是小于（'<'）

错误: 排序后又没有排序了不知道为啥. 

因为你的 vt = vector 是复制了一份, 要直接取地址. auto产生的迭代器是const ,.`auto` 在进行类型推导时会默认使用**基础类型**，而非指针与引用，所以不能修改,只有在初始化时使用了显式的引用（如 `std::ref()`）时才会将类型变更为引用类型。

```cpp
  auto p1 = std::make_pair(names[1], std::ref(score[1]));
```

### 迭代器

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

#### std::move

1. C++ 标准库使用比如vector::push_back 等这类函数时,会对参数的对象进行复制,连数据也会复制.这就会造成对象内存的额外创建, 本来原意是想把参数push_back进去就行了,通过std::move，可以避免不必要的拷贝操作。
2. std::move是将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存的搬迁或者内存拷贝所以可以提高利用效率,改善性能.。

#### std::ref

std::ref函数就是为了解决在线程的创建中等过程的值拷贝问题



函数的返回值通常不能传给一个非const的引用，因为函数返回值通常也是一个临时变量，是一个右值。

#### auto

```c++
1  auto a=1;
2  auto b='a';
3  auto s="abdc";
4  auto c;//这样错误的，系统无法自动推断出变量类型
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

　在C++定义的容器类型中，只有vector和queue容器提供迭代器算数运算和除!=和==之外的关系运算.

```
true 和 false 并不是某某库做的 define，他们是 C/C++ 的关键字，是内置的布尔变量值。
实际上 bool 变量占用了 1 个字节的内存，当值为 false 的时候，
实际上存储的是 0x00,为 ture 时实际上存储的是 0x01
```

### 类和对象

#### 构造函数

定义构造函数时并没有在函数体中对成员变量一一赋值，其函数体为空（当然也可以有其他语句），而是在函数首部与函数体之间添加了一个冒号`:`，后面紧跟`m_name(name), m_age(age), m_score(score)`语句，这个语句的意思相当于函数体内部的`m_name = name; m_age = age; m_score = score;`语句，也是赋值的意思。使用构造函数初始化列表并没有效率上的优势，仅仅是书写方便，尤其是成员变量较多时，这种写法非常简单明了。

初始化列表可以用于全部成员变量，也可以只用于部分成员变量。

构造函数初始化列表还有一个很重要的作用，那就是初始化 const 成员变量。初始化 const 成员变量的唯一方法就是使用初始化列表。

#### 对象指针

在栈上创建出来的对象都有一个名字，比如 stu，使用指针指向它不是必须的。但是通过 new 创建出来的对象就不一样了，它在**堆上分配内存**，没有名字，只能得到一个指向它的指针，所以必须使用一个指针变量来接收这个指针，否则以后再也无法找到这个对象了，更没有办法使用它。也就是说，使用 new 在堆上创建出来的对象是匿名的，没法直接使用，必须要用一个指针指向它，再借助指针来访问它的成员变量或成员函数。

栈内存是程序自动管理的，不能使用 delete 删除在栈上创建的对象；堆内存由程序员管理，对象使用完毕后可以通过 delete 删除。在实际开发中，new 和 delete 往往成对出现，以保证及时删除不再使用的对象，防止无用内存堆积。



错误:调用不带对象参数的非静态成员函数。出现这个错误的原因是，类没有实例化 。