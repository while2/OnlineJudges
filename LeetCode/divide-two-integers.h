/*
*	https://oj.leetcode.com/problems/divide-two-integers/
*/

#define LEETCODE
#include <cassert>
#include <functional>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
		unsigned int m = dividend, n = divisor;
		int sign = 1;
        if (dividend < 0) {
			m = -dividend;
			sign *= -1;
		}
        if (divisor < 0) {
			n = -divisor;
			sign *= -1;
		}

		for (;;) {
            if (n & 0x80000000 || (n << 1) > m)
                break;
            n <<= 1;
        }
        unsigned int q = 0;
        while (n >= abs(divisor)) {
            q <<= 1;
            if (m >= n) {
                q |= 1;
                m -= n;
            }
            n >>= 1;
        }
        return sign * q;
    }
};