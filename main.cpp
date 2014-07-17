#pragma warning (disable : 4996)
#pragma warning (disable : 4018)

#include "LeetCode\interleaving-string.h"
#ifdef LEETCODE

int main()
{
	Solution().isInterleave("abaaacbacaab", "bcccababccc", "bcccabaaaaabccaccbacabb");
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