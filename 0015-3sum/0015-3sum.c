/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
// 1. 自己定义一个比较函数（升序）
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int** threeSum(int* nums, int numsSize, int* returnSize,int** returnColumnSizes) {
    // 进行排序 便于后续的指针的移动
    qsort(nums, numsSize, sizeof(int), cmp);
    *returnSize = 0; // 存储一共有几行数据
    int n = 30000;   // 尽量大一些 避免溢出
    int** res = malloc(n * n * sizeof(int));
    *returnColumnSizes = malloc(n * sizeof(int)); // 存储某一行数据多少列
    int j = 0;
    int i, l, r;
    for (i = 0; i < numsSize - 2; i++) {
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1]) {
            // 跳过重复数字 进入下一循环
            // 防止作为第一个数字的 nums[i] 被重复使用
            // 写成nums[i]==nums[i+1]会使-1 -1 2这种类似情况被忽略
            continue;
        }
        l = i + 1;
        r = numsSize - 1;
        while (l < r) {
            int temp = nums[i] + nums[l] + nums[r];
            if (temp > 0) {
                r--;
            } else if (temp < 0) {
                l++;
            } else {
                res[*returnSize] = (int*)malloc(sizeof(int) * 3);
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[l];
                res[*returnSize][2] = nums[r];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                // 跳过重复情况
                while (l < r && nums[l] == nums[l + 1])
                    l++;
                while (l < r && nums[r] == nums[r - 1])
                    r--;
                l++;
                r--;
            }
        }
    }
    return res;
}