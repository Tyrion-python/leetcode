// Source : https://leetcode.com/problems/top-k-frequent-elements/
// Author : Tyrion
// Date   : 2016-08-24

/***************************************************************************************
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 *
 ***************************************************************************************/

/***************************************************************************************
 *
 * solution:
 * use map and heap
 *
 ***************************************************************************************/
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> cnt;

        for (auto num :nums)
            cnt[num]++;

        for (auto kv:cnt) {
            pq.push({kv.second, kv.first});
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> res;
        while (!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};