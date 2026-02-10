#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
// 影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//
//给定一个代表每个房屋存放金额的非负整数数组，
//计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

#define MAX(a, b) ((b) > (a) ? (b) : (a))

int dfs(int i, int* nums, int* memo) {
    if (i < 0) {
        return 0; // 递归边界（没有房子）
    }
    if (memo[i] != -1) {
        return memo[i]; // 之前计算过
    }
    int not_choose = dfs(i - 1, nums, memo);
    int choose = dfs(i - 2, nums, memo) + nums[i];
    return memo[i] = MAX(not_choose, choose);
}

int rob(int* nums, int numsSize) {
    int* memo = malloc(numsSize * sizeof(int));
    memset(memo, -1, numsSize * sizeof(int));
    int ans = dfs(numsSize - 1, nums, memo); // 从最后一个房子开始思考
    free(memo);
    return ans;
}

作者：灵茶山艾府
链接：https ://leetcode.cn/problems/house-robber/solutions/2102725/ru-he-xiang-chu-zhuang-tai-ding-yi-he-zh-1wt1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



