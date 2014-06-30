#pragma warning (disable : 4996)
#pragma warning (disable : 4018)

#include "LeetCode\word-ladder.h"
#ifdef LEETCODE
int main()
{
	char *dict[] = {"hot","dot","dog","lot","log"};

	Solution().ladderLength("hit", "cog", unordered_set<string>(begin(dict), end(dict)));
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