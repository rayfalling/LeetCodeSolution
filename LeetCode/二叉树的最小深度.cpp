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
        //����������������Ϊ�յ������˵��������Ҷ�ӽڵ㣬ֱ�ӷ���1����
        if (root->left == nullptr && root->right == nullptr) return 1;
        //���������������������һ��Ϊ�գ���Ҫ������һ�������        
        const auto left = minDepth(root->left);
        const auto right = minDepth(root->right);
        return root->left == nullptr || root->right == nullptr ? left + right + 1 : std::min(left, right) + 1;
	}
};
