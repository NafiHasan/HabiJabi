#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


// *
//  * Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (root -> left != NULL && root -> left -> val >= root -> val) return 0;
		if (root -> right != NULL && root -> right -> val <= root -> val) return 0;
		if (root -> left != NULL)isValidBST(root -> left);
		if (root -> right != NULL)isValidBST(root -> right);
	};


	int main() {
		FastIO;

		return 0;
	}