/*
*	https://oj.leetcode.com/problems/combination-sum/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	struct Comb {
		int sum, time;
		vector<int> nums;

		void Add(int val) {
			static int g_time = 1;
			time = g_time++;
			nums.push_back(val);
			sum += val;
		}
		bool operator<(const Comb &rhs) const {
			if (sum == rhs.sum)
				return time < rhs.time;
			return sum < rhs.sum;
		}
	};

	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<vector<int>> ans;
		set<Comb> all;

		sort(begin(candidates), end(candidates));

		Comb comb = {0, 0};
		all.insert(comb);

		for (auto cand : candidates) {
			for (auto comb : all) {
				comb.Add(cand);
				if (comb.sum == target)
					ans.push_back(comb.nums);
				else if (comb.sum > target)
					break;
				else
					all.insert(comb);
			}
		}

		return ans;
	}
};