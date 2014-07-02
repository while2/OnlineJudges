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
	vector<string> m_nodes;
	vector<vector<int>> m_arcs;

	void BuildGraph(const unordered_set<string> &dict) {
		unordered_map<string, int> str_to_id(dict.size());
		for (auto word : dict) {
			str_to_id[word] = m_nodes.size();
			m_nodes.push_back(word);
		}
		m_arcs.resize(m_nodes.size());
		for (int i = 0; i < m_nodes.size(); ++i) {
			auto &word = m_nodes[i];
			for (int j = 0; j < word.size(); ++j) {
				for (char c = 'a'; c <= 'z'; ++c) {
					if (word[j] == c) continue;
					string word2 = word;
					word2[j] = c;
					auto it = str_to_id.find(word2);
					if (it != str_to_id.end())
						m_arcs[i].push_back(it->second);
				}
			}
		}
	}

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		dict.insert(start), dict.insert(end);
		BuildGraph(dict);
		
		queue<int> q;
		int dst = -1;
		for (int i = 0; i < m_nodes.size(); ++i) {
			if (m_nodes[i] == start)
				q.push(i);
			if (m_nodes[i] == end)
				dst = i;
		}
		
		vector<vector<int>> prev(m_nodes.size());
		vector<int> depth(m_nodes.size(), -1);
		depth[q.front()] = 0;
		while (!q.empty()) {
			int id = q.front(); q.pop();
			for (auto id2 : m_arcs[id]) {
				if (depth[id2] == depth[id] + 1)
					prev[id2].push_back(id);
				else if (depth[id2] == -1) {
					depth[id2] = depth[id]+1;
					prev[id2].push_back(id);
					q.push(id2);
				}
			}
		}

		if (prev[dst].empty())
			return vector<vector<string>>();

		function<vector<vector<string>>(int)> parse;
		parse = [&](int id)->vector<vector<string>> {
			if (prev[id].empty())
				return vector<vector<string>>(1, vector<string>(1, m_nodes[id]));
			vector<vector<string>> chains;
			for (auto id2 : prev[id]) {
				for (auto chain: parse(id2)) {
					chain.push_back(m_nodes[id]);
					chains.push_back(chain);
				}
			}
			return chains;
		};
		return parse(dst);
    }
};