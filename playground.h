#include <stdio.h>
#include <cmath>
#include <list>
#include <string>
using namespace std;

int main() {
	int T; scanf("%d\n", &T);
	for (int t = 1; t <= T; ++t) {
		int n; scanf("%d\n", &n);
		list<string> cards;
		while (n--) {
			char name[111];
			scanf("%[^\n]\n", name);
			cards.push_back(name);
		}

		int cost = 0;
		bool changed = true;
		while (changed) {
			changed = false;
			auto it1 = cards.begin();
			auto it2 = it1; ++it2;

			for (; it2 != cards.end(); ++it1) {
				if (*it2 < *it1) {
					// insert it2
					cost++;
					changed = true;
					auto it3 = cards.begin();
					while (*it3 < *it2)
						++it3;
					cards.insert(it3, *it2);
					it2 = cards.erase(it2);
				}
				else
					++it2;
			}
		}
		printf("Case #%d: %d\n", t, cost);
	}
	return 0;
}