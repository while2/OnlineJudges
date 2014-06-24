#define LEETCODE

#ifdef LEETCODE

#include "LeetCode\word-break-ii.h"
int main()
{
	auto input1 = "catsanddog";
	char* input2[] = {"cat", "cats", "and", "sand", "dog"};

	string s = input1;
	unordered_set<string> dict;
	for (auto word : input2)
		dict.insert(word);
	Solution().wordBreak(s, dict);
}

#endif