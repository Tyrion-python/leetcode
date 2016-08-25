// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Author : Tyrion
// Date   : 2016-08-25

/***************************************************************************************
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions
 * as you like (ie, buy one and sell one share of the stock multiple times). However,
 * you may not engage in multiple transactions at the same time (ie, you must sell the
 * stock before you buy again).
 *
 ***************************************************************************************/

/***************************************************************************************
 *
 * solution:
 * greedy algorithm
 * the day i you need to sell is when prices[i] < prices[i-1].this choice have no effect
 * to the rest day of i,i+1,...n.so it's greedy.
 *
 ***************************************************************************************/

int maxProfit(int *prices, int pricesSize) {

    int max_profit = 0, min_price = prices[0], max_price = prices[0], i;
    for (i = 1; i < pricesSize; i++) {
        if (prices[i] >= max_price) {
            max_price = prices[i];
            continue;
        } else {
            max_profit += max_price - min_price;
            min_price = prices[i];
            max_price = prices[i];
        }
    }
    return max_profit;
}