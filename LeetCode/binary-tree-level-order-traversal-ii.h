/*
*	https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int>> result;
		function<void(TreeNode *node, int depth)> parse;
		parse = [&](TreeNode *node, int depth) {
			if (node == NULL) return;
			if (result.size() < depth + 1)
				result.resize(depth+1);
			result[depth].push_back(node->val);
			parse(node->left, depth+1);
			parse(node->right, depth+1);
		};
		parse(root, 0);
		for (int i = 0, j = result.size()-1; i < j; i++, j--)
			swap(result[i], result[j]);
		return result;
	}
};