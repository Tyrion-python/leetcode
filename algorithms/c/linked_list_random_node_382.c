// Source : https://leetcode.com/problems/linked-list-random-node/
// Author : Tyrion
// Date   : 2016-08-19

/***************************************************************************************
 *
 * Given a singly linked list, return a random node's value from the linked list. Each
 * node must have the same probability of being chosen.
 *
 * Follow up:What if the linked list is extremely large and its length is unknown
 * to you? Could you solve this efficiently without using extra space?
 *
 ***************************************************************************************/

/***************************************************************************************
 *
 * solution:
 * change the selection to an equivalent way.
 * detail see https://discuss.leetcode.com/topic/53738/o-n-time-o-1-space-java-solution
 *
 ***************************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct {
    struct ListNode *head;
} Solution;

/** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
Solution *solutionCreate(struct ListNode *head) {
    Solution *solution = (Solution *) malloc(sizeof(Solution));
    solution->head = head;
    return solution;
}

/** Returns a random node's value. */
int solutionGetRandom(Solution *obj) {
    struct ListNode *cur_ptr = obj->head;
    int cur_val = 0, i = 1;
    while (cur_ptr) {
        if (rand() % i == 0)
            cur_val = cur_ptr->val;
        i++;
        cur_ptr = cur_ptr->next;
    }
    return cur_val;

}

void solutionFree(Solution *obj) {
    free(obj);
}


/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 * solutionFree(obj);
 */