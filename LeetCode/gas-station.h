/*
*	https://oj.leetcode.com/problems/gas-station/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	static const int INF = 1 << 30;
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int start = 0, sum = 0;
		for (int i = 0; i < gas.size(); ++i) {
			sum += gas[i] - cost[i];
			if (sum < 0) {
				sum = 0;
				start = i+1;
			}
		}

		if (start == gas.size())
			return -1;

		for (int i = 0; i < start; ++i) {
			sum += gas[i] - cost[i];
			if (sum < 0)
				return -1;
		}

		return start;
	}
};