#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

struct node {
	int val;
	node *left , *right;
	node() {

	}
	node(int x) {
		val = x;
		left = right = NULL;
	}
};

struct bst {
	node *root;
	bst() {
		root = NULL;
	}

	node* insert(node *cur, int x) {
		if (!root) return new node(x);
		if (x > root->val) root->right = insert(root->right, x);
		else root->left = insert(root->left, x);
		return root;
	}

	node* search(node* root, int x) {
		if (root == NULL || root->val == x) return root;

		if (root->val < x) return search(root->right, x);

		return search(root->left, x);
	}
}

int main() {
	fast_io();

	return 0;
}