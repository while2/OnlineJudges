#pragma warning (disable : 4996)
#pragma warning (disable : 4018)

#include "LeetCode\palindrome-partitioning-ii.h"
#ifdef LEETCODE
int main()
{
	Solution().minCut("ab");
}
#endif
#ifdef HACKERRANK
struct Test
{
	Test()
	{
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}
};
static Test test;
#endif