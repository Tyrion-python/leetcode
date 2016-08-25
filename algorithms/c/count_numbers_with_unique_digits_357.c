// Source : https://leetcode.com/problems/count-numbers-with-unique-digits/
// Author : Tyrion
// Date   : 2016-08-25

/***************************************************************************************
 *
 * Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
 * Example:
 *
 * Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100,
 * excluding [11,22,33,44,55,66,77,88,99])
 *
 ***************************************************************************************/

/***************************************************************************************
 *
 * solution:
 * d[n] = 9*9*8*7...*(11-n) + d[n-1]+d[n-2]+,,,+d[1]
 *
 ***************************************************************************************/

int countNumbersWithUniqueDigits(int n) {
    if (n == 0)
        return 1;
    int res = 10, temp = 9, step = 9;
    for (int i = 1; i < n && i < 10; i++) {
        temp *= step;
        res += temp;
        step--;
    }
    return res;

}