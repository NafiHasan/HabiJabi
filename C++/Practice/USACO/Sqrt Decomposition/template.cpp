#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int N = 200005;
int B;
vector<int> ans(N, 0);
struct Query {
	int l, r, ind;

	const bool operator<(const Query& other) {
		if (l / B == other.l / B) {
			if ((l / B) % 2 == 0)
				return r < other.r;
			else
				return r > other.r;
		} else
			return l < other.l;
	}
};

int main() {
	FastIO;
	int n; cin >> n;
	B = (int)ceil(sqrt(n));
	vector<int> a(n + 1), freq(1000005, 0);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int q; cin >> q;
	Query queries[q];
	for (int i = 0; i < q; i++) {
		cin >> queries[i].l >> queries[i].r;
		queries[i].ind = i;
	}
	sort(queries, queries + q);
	int cnt = 1, i = 1, j = 1;
	freq[a[i]]++;
	for (int x = 0; x < q; x++) {
		while (i < queries[x].l) {
			freq[a[i]]--;
			if (freq[a[i]] == 0)cnt--;
			i++;
		}
		while (i > queries[x].l) {
			i--;
			freq[a[i]]++;
			if (freq[a[i]] == 1)cnt++;
		}
		while (j > queries[x].r) {
			freq[a[j]]--;
			if (freq[a[j]] == 0)cnt--;
			j--;
		}
		while (j < queries[x].r) {
			j++;
			freq[a[j]]++;
			if (freq[a[j]] == 1)cnt++;
		}
		ans[queries[x].ind] = cnt;
	}
	for (int i = 0; i < q; i++)cout << ans[i] << '\n';
	return 0;
}