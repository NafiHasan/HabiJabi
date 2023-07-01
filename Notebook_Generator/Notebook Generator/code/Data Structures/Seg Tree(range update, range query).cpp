ll tree[4 * N], lazy[4 * N];
inline ll merge(ll a, ll b) { return a + b; }
void push(int rt, int l, int r) {
	if (l ^ r) {
		lazy[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
	}
	tree[rt] += (r - l + 1) * lazy[rt];
	lazy[rt] = 0;
}
void update(int rt, int l, int r, int b, int e, ll v) {
	if (lazy[rt]) push(rt, l, r);
	if (l > e or r < b or b > e) return;
	if (l >= b and r <= e) {
		lazy[rt] += v;
		return push(rt, l, r);
	}
	int m = l + r >> 1, lc = rt << 1, rc = lc | 1;
	update(lc, l, m, b, e, v); update(rc, m + 1, r, b, e, v);
	tree[rt] = merge(tree[lc], tree[rc]);
}
ll query(int rt, int l, int r, int b, int e) {
	if (lazy[rt]) push(rt, l, r);
	if (l > e or r < b or b > e) return 0;
	if (l >= b and r <= e) return tree[rt];
	int m = l + r >> 1, lc = rt << 1, rc = lc | 1;
	return merge(query(lc, l, m, b, e), query(rc, m + 1, r, b, e));
}