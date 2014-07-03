#pragma warning (disable : 4996)
#pragma warning (disable : 4018)

#include "LeetCode\best-time-to-buy-and-sell-stock-iii.h"
#ifdef LEETCODE
int main()
{
	int prices[] = {6,1,3,2,4,7};
	int a = Solution().maxProfit(vector<int>(begin(prices), end(prices)));
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