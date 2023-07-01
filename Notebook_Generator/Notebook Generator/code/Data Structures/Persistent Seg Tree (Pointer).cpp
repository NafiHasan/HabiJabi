struct node {
	ll sum;
	node *left, *right;
	node(ll _sum = 0) {
		sum = _sum;
		left = right = NULL;
	}
	void build(int l, int r) {
		if (l == r) return;
		left = new node();
		right = new node();
		int mid = (l + r) / 2;
		left->build(l, mid);
		right->build(mid + 1, r);
	}
	node *update(int l, int r, int i, int x) {
		if (l > i || r < i) return this;
		if (l == r) return new node(x);
		int mid = (l + r) / 2;
		node *ret = new node();
		ret->left = left->update(l, mid, i, x);
		ret->right = right->update(mid + 1, r, i, x);
		ret->sum = ret->left->sum + ret->right->sum;
		return ret;
	}
	ll query(int tL, int tR, int rL, int rR) {
		if (tL > rR || tR < rL) return 0;
		if (tL >= rL && tR <= rR) return sum;
		int mid = (tL + tR) / 2;
		ll a = left->query(tL, mid, rL, rR);
		ll b = right->query(mid + 1, tR, rL, rR);
		return a + b;
	}
	int size() { return sizeof(*this) / sizeof(node*); }
};
const int mx = 2e5 + 5;
node *root[mx];
void solve() {
	root[0] = new node();
	root[0]->build(1, n);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		root[0] = root[0]->update(1, n, i, x);
	}
	int sz = 0;
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int version, i, x;
			cin >> version >> i >> x;
			version--;
			root[version] = root[version]->update(1, n, i, x);
		}
		else if (op == 2) {
			int version, l, r;
			cin >> version >> l >> r;
			version--;
			cout << root[version]->query(1, n, l, r) << "\n";
		}
		else {
			int version;
			cin >> version;
			version--;
			root[++sz] = root[version];
		}
	}
}