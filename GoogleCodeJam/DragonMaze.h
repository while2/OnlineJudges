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
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Pos {
	int x, y;
};
int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int n, m; scanf("%d %d", &n, &m);
		Pos s, e;
		scanf("%d %d %d %d", &s.x, &s.y, &e.x, &e.y);
		swap(s.x, s.y), swap(e.x, e.y);

		vector<vector<int>> maze(n);
		for (int i = 0; i < n; ++i) {
			maze[i].resize(m);
			for (int j = 0; j < m; ++j)
				scanf("%d", &maze[i][j]);
		}

		queue<Pos> q;
		q.push(s);

		vector<vector<bool>> visited(n);
		vector<vector<int>> energy(n);
		for (int i = 0; i < n; ++i) {
			visited[i].resize(m, false);
			energy[i].resize(m, 0);
		}		
		visited[s.y][s.x] = true;
		energy[s.y][s.x] = maze[s.y][s.x];
		maze[s.y][s.x] = -1;
		while (!q.empty()) {
			Pos pos = q.front();
			q.pop();
			auto parse = [&](int x, int y) {
				if (x < 0 || x >= m) return;
				if (y < 0 || y >= n) return;
				
				if (maze[y][x] != -1) {
					energy[y][x] = max(energy[y][x], energy[pos.y][pos.x] + maze[y][x]);

					if (!visited[y][x]) {
						Pos next = {x, y};
						q.push(next);
						visited[y][x] = true;
					}
				}
			};

			if (pos.x == e.x && pos.y == e.y)
				goto exit;					

			parse(pos.x-1, pos.y);
			parse(pos.x+1, pos.y);
			parse(pos.x, pos.y-1);
			parse(pos.x, pos.y+1);
		}
		printf("Case #%d: Mission Impossible.\n", t);
		continue;
exit:
		printf("Case #%d: %d\n", t, energy[e.y][e.x]);
	}
	return 0;
}