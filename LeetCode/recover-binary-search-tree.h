/*
*	https://oj.leetcode.com/problems/recover-binary-search-tree/
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
    void recoverTree(TreeNode *root) {
        vector<TreeNode*> outliers;
        TreeNode *last = NULL;
        function<void(TreeNode*)> parse;
        parse = [&](TreeNode *node) {
            if (node == NULL) return;
            parse(node->left);
            if (last != NULL && node->val < last->val) {
				outliers.push_back(last);
				outliers.push_back(node);
			}
			last = node;
            parse(node->right);
        };
        parse(root);
		swap(outliers[0]->val, outliers.back()->val);
    }
};