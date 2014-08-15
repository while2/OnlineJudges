/*
*	https://oj.leetcode.com/problems/sqrtx/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <stdint.h>
using namespace std;
typedef int64_t INT;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factors(n+1);
		factors[0] = 1;
        for (int i = 1; i <= n; ++i)
            factors[i] = factors[i-1] * i;
		function<string(int,int)> parse;
        parse = [&](int n, int k)->string {
			if (n == 1) return "1";
			char c0 = 1 + k / factors[n-1] + '0';
            string post = parse(n-1, k % factors[n-1]);
			for (char &c : post)
				if (c >= c0)
					c++;
			return c0 + post;
        };
		return parse(n, k-1);
    }
};