#pragma warning (disable : 4996)
#pragma warning (disable : 4018)

#include "LeetCode\populating-next-right-pointers-in-each-node-ii.h"
#ifdef LEETCODE
int main()
{
	TreeLinkNode node1(1), node2(2), node3(3), node4(4), node5(5), node7(7);
	node1.left = &node2, node1.right = &node3;
	node2.left = &node4, node2.right = &node5;
	node3.right = &node7;
	Solution().connect(&node1);
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