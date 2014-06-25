/*
*	https://oj.leetcode.com/problems/surrounded-regions/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <functional>
using namespace std;

class UFSet {
public:
	UFSet(size_t size) : m_parents(size) {
		for (int i = 0; i < size; ++i)
			m_parents[i] = i;
	}

	int Root(int a) {
		while (m_parents[a] != a) {
			a = m_parents[a] = m_parents[m_parents[a]];
		}
		return a;
	}
	bool Merge(int a, int b) {
		int ra = Root(a), rb = Root(b);
		m_parents[ra] = rb;
		return ra != rb;
	}

private:
	vector<int> m_parents;
};

class Solution {
public:	
    void solve(vector<vector<char>> &board) {
		if (board.empty()) return;
		int rows = board.size(), cols = board[0].size();
        UFSet ufs(rows * cols + 1);	// nodes [0, n-1] for pixels, node n for boundary

		auto get_id = [&](int x, int y)->int {
			return y * cols + x;
		};

		for (int y = 0; y < rows; ++y) {
			for (int x = 0; x < cols; ++x) {
				if (board[y][x] == 'X')
					continue;

				int id = get_id(x, y);
				if (y == 0)
					ufs.Merge(id, rows*cols);
				else if (board[y-1][x] == 'O')
					ufs.Merge(id, get_id(x, y-1));

				if (y == rows-1)
					ufs.Merge(id, rows*cols);
				else if (board[y+1][x] == 'O')
					ufs.Merge(id, get_id(x, y+1));

				if (x == 0)
					ufs.Merge(id, rows*cols);
				else if (board[y][x-1] == 'O')
					ufs.Merge(id, get_id(x-1, y));

				if (x == cols-1)
					ufs.Merge(id, rows*cols);
				else if (board[y][x+1] == 'O')
					ufs.Merge(id, get_id(x+1, y));
			}
		}

		int boundary_root = ufs.Root(rows*cols);
		for (int y = 0; y < rows; ++y) {
			for (int x = 0; x < cols; ++x) {
				if (ufs.Root(get_id(x, y)) != boundary_root)
					board[y][x] = 'X';
			}
		}
    }
};