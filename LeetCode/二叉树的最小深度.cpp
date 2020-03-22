#include <algorithm>
#include <cstddef>

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        //左子树和右子树都为空的情况，说明到达了叶子节点，直接返回1即可
        if (root->left == nullptr && root->right == nullptr) return 1;
        //如果左子树或右子树其中一个为空，需要返回另一个的深度        
        const auto left = minDepth(root->left);
        const auto right = minDepth(root->right);
        return root->left == nullptr || root->right == nullptr ? left + right + 1 : std::min(left, right) + 1;
	}
};
