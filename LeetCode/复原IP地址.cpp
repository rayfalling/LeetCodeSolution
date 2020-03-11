#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>

class Solution {
public:
	std::vector<std::string> restoreIpAddresses(std::string s) {
		std::vector<std::string> answers;
		search(answers, s, 1, 0, "");
		return answers;
	}

	//回溯算法 + 剪枝处理
	static void search(std::vector<std::string>& ans, std::string ip, int depth, int current_index, std::string res) {
		if (current_index > ip.length()) return;
		for (auto end = current_index; end < ip.length() && end <= current_index + 2; end++) {
			//剪枝，删去不符合规范的搜索结果
			if (ip.length() - (end + 1) > (4 - depth) * 3) continue;
			if (ip.length() - (end + 1) < 4 - depth) continue;
			auto current_segment = ip.substr(current_index, end - current_index + 1);
			if (is_valid(current_segment)) {
				if (depth == 4) {
					ans.push_back(res + current_segment);
					return;
				}
				search(ans, ip, depth + 1, end + 1, res + current_segment + ".");
			}

		}
	}

	static bool is_valid(const std::string& ip_seg) {
		int temp;
		std::stringstream ss;
		ss << ip_seg;
		ss >> temp;
		if (std::to_string(temp).size() < ip_seg.size()) return false;
		if (temp < 0 || temp > 255)return false;
		return true;
	}
};


// int main() {
// 	Solution s;
// 	s.restoreIpAddresses("25525511135");
// }