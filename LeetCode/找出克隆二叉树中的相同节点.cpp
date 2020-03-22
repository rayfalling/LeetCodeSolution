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
		auto p = getTargetCopy(original->left, cloned->left, target);    //����������
		auto q = getTargetCopy(original->right, cloned->right, target);  //����������
		return !p ? q : p;  //��Ȼ��p q��pΪ�շ���q����Ϊ��ֱ�ӷ���p
	}
};
