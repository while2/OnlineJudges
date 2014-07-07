/*
*	https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
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
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		function<TreeNode*(ListNode *start, ListNode *end)> parse;
		parse = [&](ListNode *start, ListNode *end)->TreeNode* {
			if (start == end) return NULL;
			ListNode *mid = start;
			for (auto p = start; p != end && p->next != end; p = p->next->next)
				mid = mid->next;
			TreeNode *node = new TreeNode(mid->val);
			node->left = parse(start, mid);
			node->right = parse(mid->next, end);
			return node;
		};
		return parse(head, NULL);
	}
};