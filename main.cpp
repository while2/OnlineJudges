#pragma warning (disable : 4996)
#pragma warning (disable : 4018)

#include "LeetCode\clone-graph.h"
#ifdef LEETCODE
int main()
{
	UndirectedGraphNode node0(0), node1(1), node2(2);
	node0.neighbors.push_back(&node1);
	node0.neighbors.push_back(&node2);

	node1.neighbors.push_back(&node0);
	node1.neighbors.push_back(&node2);

	node2.neighbors.push_back(&node0);
	node2.neighbors.push_back(&node1);
	node2.neighbors.push_back(&node2);

	auto clone = Solution().cloneGraph(&node0);
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