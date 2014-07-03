/*
*	https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
*/

#define LEETCODE
// Paste following to Online Judge system
#include <vector>
#include <string>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

#ifdef LEETCODE
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
#endif

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL) return;
		queue<TreeLinkNode*> q;
		q.push(root), q.push(NULL);
		TreeLinkNode *last = NULL;
		while (!q.empty()) {
			auto node = q.front(); q.pop();
			if (last != NULL)
				last->next = node;
			last = node;

			if (node == NULL) {
				if (q.empty()) break;
				q.push(NULL);
			}
			else {
				if (node->left != NULL)	q.push(node->left);
				if (node->right != NULL) q.push(node->right);
			}
		}
	}
};