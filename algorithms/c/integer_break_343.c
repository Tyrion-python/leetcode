// Source : https://leetcode.com/problems/integer-break/
// Author : Tyrion
// Date   : 2016-08-26

/***************************************************************************************
 *
 * Given a positive integer n, break it into the sum of at least two positive integers
 * and maximize the product of those integers. Return the maximum product you can get.
 * For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
 *
 * Note: You may assume that n is not less than 2 and not larger than 58.
 *
 ***************************************************************************************/

/***************************************************************************************
 * there provides two solutions
 * solution 1:
 * using dynamic programing
 * solution 2:
 * the factor that must be 2 or 3, otherwise, if there is a factor bigger than factor 3,
 * then it can bu seperate to sum of some 2 and some 3, the product is bigger.
 *
 ***************************************************************************************/

#include "math.h"

int integerBreak(int n) {
    int *nums = (int *) malloc(sizeof(int) * (n + 1));
    int temp, temp0;
    nums[1] = 0;
    for (int i = 2; i <= n; i++) {
        nums[i] = 0;
        for (int j = 1; j <= i / 2; j++) {
            if (j > nums[j])
                temp = j;
            else
                temp = nums[j];

            if (i - j > nums[i - j])
                temp0 = i - j;
            else
                temp0 = nums[i - j];

            temp *= temp0;
            if (temp > nums[i])
                nums[i] = temp;

        }
    }
    temp = nums[n];
    free(nums);

}

int integerBreak(int n) {
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    int m, t;
    if (n % 3 == 1) {
        m = n / 3 - 1;
        t = 4;
    } else {
        m = n / 3;
        t = n % 3;
    }
    if (t == 0)
        t = 1;

    return pow(3, m) * t;
}