typedef void * ArrayListValue;	/* 指向数组中数据类型的指针. */

/* 动态数组结构，使用arraylist_new函数来创建新的动态数组. */
typedef struct _ArrayList ArrayList;

/* 定义动态数组结构. */
struct _ArrayList {
	ArrayListValue *data;	/* 数组的访问入口. */
	unsigned int length;	/* 数组中已存储的数据数. */
	unsigned int _alloced;	/* 数组的最大长度 */
};

/* 比较数组中的两个数据是否相等.相等返回非零值，不等返回零. */
typedef int (*ArrayListEqualFunc)(ArrayListValue value1,
                                  ArrayListValue value2);

/* 比较数组中的两个数据 */
typedef int (*ArrayListCompareFunc)(ArrayListValue value1,
                                    ArrayListValue value2);

/* 创建一个新的动态数组.传入初始化函数最初分配给动态数组的内存大小，若length被赋予零或负值，就使用一个合理的默认大小. */
ArrayList *arraylist_new(unsigned int length);

/* 销毁动态数组并且释放其占用的内存. */
void arraylist_free(ArrayList *arraylist);

/* 在动态数组的尾部添加一个数据. */
int arraylist_append(ArrayList *arraylist, ArrayListValue data);

/* 在动态数组的头部添加一个数据. */
int arraylist_prepend(ArrayList *arraylist, ArrayListValue data);

/* 删除动态数组中指定下标的内容.index是被清除内容所在的下标. */
void arraylist_remove(ArrayList *arraylist, unsigned int index);

/* 清除动态数组中给定范围的内容.index是被清除的范围在数组中的下标起始点.length是被清除的范围的长度. */
void arraylist_remove_range(ArrayList *arraylist, unsigned int index,
                            unsigned int length);

/* 在指定的下标位置插入一个数据.插入点的下标受动态数组的大小限制. */
int arraylist_insert(ArrayList *arraylist, unsigned int index,
                     ArrayListValue data);

/* 在动态数组中找到特定数据的最小下标.Callback用于比较数组中的数据与待搜索数据. */
int arraylist_index_of(ArrayList *arraylist,ArrayListEqualFunc callback,
                       ArrayListValue data);

/* 清空动态数组中的内容. */
void arraylist_clear(ArrayList *arraylist);

/* 对动态数组进行排序.compare_func是排序过程中用来比较数据的函数. */
void arraylist_sort(ArrayList *arraylist, ArrayListCompareFunc compare_func);