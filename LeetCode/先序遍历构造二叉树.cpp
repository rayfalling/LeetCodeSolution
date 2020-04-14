/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
	}
};

#include <vector>

class Solution {
public:
	TreeNode* bstFromPreorder(std::vector<int>& preorder) {
		return bstFromPreorder(preorder, 0, preorder.size() - 1);
	}

	TreeNode* bstFromPreorder(std::vector<int>& preorder, int left, int right) {
		if (left > right) return nullptr;
		int i;
		for (i = left + 1; i <= right; ++i) {
			if (preorder[i] > preorder[left]) {
				break;
			}
		}
		const auto node = new TreeNode(preorder[left]);
		node->left = bstFromPreorder(preorder, left + 1, i - 1);
		node->right = bstFromPreorder(preorder, i, right);
		return node;
	}
};
