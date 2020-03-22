/**
 * Definition for a binary tree node.
 *  */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
	}
};

#include <algorithm>

class Solution {
public:
	TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
		if (!original)return original;
		if (original == target) {
			return cloned;
		}
		auto p = getTargetCopy(original->left, cloned->left, target);    //查找左子树
		auto q = getTargetCopy(original->right, cloned->right, target);  //查找右子树
		return !p ? q : p;  //必然在p q中p为空返回q，不为空直接返回p
	}
};
