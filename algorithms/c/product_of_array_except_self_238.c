// Source : https://leetcode.com/problems/product-of-array-except-self/
// Author : Tyrion
// Date   : 2016-08-23

/***************************************************************************************
 *
 * Given an array of n integers where n > 1, nums, return an array output such that
 * output[i] is equal to the product of all the elements of nums except nums[i].
 *
 * Solve it without division and in O(n).
 * For example, given [1,2,3,4], return [24,12,8,6].
 *
 * Follow up:Could you solve it with constant space complexity? (Note: The output
 * array does not count as extra space for the purpose of space complexity analysis.)
 *
 ***************************************************************************************/

/***************************************************************************************
 *
 * solution:
 * for a[0],a[1],a[2],...a[n-1], output[i] = a[0]*a[1]*...*a[i-1]*a[i+1]*...*a[n-1]
 * we can seperate the expression to two part, the first part contains a[0]*a[1]*a[2]*...a[i-1],
 * the second part contains a[i+1]*a[i+2]*...*a[n-1].for each i, if we calculate the two
 * part, the we get every output[i]
 *
 ***************************************************************************************/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *productExceptSelf(int *nums, int numsSize, int *returnSize) {

    int *ret_nums = (int *) malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int product = 1;
    ret_nums[0] = 1;

    for (int i = 1; i < n; i++) {
        ret_nums[i] = ret_nums[i - 1] * nums[i - 1];
    }


    for (int i = n - 1; i >= 0; i--) {
        ret_nums[i] *= product;
        product *= nums[i];
    }
    return ret_nums;
}