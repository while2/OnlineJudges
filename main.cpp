#pragma warning (disable : 4996)
#pragma warning (disable : 4018)

#include "LeetCode\fraction-to-recurring-decimal.h"
#ifdef LEETCODE
#include <set>
int main()
{
	cout << Solution().fractionToDecimal(-2147483648, 1);
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
