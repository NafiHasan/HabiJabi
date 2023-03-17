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

	node* insert(node *root, int x) {
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
	node* min_val(node* node) {
		struct node* cur = node;
		while (cur && cur->left != NULL) cur = cur->left;

		return cur;
	}
	node* del(node* root, int x) {
		if (root == NULL) return root;

		if (x < root->val) root->left = del(root->left, x);
		else if (x > root->val) root->right = del(root->right, x);
		else {
			if (root->left == NULL and root->right == NULL) return NULL;
			else if (root->left == NULL) {
				node* tmp = root->right;
				free(root);
				return tmp;
			} else if (root->right == NULL) {
				node* tmp = root->left;
				free(root);
				return tmp;
			}
			node* tmp = min_val(root->right);
			root->val = tmp->val;

			// Delete the inorder successor
			root->right = del(root->right, tmp->val);
		}
		return root;
	}
};


int main() {
	fast_io();
	int n, q;
	cin >> n >> q;
	bst *root = NULL;
	bst a;
	// map<long long, long long> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		root = a.insert(root, x);
	}
	while (q--) {
		char c;
		long long val;
		cin >> c >> val;
		if (c == 'D') {
			m[val]--;
			m[val] = max(0LL, m[val]);
		} else if (c == 'I')m[val]++;
		else {
			long long lo = val + 1, hi = 1e18, mid, ans = -1;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if ()
				}
			if (m[val] > 0)cout << "Yes\n";
			else cout << "No\n";
		}
	}

	return 0;
}