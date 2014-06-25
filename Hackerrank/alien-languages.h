/*
 *	https://www.hackerrank.com/challenges/alien-languages
 *	
 *	Alphabet [a1, a2, ... , b1, b2...]
 *	ai belongs to the first half and bi the last half.
 *	Consider an array [A1, A2, ..., An] to store the
 *	number of words begin with the specific letter,
 *	with length 1, it looks like [0, 0, ..., 1, 1, ...],
 *	cause only bi can be the end of a word. By putting
 *	one letter in front of the each given words, we	can
 *	update the array to the case with length increased.
 *	
 *	Ai should be updated to sum[Ai*2, An] since ai can be
 *	followed by any letter after Ai*2, inclusivly.
 *	Use accumulate array to speed up to O(m*n), still TLE.
 */

#define HACKERRANK
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
static const int P = 100000007;
typedef unsigned long long INT;

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d %d\n", &n, &m);
		vector<int> count(n+1, 0);
		vector<int> accumulate(n+1, 0);
		for (int i = n/2+1; i <= n; ++i)
			count[i] = 1;

		for (int i = 1; i <= n; ++i) {
			INT sum = accumulate[i-1] + count[i];
			accumulate[i] = sum % P;
		}
		while (--m) {
			for (int i = n; i > n/2; --i) {
				count[i] = accumulate[n];
			}
			for (int i = n/2; i > 0; --i) {
				INT sum = P + accumulate[n] - accumulate[i*2-1];
				count[i] = sum % P;
			}

			for (int i = 1; i <= n; ++i) {
				INT sum = accumulate[i-1] + count[i];
				accumulate[i] = sum % P;
			}
		}
		printf("%d\n", accumulate[n]);
	}
	return 0;
}
