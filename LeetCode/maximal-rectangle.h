/*
*	https://oj.leetcode.com/problems/maximal-rectangle/
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

	int maxArea(vector<int> &hist) {
		int max_area = 0;
		hist.push_back(-1);
		vector<int> s; s.reserve(hist.size()+1);
		s.push_back(-1);
		for (int i = 0; i < hist.size(); ++i) {
			if (s.size() == 1 || hist[s.back()] < hist[i])
				s.push_back(i);
			else if (hist[s.back()] == hist[i])
				s.back() = i;
			else {
				while (s.size() > 1 && hist[s.back()] > hist[i]) {
					int h = hist[s.back()]; s.pop_back();
					int left = s.back();
					max_area = max(max_area, (i - left - 1) * h);
				}
				s.push_back(i);
			}
		}
		hist.pop_back();
		return max_area;
	}

	int maximalRectangle(vector<string> &matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
    
		vector<int> heights(cols, 0);

		int max_area = 0;
		for (int y = 0; y < rows; ++y) {
			for (int x = 0; x < cols; ++x) {
				if (matrix[y][x] == '1')
					heights[x]++;
				else
					heights[x] = 0;
			}
			max_area = max(max_area, maxArea(heights));
		}

		return max_area;
    }
};