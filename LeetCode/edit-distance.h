/*
*	https://oj.leetcode.com/problems/edit-distance/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<int> row1(word2.size()+1), row2(word2.size()+1);
		for (int i = 0; i <= word2.size(); ++i) {
			row1[i] = i;
		}
		for (int i = 1; i <= word1.size(); ++i) {
			row2[0] = i;
			for (int j = 1; j <= word2.size(); ++j) {
				int d_rep = row1[j-1] + (word1[i-1] != word2[j-1] ? 1 : 0);
				int d_add = row2[j-1] + 1;
				int d_del = row1[j] + 1;
				row2[j] = min(min(d_rep, d_add), d_del);
			}
			swap(row1, row2);
		}
		return row1.back();
	}
};