# Add Two Numbers
## 题目描述
给两个非空链表，链表倒序存储每一位数字，求两个链表的和，返回的和也要倒序存储。

## 解题思路
倒序存储的每一位数字，其实就是模拟加法运算。

## 代码
### C 语言

```c
#include <stdlib.h>

#ifdef OJ_LOCAL
#include "addTwoNumbers.h"
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    // 返回结果头指针
    struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));

    // 当前计算位
    struct ListNode *current = result;

    // 进位
    int lead = 0;

    while (current != NULL) {
        // 累加数字
        current->val = 0;

        if (l1 != NULL) {
            current->val += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            current->val += l2->val;
            l2 = l2->next;
        }

        // 处理进位
        current->val += lead;
        lead = current->val / 10;
        current->val %= 10;

        // 处理 next 指针
        if (l1 == NULL && l2 == NULL && lead == 0) {
            current->next = NULL;
        } else {
            current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        }
        current = current->next;
    }

    return result;
}
```
