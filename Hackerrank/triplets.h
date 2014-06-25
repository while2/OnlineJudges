/*
 *	https://www.hackerrank.com/challenges/triplets
 *	
 *	A Binary Indexed Tree solution
 *	
 *	Order1 records how many times a number has appeared
 *	Order2 records how many ascending sequences with
 *	length 2 has appeared so far, same as Order3 for 
 *	length 3.
 *	
 *	BIT accumulate method return the sum of counting
 *	in log(n) time.
 *
 */

#define HACKERRANK
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

template<typename Key, typename Value>
struct BIT {
	BIT(int size) : m_tree(size, 0) {
	}

	Key last_bit(Key key) {
		return key & (-key);
	}
	void Add(Key key, Value val) {
		while (key < m_tree.size()) {
			m_tree[key] += val;
			key += last_bit(key);
		}
	}
	Value Accumulate(Key key) {
		Value acc = 0;
		while (key > 0) {
			acc += m_tree[key];
			key -= last_bit(key);
		}
		return acc;
	}
	Value Get(Key key) {
		return Accumulate(key) - Accumulate(key-1);
	}
	void Set(Key key, Value val) {		
		Add(key, val - Get(key));
	}
	vector<Value> m_tree;
};

typedef long long int INT;
typedef int Key;

struct Node {
	int val, idx;
};

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n; scanf("%d", &n);
	vector<Node> input(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &input[i].val);
		input[i].idx = i;
	}
	sort(input.begin(), input.end(),
		[](const Node &a, const Node &b)->bool
	{
		return a.val < b.val;
	});

	vector<int> normalized(n);
	int cur = 1;
	normalized[input[0].idx] = cur;
	for (int i = 1; i < n; ++i) {
		if (input[i].val != input[i-1].val) cur++;
		normalized[input[i].idx] = cur;
	}

	BIT<Key, INT> order1(cur+1);
	BIT<Key, INT> order2(cur+1);
	BIT<Key, INT> order3(cur+1);

	for (int i = 0; i < n; ++i) {
		int key = normalized[i];
		order3.Set(key, order2.Accumulate(key-1));
		order2.Set(key, order1.Accumulate(key-1));
		order1.Set(key, 1);
	}
	printf("%lld\n", order3.Accumulate(cur));
	return 0;
}
