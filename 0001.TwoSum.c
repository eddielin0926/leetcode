#include <stdio.h>
#include <stdbool.h>

#define SORTING

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#ifdef BRUTE_FORCE
/* Obvious brute force approach. O(n^2) time, O(1) space */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i, j = 0;
    *returnSize = 2;
    int *returnArray = (int *)malloc(*returnSize * sizeof(int));
    for (i = 0; i < numsSize - 1; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                returnArray[0] = i;
                returnArray[1] = j;
                return returnArray;
            }
        }
    }
    return returnArray;
}
#endif

#ifdef SORTING
/* Sort the array and then use two pointers to find the two numbers. O(nlogn) time, O(1) space */
static int cmp(const void *lhs, const void *rhs) {
    if (*(int *) lhs == *(int *) rhs)
        return 0;
    return *(int *) lhs < *(int *) rhs ? -1 : 1;
}

static int *alloc_wrapper(int a, int b, int *returnSize) {
    *returnSize = 2;
    int *res = (int *) malloc(sizeof(int) * 2);
    res[0] = a, res[1] = b;
    return res;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int arr[numsSize][2];  /* {value, index} pair */
    for (int i = 0; i < numsSize; ++i) {
        arr[i][0] = nums[i];
        arr[i][1] = i;
    }
    qsort(arr, numsSize, sizeof(arr[0]), cmp);
    for (int i = 0, j = numsSize - 1; i < j; ) {
        if (arr[i][0] + arr[j][0] == target)
            return alloc_wrapper(arr[i][1], arr[j][1], returnSize);
        if (arr[i][0] + arr[j][0] < target)
            ++i;
        else
            --j;
    }
    *returnSize = 0;
    return NULL;
}
#endif

#ifdef HASHMAP

#endif

int main(int argc, char const *argv[])
{
    int nums[4] = {2, 7, 11, 15};
    int numsSize = 4;
    int target = 9;
    int returnSize = 0;
    int *returnArray = twoSum(nums, numsSize, target, &returnSize);
    printf("%d %d\n", returnArray[0], returnArray[1]);
    free(returnArray);
    return 0;
}
