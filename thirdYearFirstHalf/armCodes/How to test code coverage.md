# How to test code coverage

1. Visual stdio 有代码测试, 需要enterprise 企业版. 
2. https://www.cnblogs.com/KID-XiaoYuan/p/13266700.html说的比较详细了  . GCOV 包括在gcc中, gcc安装以及 GCOVR安装 

https://www.jianshu.com/p/db7b8fc7a7ca 这里提供了**python 写的 lcov 脚本**

https://www.jianshu.com/p/ff24a81f3637 这里看安装Mingw也就是gcc

然后

`g++ -fprofile-arcs -ftest-coverage -fPIC -O0 needTest.cpp -o program`

```bash
./program
gcovr -r .
```

就可以了

进一步我们想要得到更为详细的代码分析报告，使用如下命令生成关于整个项目的测试结果。（因为测试用例只有一个CPP文件所以结果只有一个文件，后续会用复杂的项目进一步举例说明）

gcovr -r . --html --html-details -o example-html-details.html

1. 完全linux 环境下可以用这个方法 , https://blog.csdn.net/gatieme/article/details/78368667  我因为有math.h头文件在window, 移过去还有很多依赖, 所以决定在window 进行gcov.