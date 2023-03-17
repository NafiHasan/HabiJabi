#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 1000005;
vector<int> edge[N];
vector<bool> vis(N, 0);
string s;
long long base1 = 29;
long long base2 = 31;
long long  mod1 = 1e9 + 7;
long long mod2 = 1e9 + 11;
long long powerofbase1[1000000 + 5];
long long powerofbase2[1000000 + 5];
int cnt = 0;
void dfs(int u, long long f_hash1, long long r_hash1, long long f_hash2, long long r_hash2, int szz) {
	vis[u] = 1;
	f_hash1 *= base1;
	f_hash1 %= mod1;
	f_hash1 += ((int)s[u - 1] - 64);
	f_hash1 %= mod1;


	f_hash2 *= base2;
	f_hash2 %= mod2;
	f_hash2 += ((int)s[u - 1] - 64);
	f_hash2 %= mod2;
	// cout << r_hash1 << " " << r_hash2 << endl;
	long long xx = (int)s[u - 1] - 64;
	xx *= powerofbase1[szz];
	xx %= mod1;
	long long yy = ((int)s[u - 1] - 64) * powerofbase2[szz];
	yy %= mod2;

	r_hash1 += xx;
	r_hash1 %= mod1;

	r_hash2 += yy;
	r_hash2 %= mod2;
	// cout << xx << " " << yy << " " << r_hash1 << " " << r_hash2 << " for " << u << endl;
	if (f_hash1 == r_hash1 && f_hash2 == r_hash2) {
		cnt++;
		// cout << "milse" << " " << u << endl;
	}
	for (int i : edge[u]) {
		if (!vis[i]) {
			dfs(i, f_hash1, r_hash1, f_hash2, r_hash2, szz + 1);
		}
	}
}

int main() {
	FastIO;
	int tc, cs = 1;
	cin >> tc;
	powerofbase1[0] = 1LL;
	powerofbase2[0] = 1LL;
	for (int i = 1; i < 1000000 + 5; i++) {
		powerofbase1[i] = powerofbase1[i - 1] * base1;
		powerofbase1[i] %= mod1;
		powerofbase2[i] = powerofbase2[i - 1] * base2;
		powerofbase2[i] %= mod2;
	}
	while (tc--) {
		cout << "Case " << cs++ << ": ";
		cnt = 0;
		int n;
		cin >> n;
		cin >> s;
		for (int i = 0; i <= n; i++) {
			vis[i] = 0;
			edge[i].clear();
		}
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		dfs(1, 0, 0, 0, 0, 0);
		long long g = __gcd(cnt, n);
		cnt /= g, n /= g;
		cout << cnt << "/" << n << "\n";
	}
	return 0;
}