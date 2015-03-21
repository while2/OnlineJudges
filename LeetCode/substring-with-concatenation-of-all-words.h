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
    vector<int> findSubstring(string S, vector<string> &L) {
		unordered_map<string, int> dict;
		for (auto &str : L)
			dict[str]++;
			
	    vector<int> ans;
		for (int start = 0; start < L[0].size(); ++start) {
		    unordered_map<string, int> dict2;
		    int s = start, count = 0;
		    for (int i = start; i < S.size(); i += L[0].size()) {
		        string str = S.substr(i, L[0].size());
		        if (dict[str] == 0) {
					dict2.clear();
		            count = 0;
		            s = i + L[0].size();
		            continue;
		        }
		        dict2[str]++;
				count++;
		        if (dict2[str] > dict[str]) {
		            for (;;) {
		                string head = S.substr(s, L[0].size());
		                dict2[head]--;
		                count--;
						s+=L[0].size();
		                if (head == str)
		                    break;
		            }
		        }
		        if (count == L.size())
		            ans.push_back(s);
		    }
		}
        return ans;
    }
};