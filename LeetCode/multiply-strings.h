/*
*	https://oj.leetcode.com/problems/multiply-strings/
*/

#define LEETCODE
#include <cassert>
#include <functional>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.size() + num2.size(), 0);
        for (int i = num1.size()-1; i >= 0; --i) {
            int a = num1[i] - '0';
            int k = num1.size() - i - 1;
			int carry = 0;
            for (int j = num2.size()-1; j >= 0; --j) {
                int b = num2[j] - '0';
                carry += a * b + result[k];
                result[k++] = carry % 10;
                carry /= 10;
            }
			while (carry) {
				carry += result[k];
				result[k++] = carry % 10;
				carry /= 10;
			}
        }
        while (result.size() > 1 && result.back() == 0)
            result.pop_back();
        for (int i = 0; i < result.size(); ++i)
            result[i] += '0';
            
        for (int i = 0, j = result.size()-1; i < j; ++i, --j) {
            swap(result[i], result[j]);
        }
        return result;
    }
};