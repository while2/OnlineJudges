/*
*	https://oj.leetcode.com/problems/maximum-product-subarray/
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
    int maxProduct(int A[], int n) {
        if (n == 1) return A[0];
        int ans = A[0];
        int acc_max = 1, acc_min = 1;
        for (int i = 0; i < n; ++i) {
            acc_max *= A[i];
            acc_min *= A[i];
			if (acc_max < acc_min)
				swap(acc_max, acc_min);
            ans = max(ans, acc_max);
            if (acc_max < 1)
                acc_max = 1;
            if (acc_min > -1)
                acc_min = 1;
        }
        return ans;
    }
};