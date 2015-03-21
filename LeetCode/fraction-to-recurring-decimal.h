/*
*	https://oj.leetcode.com/problems/fraction-to-recurring-decimal//
*/

#define LEETCODE
#include <cassert>
#include <functional>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0)
			return "0";
        string ans;
		
		long long a = numerator, b = denominator;
		int sign = 1;
		if (numerator < 0) {
			sign *= -1;
			a = -a;
		}
		if (denominator < 0) {
			sign *= -1;
			b = -b;
		}
		if (sign == -1)
			ans += "-";
        
		
        char buff[111];
        sprintf(buff, "%lld", a / b);
        ans += buff;
        a %= b;
        if (a == 0) {
            return ans;
        }
        ans += '.';
        vector<unsigned long long> pattern, down;
        for (;;) {
            if (a == 0) {
                for (int i = 0; i < down.size(); ++i) {
                    ans += '0' + down[i];
                }
                return ans;
            }
            auto it = find(pattern.begin(), pattern.end(), a);
            if (it == pattern.end()) {
                pattern.push_back(a);
                a *= (unsigned long long)10;
                down.push_back(a/ b);
                a %= b;
            }
            else {
                int pos = it - pattern.begin();
                for (int i = 0; i < pos; ++i)
                    ans += '0' + down[i];
                ans += '(';
                for (int i = pos; i < down.size(); ++i)
                    ans += '0' + down[i];
                ans += ')';
                return ans;
            }
        }
    }
};