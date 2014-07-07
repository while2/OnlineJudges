/*
*	https://oj.leetcode.com/problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode *root) {
        bool ok = true;
        function<int(TreeNode *node)> parse;
        parse = [&](TreeNode *node)-> int {
            if (!ok) return 0;
            if (node == NULL)
                return 0;
                
            int left_depth = parse(node->left);
            int right_depth = parse(node->right);
            if (abs(left_depth - right_depth) > 1)
                ok = false;
            return max(left_depth, right_depth) + 1;
        };
        parse(root);
        return ok;
    }
};