//
// Created by Tyrion on 2016/8/14.
//

#ifndef LEETCODE_ROTATE_ARRAY_189_H
#define LEETCODE_ROTATE_ARRAY_189_H

void swap(int* nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;

}
void rotate(int* nums, int numsSize, int k) {
    if(numsSize <= 1)
        return;
    k = k % numsSize;
    int i,start, current, cut_line,temp, temp_0,count;
    if(2*k == numsSize)
    {
        for(i = 0; i<k; i++)
            swap(nums, i, i+k);
        return;
    }

    start = 0, cut_line = numsSize - 1 - k;
    current = 0;
    temp = nums[current];
    count = 0;
    while(count < numsSize)
    {
        printf("%d,%d\n", current, temp);
        if(current <= cut_line)
        {
            temp_0 = nums[current + k];
            nums[current+k] = temp;
            temp = temp_0;
            current = current + k;
            count++;
        }
        else
        {
            temp_0 = nums[current-numsSize+k];
            nums[current-numsSize+k] = temp;
            temp = temp_0;
            current = current-numsSize+k;
            count++;
        }
        if(current == start)
        {
            start++;
            current = start;
            temp = nums[current];
        }
    }

}
#endif //LEETCODE_ROTATE_ARRAY_189_H
