#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//Don't forget to clear the global variables
// make sure to set the maximum size according to the problem

const int N = 1e5 + 10;
map<int, int> ind;
vector<int> par(N), rnk(N, 0), sen(N, 0), chld(N, 0);

void makeset() {
	for (int i = 1; i < N; i++)par[i] = i;
	for (int i = 1; i < N; i++)chld[i] = i;
}

int mx = 0, ans = 0;

int get(int a) {
	// path compressed, change if needed
	if (par[a] == a)return a;
	else {
		chld[par[a]] = a;
		return par[a] = get(par[a]);
	}
	// return (par[a] == a ? a : (par[a] = get(par[a])));
}

void getchild(int a) {
	if (sen[a] > mx) {
		mx = sen[a];
		ans = a;
	} else if (sen[a] == mx) {
		ans = max(ans, a);
	}
	if (chld[a] == a)return;
	getchild(chld[a]);
}


void union_set(int a, int b) {
	a = get(a);
	b = get(b);

	if (a == b)return; // are in same set

	if (rnk[a] == rnk[b])rnk[a]++;

	if (rnk[a] > rnk[b]) {
		par[b] = a;
		chld[a] = b;
		// sen[a] = max(sen[a], sen[b]);
		// sen[b] = max(sen[a], sen[b]);
	} else {
		par[a] = b;
		chld[b] = a;
		// sen[a] = max(sen[a], sen[b]);
		// sen[b] = max(sen[a], sen[b]);
	}
}

int main() {
	FastIO;
	makeset();
	int n, q; cin >> n >> q;
	for (int i = 0, j = n; i < n; i++, j--) {
		int x;
		cin >> x;
		ind[x] = i;
		sen[x] = j;
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, b;
			cin >> a >> b;
			union_set(a, b);
		} else if (t == 2) {
			int x;
			cin >> x;
			sen[x]++;
		} else {
			int y;
			cin >> y;
			mx = 0;
			ans = 0;
			y = get(y);
			getchild(y);
			cout << ans << '\n';
		}
	}
	return 0;
}