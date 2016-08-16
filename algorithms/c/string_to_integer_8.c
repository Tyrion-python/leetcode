// Source : https://leetcode.com/problems/string-to-integer-atoi/
// Author : Tyrion
// Date   : 2016-08-16

/***************************************************************************************
 *
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge, please
 * do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input
 * specs). You are responsible to gather all the input requirements up front.
 *
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your function
 * signature accepts a const char * argument, please click the reload button  to reset
 * your code definition.
 *
 ***************************************************************************************/

/***************************************************************************************
 *
 * solution:
 * contains three step
 * first deal with the white space in the begin of the string
 * second deal with the sign
 * third deal with the number
 *
 ***************************************************************************************/

#include "string.h"

int myAtoi(char *str) {
    long long int num = 0;
    int i = 0, length = strlen(str);
    int temp;
    bool sign = true;

    while (i < length && str[i] == ' ')
        i++;
    if (i == length)
        return 0;

    if (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            sign = false;
        }
        i++;
    }

    while (i < length) {
        temp = str[i] - 48;
        if (0 <= temp && temp <= 9) {
            num = num * 10 + temp;
            if (sign && num >= INT_MAX)
                return INT_MAX;
            else if (~sign && num <= INT_MIN)
                return INT_MIN;
            i++;
        } else
            break;
    }
    if( ~sign )
        return -num;
    return num;
}