/*
*	https://oj.leetcode.com/problems/minimum-window-substring/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
		unordered_map<char, int> tex, pat;
		for (auto c : T)
			pat[c]++;

		int s = 0, e = -1, count = 0;
		
		for (e = s; e < S.size(); ++e) {
			tex[S[e]]++;
			if (tex[S[e]] == pat[S[e]]) {
				count += pat[S[e]];
				if (count == T.size())
					break;
			}
		}

		if (count < T.size())
			return "";
				
		while (s < e && pat[S[s]] == 0 || tex[S[s]] > pat[S[s]]) {
			tex[S[s]]--;
			s++;
		}

		int s0 = s, e0 = e;
		for (++e; e < S.size(); ++e) {
			tex[S[e]]++;
			while (s < e && pat[S[s]] == 0 || tex[S[s]] > pat[S[s]]) {
				tex[S[s]]--;
				s++;
			}
			if (e0 - s0 > e - s)
				e0 = e, s0 = s;
		}
		
		return S.substr(s0, e0-s0+1);
    }
};