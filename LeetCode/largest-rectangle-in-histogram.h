/*
*	https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <memory>
#include <queue>
#include <list>
#include <cassert>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.empty()) return 0;
        
        vector<size_t> stk;
        stk.push_back(0);
        size_t max_area = height[0];
        for (size_t i = 1; i < height.size(); ++i) {
            if (height[i] == height[stk.back()]) {
                stk.back() = i;
                continue;
            }
            while (!stk.empty() && height[i] < height[stk.back()]) {
                int h = height[stk.back()];
                stk.pop_back();
                size_t left = stk.empty() ? -1 : stk.back();
                max_area = max(max_area, h * (i - left - 1));
            }
            stk.push_back(i);
        }
        while (!stk.empty()) {
            int h = height[stk.back()];
            stk.pop_back();
            size_t left = stk.empty() ? -1 : stk.back();
            max_area = max(max_area, h * ((int)height.size() - left - 1));
        }
        
        return (int)max_area;
    }
};