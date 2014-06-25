/*
*	https://oj.leetcode.com/problems/candy/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int candy(vector<int> &ratings) {
		vector<int> candies(ratings.size(), 1);
		for (int i = 1; i < candies.size(); ++i) {
			if (ratings[i] > ratings[i-1] && candies[i] <= candies[i-1]) {
				candies[i] = candies[i-1] + 1;
			}
		}
		for (int i = candies.size()-2; i >= 0; --i) {
			if (ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) {
				candies[i] = candies[i+1] + 1;
			}
		}

		int sum = 0;
		for (int i = 0; i < candies.size(); ++i)
			sum += candies[i];
		return sum;
	}
};