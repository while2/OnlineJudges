#pragma warning (disable : 4996)
#pragma warning (disable : 4018)

#include "LeetCode\surrounded-regions.h"
#ifdef LEETCODE
int main()
{
	char *input[] = {"XOXX","OXOX","XOXO","OXOX","XOXO","OXOX"};
	vector<vector<char>> board;
	for (int i = 0; i < sizeof(input) / sizeof(input[0]); ++i) {
		board.push_back(vector<char>(input[i], input[i] + 4));
	}
	Solution().solve(board);
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