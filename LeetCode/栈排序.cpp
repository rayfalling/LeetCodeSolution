#include <stack>

class SortedStack {
private:
	std::stack<int> data;
	std::stack<int> temp;
public:
	SortedStack() {

	}

	void push(int val) {
		while (!data.empty() && val > data.top()) {
			temp.push(data.top());
			data.pop();
		}
		data.push(val);
		while (!temp.empty()) {
			data.push(temp.top());
			temp.pop();
		}
	}

	void pop() {
		if (!data.empty())
			data.pop();
	}

	int peek() {
		if (data.empty())return -1;
		return data.top();
	}

	bool isEmpty() {
		return data.empty();
	}
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
