#pragma warning (disable : 4996)
#pragma warning (disable : 4018)

#include "LeetCode\copy-list-with-random-pointer.h"
#ifdef LEETCODE
int main()
{
	RandomListNode node0(0), node1(1);
	node0.next = &node1;
	node1.random = &node0;
	auto clone = Solution().copyRandomList(&node0);
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