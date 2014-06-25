/*
*	https://oj.leetcode.com/problems/valid-palindrome/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isLetter(char c) {
		return (c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z') ||
			(c >= '0' && c <= '9');
	}
	char lowerCase(char c) {
		if (c >= 'A' && c <= 'Z')
			c = c - 'A' + 'a';
		return c;
	}
	bool isPalindrome(string s) {
		int n = s.size();
		int i = 0, j = n-1;
		while (true) {
			while (i < n && !isLetter(s[i])) i++;
			while (j >= 0 && !isLetter(s[j])) j--;
			if (i >= j) break;
			char c1 = lowerCase(s[i]);
			char c2 = lowerCase(s[j]);
			if (c1 != c2) return false;
			i++, j--;
		}
		return true;
	}
};