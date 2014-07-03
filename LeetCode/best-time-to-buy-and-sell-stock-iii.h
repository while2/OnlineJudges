/*
*	https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int> &prices) {		
	    if (prices.size() < 2) return 0;
		vector<int> lower(prices), upper(prices);
		for (int i = 1; i < lower.size(); ++i)
			lower[i] = min(lower[i-1], prices[i]);
		for (int i = upper.size()-2; i >= 0; --i)
			upper[i] = max(upper[i+1], prices[i]);

		vector<int> profits1(prices.size()), profits2(prices.size());
		profits1[0] = prices[0] - lower[0];
		profits2[0] = upper[0] - prices[0];
		for (int i = 1; i < prices.size(); ++i)
			profits1[i] = max(profits1[i-1], prices[i] - lower[i]);
		for (int i = prices.size()-2; i >= 0; --i)
			profits2[i] = max(profits2[i+1], upper[i] - prices[i]);

		int max_profits = 0;
		for (int i = 0; i < prices.size(); ++i)
			max_profits = max(max_profits, profits1[i] + profits2[i]);
		return max_profits;
	}
};