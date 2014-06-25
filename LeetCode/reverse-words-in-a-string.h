/*
 *	https://oj.leetcode.com/problems/reverse-words-in-a-string/
 */

#define LEETCODE
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		string temp, result;
		for (int i = s.size() - 1; i >= 0; --i) {
			char c = s[i];
			if (c == ' ' && !temp.empty()) {
				while (!temp.empty()) {
					result.push_back(temp.back());
					temp.pop_back();
				}
				result.push_back(' ');
			}
			else if (c != ' '){
				temp.push_back(c);
			}
		}
		if (!temp.empty()) {
			while (!temp.empty()) {
				result.push_back(temp.back());
				temp.pop_back();
			}
		}
		s.swap(result);
		if (s.back() == ' ')
			s.pop_back();
	}
};