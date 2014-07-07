#pragma warning (disable : 4996)
#pragma warning (disable : 4018)

#include "LeetCode\construct-binary-tree-from-inorder-and-postorder-traversal.h"
#ifdef LEETCODE
int main()
{
	int inorder[] = {1,2,3,4};
	int postorder[] = {1,4,3,2};

	Solution().buildTree(vector<int>(begin(inorder), end(inorder)), vector<int>(begin(postorder), end(postorder)));
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