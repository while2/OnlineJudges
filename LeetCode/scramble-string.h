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
		if (str1.size() != str2.size())
			return false;
		vector<int> sum1(str1.size()+1);
		vector<int> sum2(str1.size()+1);
		sum1[0] = sum2[0] = 0;
		for (int i = 0; i < str1.size(); ++i) {
			sum1[i+1] = sum1[i] + str1[i]-'a';
			sum2[i+1] = sum2[i] + str2[i]-'a';
		}

        function<bool(int,int,int,int)> parse;
        parse = [&](int s1, int e1, int s2, int e2) {
            //if (e1 - s1 != e2 - s2) return false;

			if (sum1[e1] - sum1[s1] != sum2[e2] - sum2[s2])
				return false;

			vector<int> hist(26, 0);
			for (int i = s1; i < e1; ++i) {
				++hist[str1[i]-'a'];
			}
			
			for (int i = s2; i < e2; ++i) {
				if (--hist[str2[i]-'a'] < 0)
					return false;
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