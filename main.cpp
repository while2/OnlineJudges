#pragma warning (disable : 4996)
#pragma warning (disable : 4018)

#include "LeetCode/scramble-string.h"

#ifdef LEETCODE
int main()
{
	Solution().isScramble("tqxpxeknttgwoppemjkivrulaflayn", "afaylnlurvikjmeppowgttnkexpxqt");
}

#else
struct Test
{
	Test()
	{
		freopen("in.in", "r", stdin);
		freopen("out.txt", "w", stdout);
	}
};
static Test test;
#endif