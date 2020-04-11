#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(const pair<int, int> a, const pair<int, int> b) {
	return a.first > b.first;
}

void run() {
	int n;
	cin >> n;
	vector<int> array;
	vector<int> visit(n, 0);
	vector<pair<int, int>> weight;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		array.emplace_back(temp);
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		weight.emplace_back(make_pair(temp, i));
	}

	sort(weight.begin(), weight.end(), cmp);
	int res = 0;
	for (int i = 0; i < weight.size(); i++) {
		int index = weight[i].second + 1;
		while (visit[index]) { index++; if (index = weight.size())index = 0; }
		res += abs(index - weight[i].second) * weight[i].first;
		visit[index] = 1;
	}
	cout << res << endl;
}

//网易互娱笔试3，没做出来
int main() {
	int t;
	std::cin >> t;
	while (t--) {
		run();
	}
	return 0;
}
