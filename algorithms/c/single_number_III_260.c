// Source : https://leetcode.com/problems/single-number-iii/
// Author : Tyrion
// Date   : 2016-08-19

/***************************************************************************************
 *
 * Given an array of numbers nums, in which exactly two elements appear only once and all
 * the other elements appear exactly twice. Find the two elements that appear only once.
 *
 * For example:
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 *
 ***************************************************************************************/

/***************************************************************************************
 *
 * solution:
 * the main idea is use XOR
 * let result = x^y^x^z^y^t = z^t
 * because z != t(problem definition), so in the binary present of result, there must be
 * a bit = 1.what we can easily find is the lowest bit = 1 in result,
 * lowestbit = result & ~result+1b
 * for example z = 0101b, t = 0011b, then result = 0110b, lowest bit = 0010.
 * and lowest bit & z != lowest bit & t, so we can seperate them.
 *
 ***************************************************************************************/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int result = 0, i;
    int* ret_array = (int*) malloc(sizeof(int)*2);
    *returnSize = 2;

    for(i = 0; i < numsSize; i++)
    {
        result ^= nums[i];
    }

    int lowest_bit = result & ~(result - 1);
    for(i = 0; i < numsSize; i++)
    {
        if(lowest_bit & nums[i])
            ret_array[0] ^= nums[i];
        else
            ret_array[1] ^= nums[i];
    }

    return nums;
}







