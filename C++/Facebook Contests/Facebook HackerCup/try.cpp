#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long


// const int N = 2000005;
// vector<bool>pr(N + 1, 1);
// vector<int> prime;

// void sieve() {
// 	pr[0] = pr[1] = 0;
// 	for (int i = 2; i * i <= N; i++) {
// 		if (!pr[i])continue;
// 		for (int j = i * i ; j <= N; j += i)pr[j] = 0;
// 	}
// 	for (int i = 2; i < N; i++) {
// 		if (pr[i])prime.push_back(i);
// 	}
// }


// int phi(int n) {
// 	int ans = n, ind = 0;
// 	while (prime[ind] * prime[ind] <= n) {
// 		if (n % prime[ind] == 0)ans -= ans / prime[ind];
// 		while (n % prime[ind] == 0)n /= prime[ind];
// 		ind++;
// 	}
// 	if (n != 1)ans -= ans / n;
// 	return ans;
// }
int phi(int n) {
	int ans = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) ans -= ans / i;
		while (n % i == 0) n /= i;
	}
	if (n != 1) ans -= ans / n;
	return ans;
}



signed main() {
	FastIO;
	// sieve();
	int tc;
	cin >> tc;
	while (tc--) {
		int a, m;
		cin >> a >> m;
		m /= __gcd(a, m);
		cout << phi(m) << '\n';
	}
	return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// #define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define int long long

// int phi(int n) {
// 	int ans = n;
// 	for (int i = 2; i * i <= n; i++) {
// 		if (n % i == 0) {
// 			while (n % i == 0) {
// 				n /= i;
// 			}
// 			ans -= ans / i;
// 		}
// 	}
// 	if (n > 1) {
// 		ans -= ans / n;
// 	}
// 	return ans;
// }