#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int n; cin >> n;
	vector<int> cnt(100005, 0);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
		mx = max(mx, cnt[x]);
	}
	mx = max(mx, (n + 1) / 2);
	cout << mx << '\n';
	return 0;
}