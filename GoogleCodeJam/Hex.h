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

template<class EndFunc>
bool connected(vector<string> board, char stone, Pos start, EndFunc end_func) {
	int n = board.size();
	queue<Pos> q;
	q.push(start);
	while (!q.empty()) {
		Pos p = q.front(); q.pop();
		if (end_func(p))
			return true;
		auto parse = [&](int x, int y) {
			if (x < 0 || x >= n) return;
			if (y < 0 || y >= n) return;
			if (board[y][x] == stone) {
				Pos pos = {x, y};
				q.push(pos);
				board[y][x] = '.';
			}
		};
		parse(p.x-1, p.y);
		parse(p.x+1, p.y);
		parse(p.x, p.y-1);
		parse(p.x, p.y+1);
		parse(p.x+1, p.y-1);
		parse(p.x-1, p.y+1);
	}
	return false;
}

bool red_wins(vector<string> &board) {
	int n = board.size();
	for (int i = 0; i < n; ++i) {
		if (board[0][i] == 'R') {
			Pos start = {i, 0};
			if (connected(board, 'R', start, 
				[&](const Pos &pos) { return pos.y == n-1;}))
				return true;
		}
	}
	return false;
}

bool blue_wins(vector<string> &board) {
	int n = board.size();
	for (int i = 0; i < n; ++i) {
		if (board[i][0] == 'B') {
			Pos start = {0, i};
			if (connected(board, 'B', start, 
				[&](const Pos &pos) { return pos.x == n-1;}))
				return true;
		}
	}
	return false;
}


int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int n; scanf("%d", &n);
		vector<string> board(n);
		int count_r = 0, count_b = 0;
		for (int i = 0; i < n; ++i) {
			board[i].resize(n+1);
			scanf("%s", board[i].data());
			for (int j = 0; j < n; ++j) {
				if (board[i][j] == 'R')
					count_r++;
				if (board[i][j] == 'B')
					count_b++;
			}
		}

		if (abs(count_r - count_b) > 1) {
impossible:
			printf("Case #%d: Impossible\n", t);
			continue;
		}

		if (red_wins(board) && blue_wins(board))
			goto impossible;

		if (red_wins(board)) {
			if (count_r < count_b)
				goto impossible;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (board[i][j] == 'R') {
						board[i][j] = '.';
						if (!red_wins(board)) {
							goto red;
						}
						board[i][j] = 'R';
					}
				}
			}
			goto impossible;
		}
		
		if (blue_wins(board)) {
			if (count_b < count_r)
				goto impossible;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (board[i][j] == 'B') {
						board[i][j] = '.';
						if (!blue_wins(board))
							goto blue;
						board[i][j] = 'B';
					}
				}
			}
			goto impossible;
		}

		printf("Case #%d: Nobody wins\n", t);
		continue;

red:
		printf("Case #%d: Red wins\n", t);
		continue;
blue:
		printf("Case #%d: Blue wins\n", t);
		continue;

	}
	return 0;
}