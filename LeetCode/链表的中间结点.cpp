/**
 * Definition for singly-linked list.
 */
#include <cstddef>

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		auto n = 0;
		auto cur = head;
		while (cur != nullptr) {
			++n;
			cur = cur->next;
		}
		auto k = 0;
		cur = head;
		while (k < n / 2) {
			++k;
			cur = cur->next;
		}
		return cur;
	}
};
