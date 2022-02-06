#include <stdio.h>

#include "twoSum.h"

int main() {
    // 初始化数组
    int nums[] = {2, 7, 11, 15};

    // 返回长度
    int returnSize = 0;

    // 求解
    int *result = twoSum(nums, 4, 9, &returnSize);

    // 打印
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}