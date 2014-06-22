#define LEETCODE

#ifdef LEETCODE
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

#include "LeetCode\word-break.h"
int main()
{
	auto input1 = "abcd";
	char* input2[] = {"a","abc","b","cd"};

	string s = input1;
	unordered_set<string> dict;
	for (auto word : input2)
		dict.insert(word);
	Solution().wordBreak(s, dict);
}

#endif