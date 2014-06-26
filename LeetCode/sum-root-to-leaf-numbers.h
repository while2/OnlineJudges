/*
*	https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <functional>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int sumNumbers(TreeNode *root) {
		function<int(TreeNode*, int)> parse;
		parse = [&](TreeNode *node, int pre)->int {
			if (node == nullptr) return 0;
			if (node->left == nullptr && node->right == nullptr)
				return pre * 10 + node->val;
			return (node->left ? parse(node->left, pre * 10 + node->val) : 0)
				+ (node->right ? parse(node->right, pre * 10 + node->val) : 0);
		};
		int ans = parse(root, 0);
		return ans;
	}
};