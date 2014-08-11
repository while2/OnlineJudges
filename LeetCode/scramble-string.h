/*
*	https://oj.leetcode.com/problems/scramble-string/
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
    bool isScramble(string str1, string str2) {
        function<bool(int,int,int,int)> parse;
        parse = [&](int s1, int e1, int s2, int e2) {
		
			vector<int> hist(26, 0);
			for (int i = 0; i < e1-s1; ++i) {
				hist[str1[s1+i]-'a']++;
				hist[str2[s2+i]-'a']--;
			}
			for (auto i : hist)
				if (i != 0)
					return false;

            if (e1-s1<=3) return true;

			for (int i = s1+1; i < e1-1; ++i) {
				int l1 = i-s1, l2 = e1-i;
				if (parse(s1, i, e2-l1, e2) &&
					parse(i, e1, s2, s2+l2) )
					return true;
				
				if (parse(s1, i, s2, s2+l1) &&
					parse(i, e1, e2-l2, e2) )
					return true;
			}
			return false;
        };
        auto ret = parse(0, str1.size(), 0, str2.size());
		return ret;
    }
};