#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
long long ans = 500;
long long n, x;
map<long long, long long> dp;
void fun(long long num, long long move) {
	string s = to_string(num);
	if (num < 0 || s.size() > n) {
		return ;
	}
	// cout << num << ' ' << move << '\n';
	dp[num] = move;
	if (s.size() == n)ans = min(ans, move);
	map<int, int> mp;
	for (int i = 0; i < s.size(); i++) {
		mp[s[i] - '0']++;
	}
	for (long long i = 10; i > 1; i--) {
		if (num * i < num)continue;
		if (mp[i] > 0 && dp[num * i] == 0) {
			fun(num * i, move + 1);
			// break;
		} else if (mp[i] > 0 && dp[num * i] > 0 && dp[num * i] > move + 1) {
			fun(num * i , move + 1);
			// break;
		}
	}
}


int main() {
	fast_io();
	cin >> n >> x;
	fun(x, 0);
	if (ans == 500)ans = -1;
	cout << ans << '\n';
	return 0;
}