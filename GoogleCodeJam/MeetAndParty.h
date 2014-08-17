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

typedef uint64_t INT;

struct Rect {
	int x1, y1, x2, y2;
};

struct Pos {
	int x, y;
	bool operator!=(const Pos &rhs) const {
		return x != rhs.x || y != rhs.y;
	}
};

Pos Closest(double x, double y, const Rect &rect) {
	Pos pos;
	if (x < rect.x1) pos.x = rect.x1;
	else if (x > rect.x2) pos.x = rect.x2;
	else pos.x = x;

	if (y < rect.y1) pos.y = rect.y1;
	else if (y > rect.y2) pos.y = rect.y2;
	else pos.y = y;

	return pos;
}

INT dist(int x, int y, vector<Rect> &rect) {
	INT sum = 0;
	auto acc = [](INT a, INT b)->INT {
		return (a + b) * (b-a+1) / 2;
	};

	for (int i = 0; i < rect.size(); ++i) {
		int w = rect[i].x2 - rect[i].x1 + 1;
		int h = rect[i].y2 - rect[i].y1 + 1;

		auto calc = [acc](int a, int b, int x)-> INT {
			INT sum = 0;
			if (x < a) {
				sum += acc(a-x, b-x);
			}
			else if (x > b) {
				sum += acc(x-b, x-a);
			}
			else {
				sum += acc(0, x-a) + acc(0, b-x);
			}
			return sum;
		};

		sum += calc(rect[i].x1, rect[i].x2, x) * h;
		sum += calc(rect[i].y1, rect[i].y2, y) * w;
	}
	return sum;
}

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int n; scanf("%d", &n);
		vector<Rect> rects(n);
		for (int i = 0; i < n; ++i) {
			Rect &rect = rects[i];
			scanf("%d %d %d %d", &rect.x1, &rect.y1, &rect.x2, &rect.y2);
		}

		
		Pos best_pos;
		INT best_d = INT_MAX;
		for (int i = 0; i < rects.size(); ++i) {
			
			auto update = [&](Pos pos) {
				INT d = dist(pos.x, pos.y, rects);
				if (best_d > d ||
					(best_d == d && (pos.x < best_pos.x) ||
					(pos.x == best_pos.x && pos.y < best_pos.y)))
				{
					best_d = d;
					best_pos = pos;
				}
			};

			for (int x = rects[i].x1; x <= rects[i].x2; ++x) {
				for (int y = rects[i].y1; y <= rects[i].y2; ++y) {
					Pos pos = {x, y};
					update(pos);
				}
			}
		}
		printf("Case #%d: %d %d %llu\n", t, best_pos.x, best_pos.y, best_d);
	}
	return 0;
}