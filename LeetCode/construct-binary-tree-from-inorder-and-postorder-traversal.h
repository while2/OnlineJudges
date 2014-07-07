/*
*	https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		int post_pos = postorder.size() - 1;
		function<TreeNode*(int, int)> parse;
		parse = [&](int start, int end)->TreeNode* {
			if (start == end) return NULL;
			TreeNode* node = new TreeNode(postorder[post_pos]);
			int in_pos;
			for (in_pos = start; in_pos < end; ++in_pos)
				if (inorder[in_pos] == node->val)
					break;

			--post_pos;
			node->right = parse(in_pos+1, end);
			node->left = parse(start, in_pos);
			return node;
		};
		return parse(0, inorder.size());
	}
};