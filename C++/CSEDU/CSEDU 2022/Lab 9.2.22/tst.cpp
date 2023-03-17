// C++ program to construct a tree using
// inorder and preorder traversal
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    // public:
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) { val = x; }
};

// Node* newNode(int data) {
//     Node* temp = new Node;
//     temp->data = data;
//     temp->left = temp->right = NULL;
//     return temp;
// }

set<TreeNode*> s;
stack<TreeNode*> st;

// Function to build tree using given traversal
TreeNode* buildTree(int preorder[], int inorder[], int n) {

    TreeNode* root = NULL;
    for (int pre = 0, in = 0; pre < n;) {

        TreeNode* node = NULL;
        do {
            cout << pre << ' ';
            node = new TreeNode(preorder[pre]);
            if (root == NULL) {
                root = node;
            }
            if (st.size() > 0) {
                if (s.find(st.top()) != s.end()) {
                    s.erase(st.top());
                    st.top()->right = node;
                    st.pop();
                } else {
                    st.top()->left = node;
                }
            }
            st.push(node);
        } while (preorder[pre++] != inorder[in] && pre < n);

        node = NULL;
        while (st.size() > 0 && in < n &&
                st.top()->val == inorder[in]) {
            node = st.top();
            st.pop();
            in++;
        }

        if (node != NULL) {
            s.insert(node);
            st.push(node);
        }
    }

    return root;
}

// Function to print tree in Inorder
// void printInorder(TreeNode* node) {
//     if (node == NULL)
//         return;

//     /* first recur on left child */
//     printInorder(node->left);

//     /* then print the data of node */
//     cout << node->val << " ";

//     /* now recur on right child */
//     printInorder(node->right);
// }

// Driver code
int main() {
    int in[] = { 9, 8, 4, 2, 10, 5, 10, 1, 6, 3, 13, 12, 7 };
    int pre[] = { 1, 2, 4, 8, 9, 5, 10, 10, 3, 6, 7, 12, 13 };
    int len = sizeof(in) / sizeof(int);

    TreeNode *root = buildTree(pre, in, len);
    cout << root->val;
    // printInorder(root);
    return 0;
}
