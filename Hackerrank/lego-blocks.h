/*	
 *	https://www.hackerrank.com/challenges/lego-blocks
 *	
 *	h:				height
 *	w:				width
 *	row[w]:			number of combinations for a 1 * w wall
 *	all(h, w):		number of combinations for a h * w wall, including seam
 *	solid(h, w):	number of combinations for a h * w wall, without seams
 *	
 *	First solve the 1 dim problem, for a 1 * w sized wall
 *	the solution is:
 *	row[w] = row[w-1] + row[w-2] + row[w-3] + row[w-4]
 *	
 *	combinations including unsolid cases:
 *	all(h, w) = (row[w])^h
 *	
 *	solid combinations:
 *	solid(h, w) = all(h, w) - \sum_{i+j=w}{all(h, i) * solid(h, j)}
 *	split the wall through the last seam, the left part is the sub problem
 *	for all cases including seams, the right part is solid combinations
 */

#define HACKERRANK
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
static const int P = 1000000007;
static const int N = 1000 + 5;
typedef long long INT;
static INT row_buff[N+4] = {0, 0, 0, 0, 1};	// row[0] = 1, row[-4,-1] = 0;
static INT *row = row_buff + 4;

static INT all[N], solid[N];

void init_row() {
	for (int i = 1; i < N; ++i) {
		row[i] = row[i-1] + row[i-2] + row[i-3] + row[i-4];
		row[i] %= P;
	}
}

INT my_pow(INT a, int b) {
	INT ans = 1;
	for (unsigned int mask = 1 << 31; mask > 0; mask >>= 1) {
		ans *= ans; ans %= P;
		if (b & mask) {
			ans *= a; ans %= P;
		}
	}
	return ans;
}

INT solve_solid(int h, int w) {
	if (h == 1 && w <= 4)
		return 1;
	if (h == 1)
		return 0;
	for (int i = 1; i <= w; ++i) {
		solid[i] = all[i] = my_pow(row[i], h);
		for (int j = 1; j < i; ++j) {
			solid[i] += (P - (all[j] * solid[i-j]) % P);
			solid[i] %= P;
		}
	}
	return solid[w];
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	init_row();
	int t; scanf("%d", &t);
	while (t--) {
		int h, w; scanf("%d %d", &h, &w);
		printf("%lld\n", solve_solid(h, w));
	}
	return 0;
}
