/*
*	https://oj.leetcode.com/problems/multiply-strings/
*/

#define LEETCODE
#include <cassert>
#include <functional>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == nullptr || k == 1) return head;
		ListNode **p1 = &head;
		while (*p1) {
			auto p2 = *p1;
			for (int i = 1; i < k; ++i) {
				p2 = p2->next;
				if (p2 == nullptr)
					return head;
			}
			for (auto p = *p1; p != p2;) {
				auto next = p->next;
				p->next = p2->next;
				p2->next = p;
				p = next;
			}
			auto next = &(*p1)->next;
			*p1 = p2;
			p1 = next;
		}
		return head;
	}
};