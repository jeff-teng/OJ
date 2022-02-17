#ifdef OJ_LOCAL
#include "twoSum.h"
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

        // 没有找到结果，加入 hash 表
        element = malloc(sizeof(HashableElement));
        element->index = i;
        element->data = nums[i];
        HASH_ADD_INT(hashableNums, data, element);
    }

    return result;
}