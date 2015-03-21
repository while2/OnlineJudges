/*
*	https://oj.leetcode.com/problems/binary-search-tree-iterator/
*/

#define LEETCODE
#include <cassert>
#include <functional>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
	BSTIterator(TreeNode *root) 
		:m_root(root)
	{
		m_current = getMin(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
	    return m_current != NULL;
	}

	/** @return the next smallest number */
	int next() {
	    int ret = m_current->val;
	    m_current = getNext();
		return ret;
	}

	TreeNode *getNext() {
	    if (m_current == NULL) return NULL;
		if (m_current->right != NULL)
			return getMin(m_current->right);

		vector<TreeNode*> path;
		vector<bool> direction;
		function<void(TreeNode*)> recursion;
		recursion = [&](TreeNode *node) {			
			if (m_current->val < node->val) {
				direction.push_back(false);
				path.push_back(node);
				recursion(node->left);
			}
			else if (m_current->val > node->val) {
				direction.push_back(true);
				path.push_back(node);
				recursion(node->right);
			}
		};
		recursion(m_root);
		while (!direction.empty() && direction.back()) {
			direction.pop_back();
			path.pop_back();
		}
		if (path.empty())
			return NULL;
		else
			return path.back();
	}

	TreeNode *getMin(TreeNode *node) {
		if (node == NULL) return NULL;
		while (node->left != NULL)
			node = node->left;
		return node;
	}
	TreeNode *m_root, *m_current;
};
/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/