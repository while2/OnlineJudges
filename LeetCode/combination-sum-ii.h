/*
*	https://oj.leetcode.com/problems/combination-sum-ii/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;


#define FOR(variable, container) \
	for (auto _dONT_tOUTH_mE_ = std::begin(container), _dONT_tOUTH_mE_eITHER_ = std::begin(container); _dONT_tOUTH_mE_ != std::end(container); ++_dONT_tOUTH_mE_) \
	for (variable = *_dONT_tOUTH_mE_; _dONT_tOUTH_mE_ == _dONT_tOUTH_mE_eITHER_; ++_dONT_tOUTH_mE_eITHER_)


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

	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		vector<vector<int>> ans;
		set<Comb> all;

		sort(begin(candidates), end(candidates));

		Comb comb = {0, 0};
		all.insert(comb);

		FOR (auto cand, candidates) {
			vector<Comb> temp;
			FOR (auto comb, all) {
				comb.Add(cand);
				if (comb.sum == target)
					ans.push_back(comb.nums);
				else if (comb.sum > target)
					break;
				else
					temp.push_back(comb);
			}
			all.insert(begin(temp), end(temp));
		}

		return ans;
	}
};