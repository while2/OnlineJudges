/*
*	https://oj.leetcode.com/problems/interleaving-string/
*/

#define LEETCODE
// Paste following to Online Judge system
#include <vector>
#include <string>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<char> row1(s2.size()+1), row2(s2.size()+1);
        row1[0] = 1;
        for (int j = 1; j <= s2.size(); ++j) {
            if (s2[j-1] == s3[j-1]) row1[j] = 1;
            else row1[j] = 0;
        }

        for (int i = 1; i <= s1.size(); ++i) {
            if (s1[i-1] == s3[i-1]) row2[0] = row1[0];
			else row2[0] = 0;
            for (int j = 1; j <= s2.size(); ++j) {
				row2[j] = 0;
                if (s1[i-1] == s3[i+j-1]) row2[j] |= row1[j];
                if (s2[j-1] == s3[i+j-1]) row2[j] |= row2[j-1];
            }
            swap(row1, row2);
        }
        return row1.back();
    }
};