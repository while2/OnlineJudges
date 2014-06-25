/*
*	https://oj.leetcode.com/problems/sort-list/
*/

#define LEETCODE
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	ListNode *merge(ListNode *p1, ListNode *p2) {
		if (p1 == NULL) return p2;
		if (p2 == NULL) return p1;
		ListNode *head;
		if (p1->val < p2->val) {
			head = p1; p1 = p1->next;
		}
		else {
			head = p2; p2 = p2->next;
		}
		ListNode *p = head;
		while (p1 != NULL && p2 != NULL) {
			if (p1->val < p2->val) {
				p->next = p1;
				p1 = p1->next;
			}
			else {
				p->next = p2;
				p2 = p2->next;
			}
			p = p->next;
		}
		if (p1 != NULL)
			p->next = p1;
		if (p2 != NULL)
			p->next = p2;
		return head;
	}

	ListNode *sortList(ListNode *head) {
		if (head == NULL || head->next == NULL) return head;

		ListNode **p1 = &head;
		ListNode *p2 = head;
		while (p2 != NULL && p2->next != NULL) {
			p1 = &(*p1)->next;
			p2 = p2->next->next;
		}
		auto part1 = sortList(*p1);
		*p1 = NULL;
		auto part2 = sortList(head);
		return merge(part1, part2);
	}
};