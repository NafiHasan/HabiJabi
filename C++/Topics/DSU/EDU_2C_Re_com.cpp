#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 2e5 + 10;
vector<int> par(N), rnk(N, 0);

void makeset() {
	for (int i = 1; i < N; i++)par[i] = i;
}

int get(int a) {
	// path compressed, change if needed
	return (par[a] == a ? a : (par[a] = get(par[a])));
}

void union_set(int a, int b) {
	a = get(a);  // find the topmost parent
	b = get(b);

	if (a == b)return; // are in same set

	if (rnk[a] == rnk[b])rnk[a]++;

	if (rnk[a] > rnk[b])par[b] = a;
	else par[a] = b;
}

int main() {
	FastIO;
	int n, q;
	cin >> n >> q;
	makeset();
	set<int> st;
	for (int i = 1; i <= n; i++)st.insert(i);
	while (q--) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1) {
			union_set(l, r);
		} else if (t == 2) {
			auto it1 = st.lower_bound(l);
			if (it1 != st.end()) {
				for (auto it = it1; it != st.end(); it++) {
					if ((*it) >= r)break;
					union_set((*it), r);
				}
				auto it = it1;
				while ((*it) < r) {
					st.erase(it);
					it = st.lower_bound(l);
				}
			}
		} else {
			if (get(l) == get(r)) {
				cout << "YES\n";
			} else cout << "NO\n";
		}
	}
	return 0;
}