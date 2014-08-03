#pragma warning (disable : 4996)
#pragma warning (disable : 4018)

#include "LeetCode/largest-rectangle-in-histogram.h"
#ifdef LEETCODE
int main()
{
    vector<int> height({0,0,0,0,0,0,0,0,2147483647});
	Solution().largestRectangleArea(height);
	return 0;
}

#endif
#ifdef HACKERRANK
struct Test
{
	Test()
	{
		freopen("in.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	}
};
static Test test;
#endif