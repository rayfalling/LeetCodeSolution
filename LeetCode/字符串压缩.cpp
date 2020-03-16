#include <string>
#include <sstream>

class Solution {
public:
	std::string compressString(std::string S) {
		const auto size = S.size();
		auto new_size = 0;
		std::ostringstream ostringstream;
		for (auto i = 0; i < size; i++) {
			auto cnt = 1;
			ostringstream << S[i];
			if (i < size - 1 && S[i] == S[i + 1]) {
				cnt++;
				i++;
				while (S[i] == S[i + 1]) {
					cnt++;
					i++;
				}
			}
			ostringstream << cnt;
		}
		return ostringstream.str().size() >= size ? S : ostringstream.str();
	}
};
