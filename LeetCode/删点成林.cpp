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
	std::vector<TreeNode*> res;
public:
	//´¿±©Á¦ËÑË÷
	std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete) {
		res = std::vector<TreeNode*>();
		if (std::find(to_delete.begin(), to_delete.end(), root->val) == to_delete.end())
			res.push_back(root);
		dfs(root, to_delete, res);
		return res;
	}

	TreeNode* dfs(TreeNode* root, std::vector<int>& to_delete, std::vector<TreeNode*>& res) {
		if (!root)
			return root;
		const auto dl = dfs(root->left, to_delete, res);
		const auto dr = dfs(root->right, to_delete, res);
		if (std::find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()) {
			if (dl)
				res.push_back(dl);
			if (dr)
				res.push_back(dr);
			return nullptr;
		}
		root->left = dl;
		root->right = dr;
		return root;
	}
};
