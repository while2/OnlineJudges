#define LEETCODE

#ifdef LEETCODE

#include "LeetCode\clone-graph.h"
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