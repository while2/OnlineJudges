/*
 *	https://www.hackerrank.com/challenges/even-tree
 *
 *	Count the nodes who have even number of children
 *
 */

#define HACKERRANK
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	int n, m; scanf("%d %d", &n, &m);
	vector<vector<int>> G(n);
	vector<int> count(n, 0);
	while (m--) {
		int ui, vi; scanf("%d %d", &ui, &vi);
		ui--, vi--;
		G[ui].push_back(vi);
		G[vi].push_back(ui);
	}
	
	function<void(int)> dfs;
	dfs = [&](int id) {
		count[id] = 1;
		for (int i = 0; i < G[id].size(); ++i) {
			if (count[G[id][i]] == 0) {
				dfs(G[id][i]);
				count[id] += count[G[id][i]];
			}
		}
	};
	dfs(0);
	
	int even = 0;
	for (int i = 0; i < n; ++i) {
		if (count[i] % 2 == 0) {
			even++;
		}
	}
	printf("%d\n", even-1);
	return 0;
}
