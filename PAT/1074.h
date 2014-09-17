#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int val;
	Node *next;
};

Node buff[100000];

void Swap(Node **p1, Node **p2) {
	swap(*p1, *p2);
	swap((*p1)->next, (*p2)->next);
}

Node *Reverse(Node *head, int k) {
	auto p1 = &head;
	int c = 0;
	Node *new_head = 0;
	for (auto p2 = &head; *p2; ) {
		auto next = &(*p2)->next;
		if (c++ % k == 0) {
			p1 = p2;
			if (new_head == 0)
				new_head = *p1;
		}
		else
			Swap(p1, p2);
		p2 = next;
	}
	return new_head;
};

int main() {
	int p, n, k; scanf("%d %d %d", &p, &n, &k);
	auto head = buff+p;

	for (int i = 0; i < n; ++i) {
		int addr, val, next; scanf("%d %d %d", &addr, &val, &next);
		buff[addr].val = val;
		buff[addr].next = (next == -1) ? nullptr : buff+next;
	}

	head = Reverse(head, k);

	for (auto p = head; p; p = p->next) {
		if (p->next)
			printf("%05d %d %05d\n", p-buff, p->val, p->next - buff);
		else
			printf("%05d %d -1\n", p-buff, p->val);
	}
	return 0;
}