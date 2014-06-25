/*
 *	https://www.hackerrank.com/challenges/xor-key
 *
 *	Use Trie to build indices
 *	
 *	
 */

#define HACKERRANK
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const int MAXB = 15;

struct Node {
	Node() : left(nullptr), right(nullptr) {}
	Node *left, *right;
	vector<int> indices;
};

void BuildTrie(vector<int> &a, int i, Node *root, int bit) {
	if (bit < 0) return;
	if (a[i] & (1<<bit)) {
		if (root->left == nullptr) {
			root->left = new Node;
		}
		root->left->indices.push_back(i);
		BuildTrie(a, i, root->left, bit-1);
	}
	else {
		if (root->right == nullptr) {
			root->right = new Node;
		}
		root->right->indices.push_back(i);
		BuildTrie(a, i, root->right, bit-1);
	}
}

Node *BuildTrie(vector<int> &a) {
	Node *root = new Node;
	for (int i = 0; i < a.size(); ++i) {
		BuildTrie(a, i, root, MAXB-1);
	}
	return root;
}

bool Overlap(vector<int> &indices, int p, int q) {
	// for x in [p, q]
	// it1 == x, it2 == q+
	// x <= q < q+
	// it1 < it2
	// 
	// if no index in [p, q]
	// it1 == q+, it2 == q+
	// it1 == it2

	auto it1 = lower_bound(indices.begin(), indices.end(), p);
	auto it2 = upper_bound(indices.begin(), indices.end(), q);
	return it1 < it2;
}

int Query(Node *root, int a, int p, int q) {
	int ans = 0;
	Node *node = root;
	for (int b = MAXB-1; b >= 0; --b) {
		if (node == nullptr)
			break;
		if (a & (1<<b)) {
			if (node->right && Overlap(node->right->indices, p, q)) {
				ans |= (1 << b);
				node = node->right;
			}
			else
				node = node->left;
		}
		else {
			if (node->left && Overlap(node->left->indices, p, q)) {
				ans |= (1 << b);
				node = node->left;
			}
			else
				node = node->right;
		}
	}
	return ans;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d %d", &n, &m);
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);
		
		Node *root = BuildTrie(arr);
		while (m--) {
			int a, p, q; scanf("%d %d %d", &a, &p, &q);
			printf("%d\n", Query(root, a, p-1, q-1));
		}
	}
}