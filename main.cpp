#pragma warning (disable : 4996)
#pragma warning (disable : 4018)

#include "LeetCode\largest-rectangle-in-histogram.h"
#ifdef LEETCODE
int main()
{
	int height[] = {1,0,1,0,1};
	Solution().largestRectangleArea(vector<int>(begin(height), end(height)));
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