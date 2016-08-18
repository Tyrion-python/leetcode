// Source : https://leetcode.com/problems/single-number/
// Author : Tyrion
// Date   : 2016-08-18

/***************************************************************************************
 *
 * Given an array of integers, every element appears twice except for one. Find that
 * single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it
 * without using extra memory?
 *
 ***************************************************************************************/

/***************************************************************************************
 *
 * solution:
 * note that x^y^y^x^z = z
 * so we can use xor
 *
 ***************************************************************************************/

int singleNumber(int *nums, int numsSize) {
    int ret_num = 0;
    for (int i = 0; i < numsSize; i++) {
        ret_num = ret_num ^ nums[i];
    }

    return ret_num;
}