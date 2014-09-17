#include <stdio.h>
#include <cmath>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stdint.h>
#include <algorithm>
#include <queue>
#include <functional>
#include <iostream>
#include <vector>
#include <limits>
#include <stdint.h>
using namespace std;

typedef uint64_t UINT;
static const int N = 101;
UINT comb[N][N];
void init_comb() {
	memset(comb, 0, N*N*sizeof(UINT));
	for (int b = 1; b < N; ++b)
		comb[0][b] = 1;

	for (int a = 1; a < N; ++a) {
		comb[a][a] = comb[a-1][a];
		for (int b = a+1; b < N; ++b) {
			if (comb[a][b-1] < UINT64_MAX - comb[a-1][b])
				comb[a][b] = comb[a][b-1] + comb[a-1][b];
			else
				comb[a][b] = UINT64_MAX;
		}
	}
}

string solve(int n, UINT k) {
	if (k >= comb[n][n])
		return "Doesn't Exist!";
	string ans = "(";
	int a = n-1, b = n;
	while (a > 0) {
		if (k >= comb[a-1][b]) {
			ans += ")";
			k -= comb[a-1][b];
			b--;
		}
		else {
			ans += "(";
			a--;
		}
	}
	while (b--)
		ans += ")";
	return ans;
}

int main() {
	init_comb();
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int n;
		UINT k;
		scanf("%d %llu", &n, &k);
		printf("Case #%d: %s\n", t, solve(n, k-1).c_str());
	}
	return 0;
}