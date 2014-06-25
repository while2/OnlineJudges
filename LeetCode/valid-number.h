/*
*	https://oj.leetcode.com/problems/valid-number/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isNumber(const char *s) {
		if (s == NULL) return false;

		while (*s != 0 && *s == ' ') s++;
		if (*s == '+' || *s == '-') s++;

		int dot = 0, digit = 0, e = 0;
		while (*s != 0) {
			if (*s == '.') {
				if (e > 0) return false;
				dot++;
			}
			else if (*s == 'e') {
				if (digit == 0)
					return false;
				e++;
				digit = 0;
				if (s[1] == '+' || s[1] == '-')
					s++;
			}
			else if (*s == ' ') break;
			else if (*s < '0' || *s > '9') return false;
			else digit++;
			s++;
		}
		while (*s != 0) {
			if (*s != ' ') return false;
			s++;
		}
		return dot <= 1 && e <= 1 && digit > 0;
	}
};