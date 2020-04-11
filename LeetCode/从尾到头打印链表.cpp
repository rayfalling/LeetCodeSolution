/**
 * Definition for singly-linked list.
 * */

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(nullptr) {
	}
};

#include <vector>
#include <stack>

class Solution {
public:
	std::vector<int> reversePrint(ListNode* head) {
		if (head == nullptr)return std::vector<int>();
		std::stack<int> stack;
		while (head->next != nullptr) {
			stack.emplace(head->val);
			head = head->next;
		}
		stack.emplace(head->val);
		std::vector<int> result;
		while (!stack.empty()) {
			result.emplace_back(stack.top());
			stack.pop();
		}
		return result;
	}
};
