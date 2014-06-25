/*
*	https://oj.leetcode.com/problems/palindrome-partitioning-ii/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <functional>
using namespace std;

class Solution {
public:
    int minCut(string s) {
		enum Flag { UNKNOWN, YES, NO, };
		vector<Flag> flags(s.size() * s.size(), UNKNOWN);
		auto get_flag = [&](int i, int j)-> Flag& {
			return flags[i*s.size()+j];
		};

		function<bool(int, int)> is_palindrome;
		is_palindrome = [&](int start, int end) -> bool{
			if (end - start < 1) {
				return (get_flag(start, end) = YES) || true;
			}
			else if (s[start] != s[end]) {
				return (get_flag(start, end) = NO) && false;
			}
			else {
				Flag &flag = get_flag(start+1, end-1);
				if (flag == YES) return true;
				else if (flag == NO) return false;
				else return (flag = is_palindrome(start+1, end-1) ? YES : NO) == YES;
			}
		};

        vector<int> opt(s.size()+1, s.size());
        opt[0] = -1, opt[1] = 0;
        for (int i = 2; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (is_palindrome(j, i-1)) {
                    opt[i] = min(opt[i], opt[j] + 1);
                }
            }
        }
        return opt.back();
    }
};