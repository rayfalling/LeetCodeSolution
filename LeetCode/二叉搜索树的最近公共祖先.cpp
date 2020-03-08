/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//注意二叉搜索树的性质
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) {
			return nullptr;
		}

		if (root->val > p->val&& root->val > q->val) {
			return lowestCommonAncestor(root->left, p, q);
		}

		if (root->val < p->val&& root->val < q->val) {
			return lowestCommonAncestor(root->right, p, q);
		}

		return root;
	}
};