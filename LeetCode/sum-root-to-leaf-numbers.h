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
		if (root == nullptr) return 0;
		int sum = 0;
		vector<TreeNode*> st(1, root);
		vector<int> st2(1, 0);
		while (!st.empty()) {
			auto node = st.back(); st.pop_back();
			int pre = st2.back(); st2.pop_back();
			if (node->left == nullptr && node->right == nullptr)
				sum += pre * 10 + node->val;
			else {
				if (node->left != nullptr) {
					st.push_back(node->left);
					st2.push_back(pre * 10 + node->val);
				}
				
				if (node->right != nullptr) {
					st.push_back(node->right);
					st2.push_back(pre * 10 + node->val);
				}
			}
		}
		return sum;
	}
};