/*
*	https://oj.leetcode.com/problems/wildcard-matching/
*/

#define LEETCODE
#include <cassert>
#include <functional>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
		int count = 0;
		for (int i = 0; p[i]; ++i)
			if (p[i] != '*')
				count++;
		if (count > strlen(s))
			return false;

		int n = strlen(p);
		vector<bool> row1(n+1, false), row2(n+1);
		row1[0] = true;
		for (int i = 1; i <= n; ++i) {
			if (p[i-1] == '*')
				row1[i] = row1[i-1];
			else
				row1[i] = false;
		}
		for (int i = 0; s[i]; ++i) {
			row2[0] = false;
			for (int j = 1; j <= n; ++j) {
				if (p[j-1] == '?' || s[i] == p[j-1])
					row2[j] = row1[j-1];
				else if (p[j-1] == '*')
					row2[j] = row1[j] || row2[j-1];
				else
					row2[j] = false;
			}
			swap(row1, row2);
		}
		return row1.back();
    }
};