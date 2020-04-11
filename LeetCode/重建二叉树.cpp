/**
 * Definition for a binary tree node.
 * */
#include <vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
	}
};

class Solution {
public:
	TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
		return build(preorder, inorder, 0, 0, inorder.size() - 1);
	}

	TreeNode* build(std::vector<int>& preorder, std::vector<int>& inorder, const int root, const int start,
	                const int end) {
		if (start > end)return nullptr;
		const auto current = new TreeNode(preorder[root]);
		auto i = start;
		while (i < end && preorder[root] != inorder[i])i++;
		current->left = build(preorder, inorder, root + 1, start, i - 1);
		current->right = build(preorder, inorder, root + 1 + i - start, i + 1, end);
		return current;
	}

};

int main_ÖØ½¨¶þ²æÊ÷() {
	std::vector<int> preorder = {1, 2, 4, 6, 7, 8, 3, 5};
	std::vector<int> inorder = {4, 7, 6, 8, 2, 1, 3, 5};
	Solution().buildTree(preorder, inorder);
	return 0;
}
