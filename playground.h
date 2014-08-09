#include <stdint.h>

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Customer
{
	Customer() : malted(-1) {}
	int malted;
	vector<int> unmalted;
	bool satisfied(const vector<int> &flavors) {
		if (malted != -1 && flavors[malted] == 1)
			return true;
		for (auto id : unmalted)
			if (flavors[id] == 0)
				return true;
		return false;
	}
};

int main() {
	int T; scanf("%d%*c", &T);
	for (int t = 1; t <= T; ++t) {
		int n, m; scanf("%d %d", &n, &m);
		vector<Customer> customers(m);
		for (int i = 0; i < m; ++i) {
			int pairs; scanf("%d", &pairs);
			while (pairs--) {
				int a, b;
				scanf("%d %d", &a, &b);
				--a;
				if (b == 1)
					customers[i].malted = a;
				else
					customers[i].unmalted.push_back(a);
			}
		}
		printf("Case #%d: ", t);
		vector<int> flavors(n, 0);
		bool changed = true;
		while (changed) {
			changed = false;
			for (auto customer : customers) {
				if (!customer.satisfied(flavors)) {
					if (customer.malted != -1) {
						flavors[customer.malted] = 1;
						changed = true;
					}
					else
						goto impossible;
				}
			}
		}
		for (auto i : flavors)
			printf("%d ", i);
		printf("\n");
		continue;
impossible:
		printf("IMPOSSIBLE\n");
	}
	return 0;
}