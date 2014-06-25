/*
 *	https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
 */

#define LEETCODE
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		vector<int> s;
		for (int i = 0; i < tokens.size(); ++i) {
			int a;
			if (sscanf(tokens[i].c_str(), "%d", &a) == 1) {
				s.push_back(a);
			}
			else {
				int b = s.back(); s.pop_back();
				int a = s.back(); s.pop_back();
				switch (tokens[i][0]) {
				case '+':
					s.push_back(a+b);
					break;
				case '-':
					s.push_back(a-b);
					break;
				case '*':
					s.push_back(a*b);
					break;
				case '/':
					s.push_back(a/b);
					break;
				}
			}
		}
		return s[0];
	}
};