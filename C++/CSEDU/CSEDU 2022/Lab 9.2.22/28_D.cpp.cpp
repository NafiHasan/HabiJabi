#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

class Node {
  public:
    int num;
    Node *left = NULL, *right = NULL;
    Node(int given) {
        num = given;
    }
};
set<Node*> se;
stack<Node*> st;

Node* maketree(int po[], int io[], int n) {
    Node* root = NULL;
    for (int pre = 0, in = 0; pre < n;) {
        Node* node = NULL;
        do {
            // cout << pre << ' ';
            node = new Node(po[pre]);
            if (root == NULL) root = node;
            if (st.size() > 0) {
                if (se.find(st.top()) != se.end()) {
                    se.erase(st.top());
                    st.top()->right = node;
                    st.pop();
                } else st.top()->left = node;
            }
            st.push(node);
            // pre++;
        } while (po[pre++] != io[in] && pre < n);

        node = NULL;
        while (st.size() > 0 && in < n && st.top()->num == io[in]) {
            node = st.top();
            st.pop();
            in++;
        }
        if (node != NULL) {
            se.insert(node);
            st.push(node);
        }
    }
    return root;
}
int cnt = 0;
void postorder(Node* node) {
    cnt++;
    if (cnt > 100)
        return ;
    if (node == NULL) {
        // cout << 'n';
        return;
    }
    postorder(node->left);
    // cout << cnt << ' ';
    postorder(node->right);
    cout << node->num << ' ';
}

int find_height(Node* node) {
    if (node == NULL) return 0;
    else {
        int lh = find_height(node->left);
        int rh = find_height(node->right);
        if (lh > rh) return (lh + 1);
        else return (rh + 1);
    }
}

void cur_level(Node* root, int lv) {
    if (root == NULL) return;
    if (lv == 1) cout << root->num << " ";
    else if (lv > 1) {
        cur_level(root->left, lv - 1);
        cur_level(root->right, lv - 1);
    }
}

void levelorder(Node* root) {
    int h = find_height(root);
    for (int i = 1; i <= h; i++)
        cur_level(root, i);
}

int main() {
    fast_io();
    int n;
    cin >> n;
    int preorder[n], inorder[n];
    for (int i = 0; i < n; i++)cin >> preorder[i];
    for (int i = 0; i < n; i++)cin >> inorder[i];
    Node *root = maketree(preorder, inorder, n);
    postorder(root);
    cout << '\n';
    levelorder(root);
    cout << '\n';
    return 0;
}