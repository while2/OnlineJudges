#pragma warning (disable : 4996)
#pragma warning (disable : 4018)

#include "Hackerrank\TheCaptchaCracker.h"
#ifdef LEETCODE
int main()
{
	TreeNode node1(1), node2(2), node3(3);
	node1.left = &node2;
	node1.right = &node3;
	Solution().sumNumbers(&node1);
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