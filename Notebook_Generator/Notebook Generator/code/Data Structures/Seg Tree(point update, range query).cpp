ll tree[4 * N];
inline ll merge(ll a, ll b) { return a + b; }
void update(int rt, int l, int r, int p, ll v) {
	if (l == r) return void(tree[rt] = v);
	int m = l + r >> 1, lc = rt << 1, rc = lc | 1;
	if (p <= m) update(lc, l, m, p, v);
	else update(rc, m + 1, r, p, v);
	tree[rt] = merge(tree[lc], tree[rc]);
}
ll query(int rt, int l, int r, int b, int e) {
	if (l > e or r < b or b > e) return 0;
	if (l >= b and r <= e) return tree[rt];
	int m = l + r >> 1, lc = rt << 1, rc = lc | 1;
	return merge(query(lc, l, m, b, e), query(rc, m + 1, r, b, e));
}