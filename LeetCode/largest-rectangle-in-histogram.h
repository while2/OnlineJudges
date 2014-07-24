/*
*	https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        function<int(int start, int end)> parse;
		parse = [&](int start, int end)->int {
			if (start == end) return 0;
			int min_idx = start;
			for (int i = start+1; i < end; ++i)
				if (height[i] < height[min_idx])
					min_idx = i;
			int area = height[min_idx] * (end - start);
			area = max(area, parse(start, min_idx));
			area = max(area, parse(min_idx+1, end));
			return area;
		};

		return parse(0, height.size());
    }
};