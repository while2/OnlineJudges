/*
*	https://oj.leetcode.com/problems/reorder-list/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	ListNode *reverseList(ListNode *head) {
		//if (head == NULL || head->next == NULL) return head;
		ListNode *current = NULL;
		for (auto p = head; p != NULL;) {
			auto next = p->next;
			p->next = current;
			current = p;
			p = next;
		}
		return current;
	}
	ListNode *mergeList(ListNode *head1, ListNode *head2) {
		auto p1 = head1, p2 = head2;
		while (p1 != NULL && p2 != NULL) {
			auto next1 = p1->next, next2 = p2->next;
			p1->next = p2;
			if (p2 == NULL) break;
			p2->next = next1;
			p1 = next1;
			p2 = next2;
		}
		return head1;
	}
	void reorderList(ListNode *head) {
		if (head == NULL || head->next == NULL) return;
		auto mid = head;
		for (auto p = head; p != NULL && p->next != NULL; p = p->next->next)
			mid = mid->next;
		auto last = mid->next;
		mid->next = NULL;

		last = reverseList(last);
		mergeList(head, last);
	}
};