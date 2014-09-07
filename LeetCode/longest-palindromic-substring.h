/*
*	https://oj.leetcode.com/problems/longest-palindromic-substring/
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
    string longestPalindrome(string s) {
		int start = 0, end = 0;
		for (int i = 0; i < s.size(); ++i) {
			int j;
			for (j = 1; i - j >= 0 && i + j < s.size(); ++j) {
				if (s[i-j] != s[i+j])
					break;
			}
			if (2*j-1 > end-start+1) {
				start = i-j+1;
				end = i+j-1;
			}

			for (j = 0; i-j >= 0 && i+j+1 < s.size(); ++j) {
				if (s[i-j] != s[i+1+j])
					break;
			}
			if (2*j > end-start+1) {
				start = i-j+1;
				end = i+j;
			}
		}
		return s.substr(start, end-start+1);
    }
};