# python笔记

【python报错】Non-ASCII character '\xe5' 

解决方法：
在Python源文件的最开始一行，加入一句：

coding=UTF-8

或者

-*- coding:UTF-8 -*-



##### [python报错]"IndentationError: unexpected indent"的两三解决方法

这个是缩进错误，我们可以通过下面几步解决他：
首先检查代码是不是有错误的索引
如果没有，全都正确，可以看看是不是使用'''进行了整段的注释，如果是，一定要保证其与上下相邻代码缩进一致，而#就无所谓
如果还有错，使用notepad++打开文件，选择视图->显示符号->显示空格和制表符，然后查看是不是有空格与制表符混用的情况
vim可以用: set list 显示空格和制表符.
unexpected indent 就是说“n”是一个“意外的”缩进。也就是说，这里的问题就是指“n”是一个意外的缩进。通过查看源代码可知这里的确是缩进了一个字符位。
据此推断，我们把这句话的缩进取消，也就是顶格写，

##### [python报错]出现了AttributeError: object 'L2Cache' has no attribute 'connectCPUSideBus'

  (C++ object is not yet constructed, so wrapped C++ methods are unavail
对象“l2cache”没有属性 ,很多是说不要用跟系统库同样名字,这里则是因为之前的顶格写,导致没有定义到class中去.

##### 【python报错】TypeError: super(type, obj): obj must be an instance or subtype of type

class FooChild(FooParent):
    def __init__(self):
         super(FooChild,self)
 #首先找到 FooChild 的父类（就是类 FooParent），然后把类 FooChild 的对象转换为类 FooParent 的对象

##### Sccons

Scons是一个开放源码、以Python语言编码的自动化构建工具，可用来替代make编写复杂的makefile。并且scons是跨平台的，只要scons脚本写的好，可以在Linux和Windows下随意编译。
在Java的集成开发环境中，比如Eclipse、IDEA中，有常常有三种与编译相关的选项Compile、Make、Build三个选项。这三个选项最基本的功能都是完成编译过程。但又有很大的区别，区别如下：
1、Compile：只编译选定的目标，不管之前是否已经编译过。

2、Make：编译选定的目标，但是Make只编译上次编译变化过的文件，减少重复劳动，节省时间。（具体怎么检查未变化，这个就不用考虑了，IDE自己内部会搞定这些的）

3、Build：是对整个工程进行彻底的重新编译，而不管是否已经编译过。Build过程往往会生成发布包，这个具体要看对IDE的配置了，Build在实际中应用很少，因为开发时候基本上不用，发布生产时候一般都用ANT等工具来发布。Build因为要全部编译，还要执行打包等额外工作，因此时间较长。