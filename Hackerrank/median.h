/*
 *	https://www.hackerrank.com/challenges/median
 *	
 *	map solution got TLE
 *	might be the iterator ++ operation, I thought map/set 
 *	is an RB-Tree with indices, so it++ takes O(1) time.
 *	It's not.
 *	it++ takes time to search the smallest element in the right subtree,
 *	or if the node is a left child and has no right child, the smallest 
 *	element in the right sibling.
 *	It's O(h) where h is the height of node.
 *	but the amortized time ends up with O(n).
 *	Still don't know why.
 *	
 */

#define HACKERRANK
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long INT;

int main(void){
	int n; scanf("%d\n", &n);
	vector<int> data;
	while (n--) {
		char t; int a;
		scanf("%c %d\n", &t, &a);
		
		auto it = std::lower_bound(data.begin(), data.end(), a);
		if (t == 'a') {			
			data.insert(it, a);
		}
		else if (t == 'r') {
			if (it == data.end() || *it != a) {
				printf("Wrong!\n");
				continue;
			}
			else {
				data.erase(it);
			}
		}

		if (data.empty()) {
			printf("Wrong!\n");
			continue;
		}

		int mid = data.size() / 2;
		if (mid * 2 == data.size())
		{
			INT a = data[mid-1], b = data[mid];
			INT sum = a + b;
			if (sum % 2==0)
				printf("%lld\n", sum/2);
			else
				printf("%0.1lf\n", 0.5 * sum);
		}
		else
		{
			printf("%d\n", data[mid]);
		}
	}

	return 0;
}