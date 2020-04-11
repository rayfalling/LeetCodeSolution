#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(const pair<int, pair<int, int>> a, const pair<int, pair<int, int>> b) {
	return a.first < b.first;
}

void cal() {
	int M, L;
	cin >> M >> L;
	vector<vector<int>> map(M, vector<int>(M, 0));
	vector<pair<int, int>> exist;

	//load
	for (auto i = 0; i < M; i++) {
		for (auto j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0)
				exist.emplace_back(make_pair(i, j));
		}
	}

	int x, y;
	cin >> x >> y;

	//cal length
	vector<pair<int, pair<int, int>>> length;
	for (auto pair : exist) {
		auto len = pow(abs(pair.first - x), 2) + pow(abs(pair.second - y), 2);
		length.emplace_back(make_pair(len, pair));
	}
	sort(length.begin(), length.end(), cmp);

	auto current = L, cnt = 0;
	while (cnt < length.size()) {
		if (pow(current, 2) >= length[cnt].first) {
			current += map[length[cnt].second.first][length[cnt].second.second];
			cnt++;
		}
		else {
			break;
		}
	}
	cout << current << endl;
}

//ÍøÒ×»¥Óé±ÊÊÔ1
int main_ÍøÒ×»¥Óé±ÊÊÔ1() {
	int t;
	cin >> t;
	while (t--) {
		cal();
	}
	return 0;
}

