/*
*	https://oj.leetcode.com/problems/distinct-subsequences/
*/

#define LEETCODE
// Paste following to Online Judge system
#include <vector>
#include <string>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
	int numDistinct(string S, string T) {
		vector<int> row1(S.size()+1, 1), row2(S.size()+1);
		for (int t = 1; t <= T.size(); ++t) {
			for (int s = 0; s <= S.size(); ++s) {
				if (s < t)
					row2[s] = 0;
				else if (T[t-1] == S[s-1])
					row2[s] = row2[s-1] + row1[s-1];
				else
					row2[s] = row2[s-1];
			}
			swap(row1, row2);
		}
		return row1.back();
	}
};