# c语言qsort函数
## 简介
qsort 是 C 语言标准库 <stdlib.h> 中提供的一个通用排序函数。
```C
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));
//qsort(数组地址，元素个数，sizeof(数据类型)，自定义比较函数)
//如下:
// 升序 (从小到大)
int cmp_int_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); 
}

// 降序 (从大到小)
int cmp_int_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a); 
}
```