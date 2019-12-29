在此存放我在大学阶段所写的所有课程设计题目和代码

- OOP(C++)-面向对象程序设计：教室管理系统
- C-程序设计实践：小型超市库存与销售管理系统
- OS-操作系统课程设计：动态分区分配算法实现

----------


#### OOP(C++)-面向对象课程设计

##### 题目
实现一个简单的教室管理系统，系统基本功能包括
1) 教室信息维护：教室编号、类型、座位数等基本信息的维护；
2) 查询功能：查询满足指定条件的教室信息；
3) 预约功能：根据查询结果对指定教室进行预约操作；
4) 统计功能：统计各类教室的情况。

##### 完成时间
大二上学期19周（2018-2）

#### 运行截图
![](\img\cpp0.jpg)


----------


#### 程序设计实践课程设计（补修）

##### 题目

用C语言开发一个小型超市库存与销售管理系统。

【数据结构】

- 库存数据文件。每个商品的信息包含：商品编号，商品名称，进价，建议售价，生产厂商，库存数量；

- 销售数据文件。每个商品的信息包含：商品编号，商品名称，售价，销售数量，销售日期；

- 用户数据文件。每个用户的信息包括：用户账号，密码，权限级别（区别系统管理员用户和普通用户）。

【系统实现功能】

1、用户管理（操作用户数据文件）。

- 高级用户（超市管理者）：具有所有功能，同时可以添加用户、删除用户。创建新用户后，将普通用户信息存储到文件“user.dat”中。

- 普通用户（售货员）：可执行销售业务处理和查询功能。

2、进货&库存业务管理（操作库存数据文件）。根据商品编号查找相应商品，如果不存在，执行添加操作 ；如果商品已存在，根据进货数量修改商品数量。

3、销售业务处理（操作库存数据文件和销售数据文件）。用户在销售数据文件中添加销售记录，同时更新库存数据文件的相应商品的信息。

4、查询功能。支持以下几种查询方式：

- 按商品名称（精确查找，或模糊查找）查询商品基本信息（商品名、售价、库存）

- 按商品名称和生产厂商（多条件查询）查询商品基本信息（商品名、售价、库存）；

- 按销售日期查询某一天销售的情况。

5、功能扩展。可以按照自己对商品库存与销售系统的理解和解决问题的程度对系统进行扩展。比如：

- 支持商品批量入库（从文件中导入）。

- 按照固定的日期范围统计所销售的货物信息（商品名称，销售总量，收益率），像，月销售情况统计，季度销售情况统计，年度销售情况统计。

- 按照销售量、销售利润等条件，统计指定日期范围内商品的销售情况。

##### 完成时间
大二下学期10周（2018-4）

#### 运行截图
![](\img\c0.jpg)

----------


#### 操作系统课程设计

##### 题目
用C语言实现动态分区分配过程alloc()和回收过程free()。其中，空闲分区通过空闲分区链表来管理，分别采用首次适应算法、循环首次适应算法、最佳适应算法、最坏适应算法进行内存块的分配和回收，同时显示内存块分配和回收后空闲内存分区链的情况。
##### 完成时间
2018/6/25至2018/6/29

#### 运行截图
![](\img\os0.jpg)


----------
