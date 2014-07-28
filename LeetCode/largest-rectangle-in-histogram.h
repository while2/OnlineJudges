/*
*	https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <memory>
#include <queue>
#include <list>
#include <cassert>
using namespace std;

template<typename T>
class SegmentTree
{
public:
	SegmentTree(T identity, function<T(T, T)> merge)
		:m_identity(identity), m_merge(merge)
	{
		assert(m_merge(identity, identity) == identity);
	}

	template<class Iter>
	void init(const Iter begin, const Iter end)
	{
		int size = 0;
		for (auto it = begin; it != end; ++it)
			size++;
		
		int leaves = 1;
		while (leaves < size)
			leaves *= 2;

		m_tree.resize(leaves * 2 - 1);
		
		size_t pos = leaves-1;
		for (auto it = begin; it != end; ++it)
			m_tree[pos++] = *it;
		while (pos < m_tree.size())
			m_tree[pos++] = m_identity;

		for (int i = leaves-2; i >= 0; --i)
			m_tree[i] = m_merge(m_tree[get_left_child(i)], m_tree[get_right_child(i)]);
	}

	T query(int start, int end)
	{
		return query(start, end, 0, 0, (m_tree.size() + 1) / 2);
	}
private:
	size_t get_left_child(size_t id) { return id * 2 + 1; }
	size_t get_right_child(size_t id) { return id * 2 + 2; }
	size_t get_parent(size_t id) { return (id - 1) / 2; }

	T query(size_t start, size_t end, size_t node_id, size_t node_start, size_t node_end)
	{
		if (start <= node_start && node_end <= end)
			return m_tree[node_id];
		if (end <= node_start || node_end <= start)
			return m_identity;
		int mid = (node_start + node_end) / 2;
		return m_merge(query(start, end, get_left_child(node_id), node_start, mid),
			query(start, end, get_right_child(node_id), mid, node_end));
	}

	T m_identity;
	vector<T> m_tree;
	function<T(T, T)> m_merge;
};


class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
		if (height.empty()) return 0;
		if (height.size() == 1) return height[0];

		vector<int> indices(height.size());
		for (size_t i = 0; i < indices.size(); ++i)
			indices[i] = i;
		SegmentTree<int> seg(-1, [&](int a, int b)->int
		{
			if (a == -1) return b;
			if (b == -1) return a;
			return height[a] < height[b] ? a : b;
		});
		seg.init(indices.begin(), indices.end());

		function<int(int, int)> parse;
		parse = [&](int start, int end)->int
		{
			if (start == end) return 0;
			int min_idx = seg.query(start, end);
			int area = height[min_idx] * (end - start);

			area = max(area, parse(start, min_idx));
			area = max(area, parse(min_idx+1, end));
			return area;
		};
		return parse(0, height.size());
    }
};