/*
*	https://oj.leetcode.com/problems/word-ladder/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
	struct Node {
		Node(const string &word) : word(word) {}
		string word;
		vector<Node*> neighbors;
	};
	vector<Node*> m_graph;

	void BuildGraph(const unordered_set<string> &dict) {
		unordered_map<string, Node*> str_to_node(dict.size());
		for (auto word : dict) {
			auto node = new Node(word);
			str_to_node[word] = node;
			m_graph.push_back(node);
		}
		for (int i = 0; i < m_graph.size(); ++i) {
			auto &word = m_graph[i]->word;
			for (int j = 0; j < word.size(); ++j) {
				for (char c = 'a'; c <= 'z'; ++c) {
					if (word[j] == c) continue;
					string word2 = word;
					word2[j] = c;
					auto it = str_to_node.find(word2);
					if (it != str_to_node.end())
						m_graph[i]->neighbors.push_back(it->second);
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
		for (auto node : m_graph) {
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