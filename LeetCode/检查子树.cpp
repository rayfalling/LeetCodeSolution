/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
	}
};

class Solution {
public:
	bool checkSubTree(TreeNode* t1, TreeNode* t2) {
		if (t1 == t2) return true;
		if (!t1) return false;
		if (t1->val == t2->val) {
			if (checkSubTree(t1->left, t2->left) && checkSubTree(t1->right, t2->right)) return true;
		}
		return checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
	}
};
