# C++ 映射表 (Mapping Table) 核心知识点

在 C++ 中，映射表被称为**关联容器**，核心概念是存储**键值对 (Key-Value pairs)**。这与 Java 中的 `HashMap` 或 Python 中的字典 (`dict`) 是完全相同的概念。

C++ 标准模板库 (STL) 提供了两种最常用的映射表：`std::unordered_map` 和 `std::map`。为了追求极致的速度，日常开发和算法刷题中最常用的是 `std::unordered_map`。

## 1. 引入头文件与声明

使用映射表前，必须引入 `<unordered_map>` 或 `<map>` 头文件。

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // 声明一个键(Key)为 string 类型，值(Value)为 int 类型的无序映射表
    unordered_map<string, int> ageMap;
    return 0;
}
```
## 2. 插入与修改数据
最直观的操作方式是使用 [] 运算符。如果键不存在，会自动插入；如果键已存在，会覆盖原有的值。
```cpp
// 1. 使用 [] 运算符 (最常用)
ageMap["Alice"] = 20;  // 插入新键值对
ageMap["Alice"] = 21;  // 修改已有的值

// 2. 初始化列表 (C++11 特性，常用于预设静态数据)
unordered_map<char, int> romanMap = {
    {'I', 1},
    {'V', 5},
    {'X', 10}
};

// 3. 使用 insert() 方法
ageMap.insert({"Bob", 22});
```
## 3. 访问与查找数据（核心避坑点）
```cpp
// ❌ 危险操作：会意外插入 {"Charlie", 0}
// ageMap中不存在key为Charlie 会自动赋值为0
cout << ageMap["Charlie"] << endl; 

// ✅ 安全方法 A：使用 count()
// 返回该键在表中的数量 (对于 map 只能是 0 或 1)
if (ageMap.count("David") > 0) {
    cout << "David 存在！" << endl;
}

// ✅ 安全方法 B：使用 find()
// 返回一个迭代器，如果找不到则指向表的末尾 (end)
if (ageMap.find("Bob") != ageMap.end()) {
    cout << "Bob 的年龄是: " << ageMap["Bob"] << endl;
}
```
## 4. 遍历与删除元素
```cpp
//第一种：使用范围for
// 遍历：pair 是一个结构体，pair.first 是键，pair.second 是值
for (const auto& pair : romanMap) {
    cout << "字符: " << pair.first << ", 数值: " << pair.second << endl;
}
//第二种：使用迭代器
for (auto it = mp.begin(); it != mp.end(); ++it) {
    cout << it->first << " " << it->second << endl;
}

// 删除：使用 erase() 根据键移除对应的键值对
ageMap.erase("Alice");// 按 key 删除
mp.erase(it);      // 按迭代器删除
mp.clear();        // 清空
```
## 5.unordered_map 与 map 的核心区别
| 对比项  | map      | unordered_map |
| ---- | -------- | ------------- |
| 底层结构 | 红黑树      | 哈希表           |
| 是否有序 | 有序       | 无序            |
| 查找效率 | O(log n) | O(1)          |
| 内存消耗 | 较小       | 较大            |
| 适合场景 | 需要排序     | 追求速度          |

