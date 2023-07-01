const int mx = 100005;
const int sz = 100005;
struct query {
	int l, r, id;
	bool operator<(const query &a) const {
		int x = l / sz; int y = a.l / sz;
		if (x != y) return x < y;
		if (x % 2) return r < a.r;
		return r > a.r;
	}
} ques[mx];
void add(int indx) { }
void baad(int indx) { }
void solve() {
	int l = 0;
	int r = -1;
	sort(ques + 1, ques + q + 1);
	for (int i = 1; i <= q; i++) {
		while (l > ques[i].l) add(--l);
		while (r < ques[i].r) add(++r);
		while (l < ques[i].l) baad(l++);
		while (r > ques[i].r) baad(r--);
		ans[ques[i].id] = sum[now];
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << " ";
}