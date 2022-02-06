# Two Sum
## 题目描述
给一个整型数组 `nums` 和一个目标值 `target`，返回 `nums` 中两个相加等于目标值 `target` 的下标。

题目保证有唯一解，并且同一个元素不会用到两次。数组长度区间 $[2, 10^4]$，每个元素和目标值区间 $[-10^9, 10^9]$。

## 解题思路
LeetCode 第一题，首先最容易想到的方式就是两层遍历，时间复杂度 $O(n^2)$，空间复杂度 $O(1)$。

可以用一个 hash 表来进行优化，把每一个元素的**值和下标**存到 hash 表中，然后遍历每一个元素 `element`，然后在 hash 表里面查找 `target - element`，找到后返回对应的下标和当前下标。这样时间复杂度和空间复杂度都可以做到 $O(n)$。

有一个需要注意的点，如果使用先存 hash 表，再查找的方式，要注意判断找到的值和当前遍历的值是不是在同一个位置，因为题目说**同一个元素不会用到两次**。

还可以用另一种方式进行优化，先遍历每一个元素 `element`，如果没有在 hash 表中找到 `target - element`，这个时候再把 `element` 存到 hash 表中，后面遍历到 `target - element` 的时候就可以找到 `element`。这样做可以解决上面找到相同元素的问题，也可以减少一些非必要操作。

## 代码
### C 语言
C 标准库中没有 hash 表的实现，LeetCode 上默认包含了 `uthash.h`，可以参照 [uthash 文档](https://troydhanson.github.io/uthash/) 编写代码。

```c
#ifdef OJ_LOCAL
#include "uthash.h" // http://troydhanson.github.io/uthash/
#endif


typedef struct {
    // 数据和下标
    int data, index;

    // 使结构体可以 hash
    UT_hash_handle hh;

} HashableElement;


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    // 一定能找到结果
    *returnSize = 2;

    // 返回结果分配内存
    int *result = malloc(sizeof(int) * 2);

    // 初始化 hash 表
    HashableElement *tmp, *element, *hashableNums = NULL;

    // 存储数据
    for (int i = 0; i < numsSize; i++) {
        // 剩余的数
        int restNum = target - nums[i];

        // 查找是否已加入 hash 表
        HASH_FIND_INT(hashableNums, &restNum, tmp);

        // 如果找到结果，直接返回
        if (tmp != NULL) {
            result[0] = tmp->index;
            result[1] = i;

            return result;
        }

        // 没有找到结果，加入 hash table
        element = malloc(sizeof(HashableElement));
        element->index = i;
        element->data = nums[i];
        HASH_ADD_INT(hashableNums, data, element);
    }

    return result;
}
```