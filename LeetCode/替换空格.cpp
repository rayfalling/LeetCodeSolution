#include <string>
#include <sstream>

class Solution {
public:
	std::string replaceSpace(std::string s) {
		std::ostringstream mainstreaming;
		for(auto c : s) {
			if(c == ' ') {
				mainstreaming << "%20";
			}else {
				mainstreaming << c;
			}
		}
		return mainstreaming.str();
    }
};
