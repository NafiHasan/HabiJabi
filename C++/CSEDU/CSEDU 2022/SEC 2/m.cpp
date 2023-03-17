#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<long long> a(2005, 0);
long long dp[2005][2005];
int n;
long long f(long long kid, long long pos, vector<bool> vis) {
	if (dp[kid][pos] != -1)return dp[kid][pos];

	long long ans  = 0;
	for (int i = 0; i < n; i++) {
		ans +=
	}
}


int main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];

	return 0;
}