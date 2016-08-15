//
// Created by Tyrion on 2016/8/12.
//

#ifndef LEETCODE_FIRST_BAD_VERSION_278_H
#define LEETCODE_FIRST_BAD_VERSION_278_H

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int left = 1, right = n,middle;
    bool flag;
    do {
        middle = (left+right)/2;
        flag = isBadVersion(middle);
        if(flag) {
            if(middle == 1 || isBadVersion(middle-1))
                return middle;
            else
                right = middle;
        }
        else {
            left = middle + 1;
        }

    }while(true);
}

#endif //LEETCODE_FIRST_BAD_VERSION_278_H
