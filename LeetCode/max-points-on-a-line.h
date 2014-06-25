/*
*	https://oj.leetcode.com/problems/max-points-on-a-line/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};


class Solution {
public:
	struct Line {
		int a, b;
		bool operator < (const Line &rhs) const {
			if (a == rhs.a) return b < rhs.b;
			else return a < rhs.a;
		}
	};
	int gcd(int a, int b) {
		if (a < 0) return gcd(-a, b);
		if (b < 0) return gcd(a, -b);

		if (a < b) swap(a, b);
		while (b) {
			int temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}
	int maxPoints(vector<Point> &points) {
		if (points.size() <= 1) {
			return points.size();
		}
		int max_points = 0;
		for (int i = 0; i < points.size(); ++i) {
			auto &p1 = points[i];
			int same = 0;
			map<Line, int> lines;
			for (int j = 0; j < points.size(); ++j) {
				auto &p2 = points[j];
				if (p1.x == p2.x && p1.y == p2.y) {
					same++;
				}
				else {
					int dx = p1.x - p2.x;
					int dy = p1.y - p2.y;
					int d = gcd(dx, dy);
					dx/=d, dy/=d;
					if (dx < 0) {
						dx = -dx, dy = -dy;
					}
					Line line = {dx, dy};
					lines[line]++;
				}
			}
			int max_lines = 0;
			for (auto it = lines.begin(); it != lines.end(); ++it) {
				max_lines = max(max_lines, it->second);
			}
			max_lines += same;
			max_points = max(max_points, max_lines);
		}
		return max_points;
	}
};