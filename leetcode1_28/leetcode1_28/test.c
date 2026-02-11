#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((b) > (a) ? (b) : (a))

// 198. 打家劫舍
int rob(int* nums, int numsSize) {
    int f0 = 0, f1 = 0;
    for (int i = 0; i < numsSize; i++) {
        int new_f = MAX(f1, f0 + nums[i]);
        f0 = f1;
        f1 = new_f;
    }
    return f1;
}

int deleteAndEarn(int* nums, int numsSize) {
    int mx = 0;
    for (int i = 0; i < numsSize; i++) {
        mx = MAX(mx, nums[i]);
    }

    int* a = calloc(mx + 1, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        a[nums[i]] += nums[i]; // 统计等于 x 的元素之和
    }

    int res = rob(a, mx + 1);
    free(a);
    return res;
}

