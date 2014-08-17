/*
 *	https://oj.leetcode.com/problems/palindrome-number/
 */

#define LEETCODE
#include <stdint.h>
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int head = 1;
        while (head *10 > head && head * 10 <= x)
            head *= 10;
            
        while (head > 1) {
            if (x / head != x % 10)
                return false;
            x %= head;
            x /= 10;
            head /= 100;
        }
        return true;
    }
};