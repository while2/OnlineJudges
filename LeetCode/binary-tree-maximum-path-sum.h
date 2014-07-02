/*
*	https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxPathSum(TreeNode *root) {
		function<void(TreeNode*, int&, int &)> parse;
		parse = [&](TreeNode* node, int &sum1, int &sum2) {
			// sum1 : a sum end with node
			// sum2 : any kind of sum 
			
			if (node->left == NULL && node->right == NULL) {
				sum1 = sum2 = node->val;
				return;
			}

			if (node->left != NULL && node->right == NULL) {
				parse(node->left, sum1, sum2);
				sum2 = max(sum2, sum1);
				sum2 = max(sum2, sum1 + node->val);
				sum2 = max(sum2, node->val);
				sum1 = max(node->val, sum1 + node->val);
				return;
			}
			
			if (node->left == NULL && node->right != NULL) {
				parse(node->right, sum1, sum2);
				sum2 = max(sum2, sum1);
				sum2 = max(sum2, sum1 + node->val);
				sum2 = max(sum2, node->val);
				sum1 = max(node->val, sum1 + node->val);
				return;
			}

			int suml1 = 0, suml2 = 0, sumr1 = 0, sumr2 = 0;
			parse(node->left, suml1, suml2);
			parse(node->right, sumr1, sumr2);
			
			sum2 = max(suml2, sumr2);
			sum2 = max(sum2, suml1 + sumr1 + node->val);
			sum2 = max(sum2, node->val);
			sum1 = max(suml1, sumr1) + node->val;
			sum1 = max(sum1, node->val);
		};
		int sum1, sum2;
		parse(root, sum1, sum2);
		return max(sum1, sum2);
	}
};