/*
*	https://oj.leetcode.com/problems/copy-list-with-random-pointer/
*/

#define LEETCODE
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

#include <unordered_map>
using namespace std;

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == nullptr) return nullptr;

		auto *head2 = new RandomListNode(head->label);

		unordered_map<RandomListNode*, RandomListNode*> map;
		map[head] = head2;

		for (auto p = head, p2 = head2; p != nullptr; p = p->next, p2 = p2->next) {
			if (p->next != nullptr) {
				auto &next2 = map[p->next];
				if (next2 == nullptr)
					next2 = new RandomListNode(p->next->label);
				p2->next = next2;
			}
			if (p->random != nullptr) {
				auto &random2 = map[p->random];
				if (random2 == nullptr)
					random2 = new RandomListNode(p->random->label);
				p2->random = random2;
			}
		}
		return head2;
	}
};