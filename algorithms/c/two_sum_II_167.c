// Source : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Author : Tyrion
// Date   : 2016-08-18

/***************************************************************************************
 *
 * Given an array of integers that is already sorted in ascending order, find two numbers
 * such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to
 * the target, where index1 must be less than index2. Please note that your returned
 * answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 ***************************************************************************************/

/***************************************************************************************
 *
 * solution:
 * the main idea is search and narrow the range.
 * for an array a[0],a[1],a[2],...a[n-1], first we calculate sum = a[0]+a[n-1],
 * if sum > target number, then a[0] is absolutely excluded.
 * because a[0] + a[x] <= a[0] + a[n-1] < target.so next search a[1].
 * sum < target is the same princple
 *
 ***************************************************************************************/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {

    int from_p = 0, back_p = numbersSize - 1, sum;
    do {
        sum = numbers[from_p] + numbers[back_p];
        if (sum == target)
            break;
        else if (sum > target)
            back_p--;
        else
            from_p++;
    } while (true);

    int *ret_arr = (int *) malloc(sizeof(int) * 2);
    returnSize = (int *) malloc(sizeof(int));
    *returnSize = 2;

    int k = 0;
    int number0 = numbers[from_p];
    int number1 = numbers[back_p];
    for (int i = 0; i < numbersSize; i++) {
        if (numbers[i] == number0 || numbers[i] == number1)
            ret_arr[k++] = i;
    }
    return ret_arr;
}