/*
*	https://oj.leetcode.com/problems/3sum/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	struct Triplet {
		int a, b, c;
	};
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > result;
		if (num.size() < 3) return result;
		sort(num.begin(), num.end());
		for (auto i = num.begin(); i != num.end();) {
			for (auto j = i+1; j != num.end();) {
				int num_k = -(*i+*j);
				if (*j <= num_k) {
					auto k = lower_bound(j+1, num.end(), num_k);
					if (k != num.end() && *k == num_k) {
						result.push_back(vector<int>());
						result.back().push_back(*i);
						result.back().push_back(*j);
						result.back().push_back(*k);
					}
				}
				++j;
				while (j != num.end() && *(j-1) == *j) ++j;
			}
			++i;
			while (i != num.end() && *(i-1) == *i) ++i;
		}

		return result;
	}
};