#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int MOD = 1e9 + 7;

struct mint {
	int v; explicit operator int() const { return v; }
	mint() { v = 0; }
	mint(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};

mint& operator+=(mint& a, mint b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mint& operator-=(mint& a, mint b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint operator*(mint a, mint b) { return mint((long long) a.v * b.v); }
mint& operator*=(mint& a, mint b) { return a = a * b; }
mint pow(mint a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mint inv(mint a) { assert(a.v != 0); return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }


mint ans = 0;
mint dp[100005][505];
int n, m;
int a[100005];
deque<int> fix;

int bs(deque<int> d, int ind) {
	int lo = 0, hi = d.size() - 1, mid, ans = -1;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (d[mid] > ind) {
			ans = d[mid];
			hi = mid - 1;
		} else lo = mid + 1;
	}
	return ans;
}

int cnt = 0;
mint fun(int ind, int cur) {
	cnt++;
	cout << ind << ' ' << cur << '\n';
	// if (!fix.empty() && ind == fix.front())fix.pop_front();
	if ((int)dp[ind][cur] != -1)return dp[ind][cur];
	if (ind >= n - 1) {
		// cout << ind << ' ' << cur << '\n';
		return 1;
	}
	// if (a[ind] != 0) {
	// 	return dp[ind][cur] = fun(a[ind], ind + 1, max(1, a[ind] - 1)) + fun(a[ind], ind + 1, a[ind]) + fun(a[ind] , ind + 1, min(m, a[ind] + 1));
	// }
	if (ind < n - 1 && a[ind + 1] != 0) {
		return dp[ind][cur] = fun(ind + 1, a[ind + 1]);
	}

	mint tot = 0;

	if (bs(fix, ind) == -1) {
		tot += fun(ind + 1, cur);
		if (cur + 1 <= m)tot += fun(ind + 1, min(m, cur + 1));
		if (cur - 1 >= 1)tot += fun(ind + 1, max(1, cur - 1));
		// (int)tot << '\n';
		return dp[ind][cur] = tot;
	}
	int last = bs(fix, ind);
	int lo = a[last] - (last - ind - 1);
	lo = max(1, lo);
	int hi = a[last] + (last - ind - 1);
	hi = min(m, hi);
	// cout << ind << ' ' << cur << ' ' << lo << ' ' << hi << '\n';
	if (cur >= lo && cur <= hi)tot += fun(ind + 1, cur);
	if ((cur + 1) >= lo && (cur + 1) <= hi)tot += fun(ind + 1, cur + 1);
	if ((cur - 1) >= lo && (cur - 1) <= hi)tot += fun(ind + 1, cur - 1);
	// cout << ind << ' ' << pre << ' ' << (int)tot << '\n';
	// if (ind == 1 && cur == 3) {
	// 	cout << lo << ' ' << hi << '\n';
	// 	cout << (int)tot << '\n';
	// }
	return dp[ind][cur] = tot;
}

int main() {
	FastIO;
	cin >> n >> m;
	memset(dp, -1 , sizeof dp);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] != 0)fix.push_back(i);
	}
	if (a[0] == 0) {
		if (fix.size() == 0) {
			for (int i = 1; i <= m; i++) {
				ans += fun(0, i);
			}
		} else {
			int lo = a[fix.front()] - (fix.front());
			lo = max(1, lo);
			int hi = a[fix.front()] + (fix.front());
			hi = min(m, hi);
			for (int i = lo; i <= hi; i++) {
				ans += fun(0, i);
			}
		}
	} else {
		ans += fun(0, a[0]);
	}
	// cout << cnt << '\n';
	// cout << (int)dp[0][1] << '\n';
	// ans = fun(0, 0);
	// if ((int)ans == 0)ans += 1;
	for (int i = 1; i < fix.size(); i++) {
		if (abs(a[fix[i]] - a[fix[i - 1]]) > (fix[i] - fix[i - 1]))ans = 0;
	}
	cout << (int)ans << '\n';
	return 0;
}