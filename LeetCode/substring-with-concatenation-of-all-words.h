/*
*	https://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/
*/

#define LEETCODE
#include <cassert>
#include <functional>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
	struct MatchState {
		MatchState() : count(0), start(0) {}
		
		unordered_map<string, int> dict;
		int count, start;
	};

    vector<int> findSubstring(string S, vector<string> &L) {
		unordered_map<string, int> dict;
		for (auto &str : L)
			dict[str]++;
		vector<int> ans;
		int len = L[0].size();
		vector<MatchState> matches(S.size()+1);
		for (int i = len; i < matches.size(); ++i) {
			string str = S.substr(i-len, len);
			if (dict[str] == 0) continue;

			matches[i] = matches[i-len];
			if (matches[i].count == 0)
				matches[i].start = i - len;
		
			if (matches[i].dict[str] < dict[str]) {
				matches[i].dict[str]++;
				matches[i].count++;
			}
			else {
				int start = matches[i].start;
				while (start < i) {
					string s = S.substr(start, len);
					if (s == str) break;
					matches[i].dict[s]--;
					matches[i].count--;
					start += len;
				}
				matches[i].start = start + len;
			}
			if (matches[i].count == L.size())
				ans.push_back(matches[i].start);
		}	

        return ans;
    }
};