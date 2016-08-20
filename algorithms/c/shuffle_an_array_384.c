// Source : https://leetcode.com/problems/shuffle-an-array/
// Author : Tyrion
// Date   : 2016-08-20

/***************************************************************************************
 *
 *Shuffle a set of numbers without duplicates.
 * Example:
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 * // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must
 * equally likely to be returned.
 * solution.shuffle();
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 *
 ***************************************************************************************/

/***************************************************************************************
 *
 * solution:
 * for array a[0],a[1],a[2],...a[n-1];
 * a random shuffle can be achiece by follow step
 * for k in 0 to n-1
 * select an random number rd between 0 to k,
 * if rd == k, the do nothing
 * else we swap a[rd] and a[k]
 * after the loop, the shuffle is done;
 *
 ***************************************************************************************/

typedef struct {
    int *nums;
    int *new_nums;
    int size;

} Solution;

Solution *solutionCreate(int *nums, int size) {
    Solution *solution = (Solution *) malloc(sizeof(Solution));
    solution->nums = nums;
    solution->size = size;
    int *new_nums = (int *) malloc(sizeof(int) * size);
    solution->new_nums = new_nums;
}

/** Resets the array to its original configuration and return it. */
int *solutionReset(Solution *obj, int *returnSize) {
    return obj->nums;

}

/** Returns a random shuffling of the array. */
int *solutionShuffle(Solution *obj, int *returnSize) {

    int size = obj->size;
    int rd;
    int *nums = obj->nums;
    int *new_nums = obj->new_nums;

    for (int i = 0; i < size; i++) {
        rd = rand() % (i+1);
        if(i == rd)
        {
            new_nums[i] = nums[i];
            continue;
        }
        new_nums[i] = new_nums[rd];
        new_nums[rd] = nums[i];
    }
    return new_nums;
}

void solutionFree(Solution *obj) {
    free(obj->new_nums);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(nums, size);
 * int* param_1 = solutionReset(obj);
 * int* param_2 = solutionShuffle(obj);
 * solutionFree(obj);
 */