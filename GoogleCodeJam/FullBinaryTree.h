#include <stdio.h>
#include <cmath>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <stdint.h>
#include <algorithm>
#include <queue>
#include <functional>
#include <iostream>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int n; scanf("%d", &n);
		vector<vector<int>> graph(n);
		for (int i = 1; i < n; ++i) {
			int a, b; scanf("%d %d", &a, &b);
			--a, --b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		vector<char> used(n);
		function<int(int)> tree_size;
		tree_size = [&](int r) {
			used[r] = true;
			vector<int> children;
			for (auto p : graph[r]) {
				if (!used[p])
					children.push_back(tree_size(p));
			}
			if (children.size() < 2)
				return 1;
			else {
				sort(begin(children), end(children), [](int a, int b)->bool { return a > b; });
				return 1 + children[0] + children[1];
			}
		};

		int max_size = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < used.size(); ++j)
				used[j] = false;
			max_size = max(max_size, tree_size(i));
		}

		printf("Case #%d: %d\n", t, n - max_size);
	}
}