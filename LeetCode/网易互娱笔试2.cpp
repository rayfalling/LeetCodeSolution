#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void run_ÍøÒ×»¥Óé±ÊÊÔ2() {
	int N, M;
	vector<unordered_set<int>> set_map(10001, unordered_set<int>());
	cin >> N >> M;
	for (auto i = 1; i <= N; i++) {
		set_map[i].insert(i);
	}
	while (M--) {
		auto op = 0;
		cin >> op;
		if (op == 1) {
			int x, y;
			cin >> x >> y;
			if (set_map[x].find(y) != set_map[x].end() && set_map[y].find(x) != set_map[y].end()) {
				continue;
			}
			for (auto num : set_map[x]) {
				if (num == x)continue;
				set_map[num].insert(set_map[y].begin(), set_map[y].end());
			}
			for (auto num : set_map[y]) {
				if (num == y)continue;
				set_map[num].insert(set_map[x].begin(), set_map[x].end());
			}
			set_map[y].insert(set_map[x].begin(), set_map[x].end());
			set_map[x].insert(set_map[y].begin(), set_map[y].end());
		}
		else if (op == 2) {
			int x;
			cin >> x;
			if (set_map[x].size() > 1) {
				for (auto num : set_map[x]) {
					if (num == x)continue;
					set_map[num].erase(x);
				}
				set_map[x].clear();
				set_map[x].insert(x);
			}
		}
		else if (op == 3) {
			int x;
			cin >> x;
			cout << set_map[x].size() << endl;
		}
	}
}

//ÍøÒ×»¥Óé±ÊÊÔ2
int main_ÍøÒ×»¥Óé±ÊÊÔ2() {
	int t;
	cin >> t;
	while (t--) {
		run_ÍøÒ×»¥Óé±ÊÊÔ2();
	}
	return 0;
}
