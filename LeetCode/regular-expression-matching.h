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
		int n = strlen(p);
		vector<bool> row1(n+1, false), row2(n+1);
		row1[0] = true;
		for (int j = 1; j <= n; ++j)
			if (p[j-1] == '*')
				row1[j] = row1[j-2];
			else
				row1[j] = false;

		for (int i = 0; s[i]; ++i) {
			row2[0] = false;
			for (int j = 1; j <= n; ++j) {
				if (p[j-1] == '*') {
					row2[j] = row2[j-1];
					if (j >= 2 && row2[j-2])
						row2[j] = true;
					if ((p[j-2] == '.' || p[j-2] == s[i])
						&& row1[j])
						row2[j] = true;
				}
				else if (p[j-1] == '.' || p[j-1] == s[i])
					row2[j] = row1[j-1];
				else
					row2[j] = false;
			}
			swap(row1, row2);
		}

		return row1.back();
    }
};