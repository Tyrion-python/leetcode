// Source : https://leetcode.com/problems/counting-bits/
// Author : Tyrion
// Date   : 2016-08-16

/***************************************************************************************
 *
 * Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num
 * calculate the number of 1's in their binary representation and return them as an array.
 *
 * Example:
 * For num = 5 you should return [0,1,1,2,1,2].
 *
 * Follow up:
 * It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can
 * you do it in linear time O(n) /possibly in a single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like
 * __builtin_popcount in c++ or in any other language.
 *
 ***************************************************************************************/

/***************************************************************************************
 *
 * solution:
 * for any number, it can represent as 10000b + XXXXb(both binary)
 * for example 5 = 101b = 100b + 1b
 * so the 1's number in 1XXXXb is 1 + 1's number in XXXX;
 * we just calculate 1's number begin with 1;
 *
 ***************************************************************************************/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int num, int *returnSize) {

    int *count_array = (int *) malloc(sizeof(int) * (num + 1));
    *returnSize = (num + 1);

    int base, i;
    count_array[0] = 0;
    if (num == 0)
        return count_array;
    count_array[1] = 1;

    for (base = 2; base <= num; base *= 2) {
        for (i = 0; i < base && (i + base) <= num; i++) {
            count_array[base + i] = 1 + count_array[i];
        }
    }

    return count_array;
}