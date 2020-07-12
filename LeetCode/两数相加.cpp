/**
 * Definition for singly-linked list.
 */
#include <cmath>

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(nullptr) {
	}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		auto* node = new ListNode(-1);
		auto* head = node;
		auto carry = 0;
		while (l1 != nullptr || l2 != nullptr) {
			const auto x = l1 == nullptr ? 0 : l1->val;
			const auto y = l2 == nullptr ? 0 : l2->val;

			const auto sum = x + y + carry;
			carry = sum / 10;
			auto* next = new ListNode(sum % 10);
			node->next = next;
			node = node->next;
			l1 = l1 == nullptr ? nullptr : l1->next;
			l2 = l2 == nullptr ? nullptr : l2->next;
		}
		if(carry >0) {
			auto* next = new ListNode(carry);
			node->next = next;
		}
		return head->next;
	}
	// overflow
	// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	// 	long long a = 0, b = 0;
	// 	auto index = 0;
	// 	while (l1->next != nullptr) {
	// 		long long plus = 10;
	// 		for (auto i = 0; i < index; i++)plus *= 10;
	// 		plus *= l1->val;
	// 		a += plus;
	// 		index++;
	// 		l1 = l1->next;
	// 	}
	// 	index = 0;
	// 	while (l2->next != nullptr) {
	// 		long long plus = 10;
	// 		for (auto i = 0; i < index; i++)plus *= 10;
	// 		plus *= l2->val;
	// 		b += plus;
	// 		index++;
	// 		l1 = l2->next;
	// 	}
	// 	auto ans = a + b;
	//
	// 	auto* res = new ListNode(static_cast<int>(ans % 10));
	// 	ans /= 10;
	// 	while (ans != 0) {
	// 		const auto t = static_cast<int>(ans % 10);
	// 		auto* const temp_node = new ListNode(t);
	// 		temp_node->next = res;
	// 		res = temp_node;
	// 		ans /= 10;
	// 	}
	// 	return res;
	// }
};
