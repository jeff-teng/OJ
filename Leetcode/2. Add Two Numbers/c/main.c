#include <stdio.h>
#include <stdlib.h>

#include "addTwoNumbers.h"


int main() {
    // 构造参数
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *current;

    current = l1;
    current->val = 2;
    current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    current = current->next;
    current->val = 4;
    current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    current = current->next;
    current->val = 3;
    current->next = NULL;

    current = l2;
    current->val = 5;
    current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    current = current->next;
    current->val = 6;
    current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    current = current->next;
    current->val = 4;
    current->next = NULL;

    // 返回结果
    struct ListNode *result = addTwoNumbers(l1, l2);

    // 打印
    while (result != NULL) {
        printf("%d", result->val);
        result = result->next;
    }

    return 0;
}