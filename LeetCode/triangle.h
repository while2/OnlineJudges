/*
*	https://oj.leetcode.com/problems/triangle/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		for (int i = 1; i < triangle.size(); ++i) {
			auto &pre = triangle[i-1];
			auto &row = triangle[i];
			row[0] += pre[0];
			row.back() += pre.back();
			for (int j = 1; j < row.size()-1; ++j) {
				row[j] += min(pre[j-1], pre[j]);
			}
		}
		auto &cost = triangle.back();
		int min_cost = cost[0];
		for (int i = 1; i < cost.size(); ++i)
			min_cost = min(min_cost, cost[i]);
		return min_cost;
	}
};