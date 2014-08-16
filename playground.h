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

bool red_wins(vector<string> &board) {
	int n = board.size();
	vector<int> row(n, 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] != 'R')
				row[j] = 0;
			else if (j+1 < n)
				row[j] += row[j+1];
		}
	}

	for (int i = 0; i < n; ++i) {
		if (row[i] > 0)
			return true;
	}
	return false;
}

bool blue_wins(vector<string> &board) {
	int n = board.size();
	vector<int> col(n, 1);
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < n; ++i) {
			if (board[i][j] != 'B')
				col[i] = 0;
			else if (i+1 < n)
				col[i] += col[i+1];
		}
	}

	for (int i = 0; i < n; ++i) {
		if (col[i] > 0)
			return true;
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