#include <vector>
#include <unordered_map>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == nullptr) return nullptr;

		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
		UndirectedGraphNode *node2 = new UndirectedGraphNode(node->label);
		map[node] = node2;
		vector<UndirectedGraphNode*> st(1, node);
		
		while (!st.empty()) {
			auto &node = st.back(); st.pop_back();
			auto &node2 = map[node];
			if (node2 == nullptr)
				node2 = new UndirectedGraphNode(node->label);
			for (auto neighbor : node->neighbors) {
				auto &neighbor2 = map[neighbor];
				if (neighbor2 == nullptr) {
					neighbor2 = new UndirectedGraphNode(neighbor->label);
					st.push_back(neighbor);
				}
				node2->neighbors.push_back(neighbor2);
			}
		}
		return node2;
	}
};