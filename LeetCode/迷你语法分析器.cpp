// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
#include <vector>

class NestedInteger {
public:
	// Constructor initializes an empty nested list.
	NestedInteger();

	// Constructor initializes a single integer.
	NestedInteger(int value);

	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Set this NestedInteger to hold a single integer.
	void setInteger(int value);

	// Set this NestedInteger to hold a nested list and adds a nested integer to it.
	void add(const NestedInteger& ni);

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const std::vector<NestedInteger>& getList() const;
};

#include <string>
#include <stack>


class Solution {
	std::stack<char> stack_;
	std::stack<NestedInteger*> ne_stack_;

	int get_integer() {
		auto num = 0;
		for (auto i = 1; !stack_.empty() && stack_.top() != '[' && stack_.top() != ','; i *= 10) {
			if (stack_.top() == '-') {
				num *= -1;
			}
			else {
				num += i * (stack_.top() - '0');
			}
			stack_.pop();
		}
		return num;
	}

public:
	NestedInteger deserialize(std::string s) {
		const auto nested_integer = new NestedInteger();
		auto cnt = 0;
		for (auto c : s) {
			if (c == ',' || c == ']') {
				if (!ne_stack_.empty() && cnt != 0) {
					ne_stack_.top()->add(NestedInteger(get_integer()));
					cnt = 0;
				}
				if (stack_.top() == '[' && c == ']') {
					stack_.pop();
					const auto res = ne_stack_.top();
					ne_stack_.pop();
					if (ne_stack_.empty()) {
						return *res;
					}
					ne_stack_.top()->add(*res);
				}
			}
			else {
				stack_.push(c);
				cnt++;
				if (c == '[') {
					cnt = 0;
					const auto current = new NestedInteger();
					ne_stack_.push(current);
				}
			}
		}
		if (!stack_.empty()) {
			return {get_integer()};
		}
		return *ne_stack_.top();
	}
};
