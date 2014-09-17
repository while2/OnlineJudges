/*
 *	https://oj.leetcode.com/problems/implement-strstr/
 */

#define LEETCODE
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool match(char *str1, char *str2, int n) {
		for (int i = 0; i < n; ++i)
			if (str1[i] != str2[i])
				return false;
		return true;
	}

    char *brutalForce(char *haystack, char *needle) {
		int n = strlen(needle);
		for (char *p = haystack; *p; ++p) {
			if (match(p, needle, n))
				return p;
		}
		return nullptr;
    }
	
    char *rabinKarp(char *haystack, char *needle) {
		int n = strlen(needle);
		if (strlen(haystack) < n)
			return NULL;
		typedef unsigned int UINT;
		UINT pat = 0, tex = 0, R = 1000000007;
		for (int i = 0; i < n; ++i)
			pat = pat * R + needle[i];

		for (int i = 0; i < n; ++i)
			tex = tex * R + haystack[i];

		UINT lead = 1;
		for (int i = 1; i < n; ++i)
			lead *= R;

		auto p1 = haystack, p2 = haystack + n;
		for (;;p1++, p2++) {
			if (tex == pat && match(p1, needle, n))
				return p1;
			tex = (tex - *p1 * lead) * R + *p2;
			if (!*p2)
				break;
		}
		return nullptr;
	}

    char *strStr(char *haystack, char *needle) {
		return rabinKarp(haystack, needle);
	}
};