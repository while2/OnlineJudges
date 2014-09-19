/*
*	https://oj.leetcode.com/problems/zigzag-conversion/
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
    string convert(string s, int nRows) {
        string output; output.reserve(s.size());
        int stride = (nRows-1)*2;
        int step = stride;
        for (int r = 0; r < nRows; ++r) {
            for (int i = r; i < s.size(); i += stride) {
                output += s[i];
                if (r == 0 || r == nRows-1) continue;
                if (i+step < s.size())
                    output += s[i+step];
            }
            step -= 2;
        }
        return output;
    }
};