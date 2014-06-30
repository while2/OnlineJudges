/*
*	https://oj.leetcode.com/problems/word-ladder/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <functional>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
	struct Node {
		Node(const string &word) : word(word) {}
		string word;
		vector<Node*> neighbors;
	};
	vector<Node*> m_nodes;
    bool IsNeighbor(const string &str1, const string &str2) {
        int diff = 0;
        for (int i = 0; i < str1.size(); ++i) {
            if (str1[i] != str2[i])
                if (diff++ > 0)
                    return false;
        }
        return true;
    }
	void BuildGraph(const unordered_set<string> &dict) {
		for (auto word : dict)
			m_nodes.push_back(new Node(word));
		for (int i = 0; i < m_nodes.size(); ++i) {
			for (int j = i+1; j < m_nodes.size(); ++j) {
				if (IsNeighbor(m_nodes[i]->word, m_nodes[j]->word)) {
					m_nodes[i]->neighbors.push_back(m_nodes[j]);
					m_nodes[j]->neighbors.push_back(m_nodes[i]);
				}
			}
		}
	}
    int ladderLength(string start, string end, unordered_set<string> &dict) {
		dict.insert(start), dict.insert(end);
		BuildGraph(dict);
		queue<Node*> q;
		queue<int> q2;
		Node *dst = nullptr;
		for (auto node : m_nodes) {
			if (node->word == start)
				q.push(node);
			if (node->word == end)
				dst = node;
		}
		if (q.empty() || dst == nullptr)
			return 0;
		q2.push(0);
		unordered_set<Node*> visited;
		while (!q.empty()) {
			Node *node = q.front();
			q.pop();
			int depth = q2.front();
			q2.pop();

			if (node == dst)
				return depth+1;
			
			visited.insert(node);
			for (auto neighbor : node->neighbors)
				if (visited.find(neighbor) == visited.end()) {
					q.push(neighbor);
					q2.push(depth+1);
				}
		}
		return 0;
    }
};