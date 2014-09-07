/*
*	https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
		auto result = [&](int a, int b) -> double {
			vector<int> candidates;
			candidates.push_back(A[a]);
			candidates.push_back(B[b]);
			
			if (a+1 < m)
				candidates.push_back(A[a+1]);
			if (b+1 < n)
				candidates.push_back(B[b+1]);
			
			sort(begin(candidates), end(candidates));
			if ((m + n) % 2 == 0)
				return (candidates[0] + candidates[1]) * 0.5;
			else
				return candidates[0];
		};

		int k = (m + n - 1) / 2;

		if (m == 0)
			return result(0, k);
		if (n == 0)
			return result(k, 0);

		if (A[m-1] < B[0]) {
			if (m > k)
				return result(k, 0);
			else
				return result(m, k-m);
		}
		if (A[0] > B[n-1]) {
			if (n > k)
				return result(0, k);
			else
				return result(k-n, n);
		}

		int a1 = 0, a2 = m, b1 = 0, b2 = n;
		for (;;) {
			int a = (a1+a2)/2;
			int b = (b1+b2)/2;

			if (a + b == k) {
				return result(a, b);
			}
			else if (a + b > k) {
				if (A[a-1] < B[b-1])
					b2 = b;
				else
					a2 = a;
			}
			else {
				if (A[a-1] < B[b-1]) {
					k -= (a1 - a);
					a1 = a;
				}
				else {
					k -= (b1 - b);
					b1 = b;
				}
			}
		}
    }
};