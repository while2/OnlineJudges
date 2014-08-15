#include <stdint.h>
#include <stdio.h>

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef uint64_t INT;

void ReadFlow(INT &flow, char buff[], int l) {
	flow = 0;
	for (int i = 0; i < l; ++i)
		if (buff[i] == '1')
			flow |= ((INT)1 << i);
}

int BitCount(INT bits) {
	int count = 0;
	while (bits) {
		count++;
		bits &= (bits - 1);
	}
	return count;
}

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int n, l; scanf("%d %d", &n, &l);

		vector<INT> src(n), dst(n);
		char buff[44];
		for (int i = 0; i < n; ++i) {
			scanf("%s", &buff);
			ReadFlow(src[i], buff, l);
		}
		for (int i = 0; i < n; ++i) {
			scanf("%s", &buff);
			ReadFlow(dst[i], buff, l);
		}

		vector<vector<INT>> flip_map(n);
		unordered_map<INT, int> flip_count;
		for (int i = 0; i < n; ++i) {
			flip_map[i].resize(n);
			for (int j = 0; j < n; ++j) {
				flip_map[i][j] = src[i] ^ dst[j];
				flip_count[src[i] ^ dst[j]]++;
			}
		}

		int flips = l + 1;
		for (auto &pair : flip_count) {
			if (pair.second == n)
				flips = min(flips, BitCount(pair.first));
		}
		if (flips == l + 1)
			printf("Case #%d: NOT POSSIBLE\n", t);
		else
			printf("Case #%d: %d\n", t, flips);
	}
	return 0;
}