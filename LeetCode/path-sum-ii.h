/*
*	https://oj.leetcode.com/problems/distinct-subsequences/
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
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int>> paths;
		if (root == NULL) return paths;

		function<void(TreeNode*, int, vector<int>&)> parse;
		parse = [&](TreeNode *node, int sum, vector<int> &path) {
			path.push_back(node->val);
			
			if (node->left == NULL && node->right == NULL && node->val == sum) {
				paths.push_back(path);
			}
			
			if (node->left != NULL) {
				parse(node->left, sum - node->val, path);
			}
			if (node->right != NULL) {
				parse(node->right, sum - node->val, path);
			}
			path.pop_back();
		};

		vector<int> path;
		parse(root, sum, path);
		return paths;
	}
};