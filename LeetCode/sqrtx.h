/*
*	https://oj.leetcode.com/problems/sqrtx/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <stdint.h>
using namespace std;
typedef int64_t INT;
class Solution {
public:
    int sqrt(int x) {
        INT a = 1, b = x;
        while (true) {
            if (a*a <= b && (a+1)*(a+1) > b)
                return a;
            a = (a + b/a) / 2;
        }
    }
};