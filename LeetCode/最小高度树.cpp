#include <vector>
#include <queue>
#include <set>

class Solution {
public:
	/*
	 * ��Ϊ���ĸ߶���С������������м��۰�
	 * �����ڵ�Ϊ������м�ڵ㣬����Ϊһ����������
	 */
	std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
		//����nΪ1��ʱ��
		if (n == 1)return {0};
		//��������ͼ
		std::vector<std::set<int>> maps(n);
		//����������ͼ
		for (auto edge : edges) {
			maps[edge[0]].insert(edge[1]);
			maps[edge[1]].insert(edge[0]);
		}
		//��ǰ�����Ľڵ�
		std::queue<int> q;
		//ѭ��������Ҷ�ӽڵ�
		for (auto i = 0; i < n; i++) {
			//�ҵ����е�Ҷ�ӽڵ�
			if (maps[i].size() == 1)
				q.push(i);
		}

		//n > 2��ʱ��
		while (n > 2) {
			//ȡ������Ҷ�ӽڵ������
			const int size = q.size();
			//ʹnΪ���ڵ������
			n -= size;
			for (auto i = 0; i < size; i++) {
				//��ȡ��һ��Ҷ�ӽڵ�
				auto front = q.front();
				q.pop();
				//��Ҷ�ӽڵ㿪ʼ�������ڵ㣬��ȡ���
				for (auto item : maps[front]) {
					//ɾ���������Ľڵ�ı�����
					maps[item].erase(front);
					//���ɾ����ΪҶ�ӽڵ㣬��ӵ�Ҷ�ӽڵ������������
					if (maps[item].size() == 1) {
						q.push(item);
					}
				}
			}
		}

		std::vector<int> ans;
		//ʣ�µĽڵ����Ϊ������м�ڵ㣬��������ڵ�
		while (!q.empty()) {
			ans.push_back(q.front());
			q.pop();
		}
		return ans;
	}
};

int main_��С�߶���() {
	Solution s;
	std::vector<std::vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
	s.findMinHeightTrees(4, edges);
	return 0;
}
