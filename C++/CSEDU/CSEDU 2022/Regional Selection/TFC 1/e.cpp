#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

const ll N = 20000005;
// vector<bool>prime(N + 1, 1);
// const int N = 200005;
// vector<bool>prime(N+1, 1);

// void sieve(){
// 	prime[0] = prime[1] = 0;
// 	for (int i=2; i*i <= N; i++){
// 		if(!prime[i])continue;
// 		for (int j = i*i ; j <= N; j+=i)prime[j] = 0;
// 	}
// }


int main() {
	fast_io();
	// sieve();
	vector<ll> pre(N, 1), cum(N, 0);
	for (ll i = 2; i < N; i++) {
		for (ll j = i; j < N; j += i) {
			pre[j] += i;
		}
	}
	for (ll i = 1; i < N; i++) {
		cum[i] += cum[i  - 1] + pre[i];
	}
	while (1) {
		ll n;
		cin >> n;
		if (n == 0)break;
		ll ans = cum[n] - 1;
		cout << ans << '\n';
	}
	return 0;
}