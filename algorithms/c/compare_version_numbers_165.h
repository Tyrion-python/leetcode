//
// Created by Tyrion on 2016/8/15.
//

#ifndef LEETCODE_COMPARE_VERSION_NUMBERS_165_H
#define LEETCODE_COMPARE_VERSION_NUMBERS_165_H

#include "string.h"

int compareVersion(char *version1, char *version2) {
    int length1 = strlen(version1);
    int length2 = strlen(version2);
    int sum1 = 0, sum2 = 0, i = 0, j = 0;
    while (i < length1 || j < length2) {
        while ( i < length1 && version1[i] != '.') {
            sum1 = sum1 * 10 + version1[i] - '0';
            i++;
        }
        while (j < length2 && version2[j] != '.') {
            sum2 = sum2 * 10 + version2[j] - '0';
            j++;
        }
        if (sum1 > sum2)
            return 1;
        else if (sum1 < sum2)
            return -1;
        i++;
        j++;
        sum1 = 0;
        sum2 = 0;
    }
    return 0;
}

#endif //LEETCODE_COMPARE_VERSION_NUMBERS_165_H
