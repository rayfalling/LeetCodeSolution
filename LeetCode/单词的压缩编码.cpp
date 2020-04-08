#include <string>
#include <unordered_map>
#include <vector>

class TrieNode {
    TrieNode* children_[26];
public:
    int count;
    TrieNode() {
        for (auto& i : children_)
            i = nullptr;
        count = 0;
    }
    TrieNode* get(const char c) {
        if (children_[c - 'a'] == nullptr) {
            children_[c - 'a'] = new TrieNode();
            count++;
        }
        return children_[c - 'a'];
    }
};
class Solution {
public:
    int minimumLengthEncoding(std::vector<std::string>& words) {
	    const auto trie = new TrieNode();
        std::unordered_map<TrieNode*, int> nodes;

        for (auto i = 0; i < static_cast<int>(words.size()); ++i) {
	        auto word = words[i];
	        auto cur = trie;
            for (int j = word.length() - 1; j >= 0; --j)
                cur = cur->get(word[j]);
            nodes[cur] = i;
        }

	    auto ans = 0;
        for (auto& [node, idx] : nodes) {
            if (node->count == 0) {
                ans += words[idx].length() + 1;
            }
        }
        return ans;
    }
};
