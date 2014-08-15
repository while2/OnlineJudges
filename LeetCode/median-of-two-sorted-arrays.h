/*
*	https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
using namespace std;
class Solution {
public:
	double 
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
		auto result = [&](int a, int b) -> double {
			if ((m + n) % 2 == 0) {
				if (a == m) return 0.5 * (B[b] + B[b+1]);
				if (b == n) return 0.5 * (A[b] + A[b+1]);			
				return 0.5 * (A[a] + B[b]);
			}
			else {
				if (a == m) return B[b];
				if (b == n) return A[a];
				return min(A[a], B[b]);
			}
		};
		int k = (m + n - 1) / 2;
		int sa = 0, ea = m, sb = 0, eb = n;
		while (true) {
			int ma = (sa + ea) / 2;
			int mb = (sb + eb) / 2;

			if (ea - sa <= 1 && eb - sb <= 1) {
				return result(ma, mb);
			}
			
			if (ma + mb < k) {
				if (A[ma] < B[mb]) {
					sa = ma;
				}
				else
					sb = mb;
			}
			else {
				if (A[ma] < B[mb])
					eb = mb;
				else
					ea = ma;
			}
		}
    }
};