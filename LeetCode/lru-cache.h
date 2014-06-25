/*
*	https://oj.leetcode.com/problems/lru-cache/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct Item {
	int key, val;
};

class LRUCache{
public:
	list<Item> m_items;
	map<int, list<Item>::iterator> m_map;
	int m_capacity;

	LRUCache(int capacity) : m_capacity(capacity) {}

	int get(int key) {
		auto it = m_map.find(key);
		if (it == m_map.end())
			return -1;
		Item item = *it->second;
		m_items.erase(it->second);
		m_items.push_back(item);
		auto it2 = m_items.end();
		it->second = --it2;
		return item.val;
	}

	void set(int key, int value) {
		auto it = m_map.find(key);
		if (it == m_map.end()) {
			// insert
			Item item = {key, value};
			m_items.push_back(item);
			auto it2 = m_items.end();
			m_map[key] = --it2;
			if (m_items.size() > m_capacity) {
				m_map.erase(m_items.begin()->key);
				m_items.pop_front();
			}
		}
		else {
			Item item = *it->second;
			item.val = value;
			m_items.erase(it->second);
			m_items.push_back(item);
			auto it2 = m_items.end();
			it->second = --it2;
		}
	}
};