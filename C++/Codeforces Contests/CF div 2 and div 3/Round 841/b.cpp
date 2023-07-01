#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

const int mod=1e9+7;

int binpow(int a, int n){
	a %= mod;
	int ans=1;
	while(n){
		if(n&1) ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans%mod;
}

signed main() {
	FastIO;
 	int tc;
 	cin>> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		int x;
 		int ans = (n + 1) * n % mod * (2LL * n + 1) % mod * binpow(6LL, mod - 2) % mod;

 		int p =  2LL * (n * (n + 1) % mod * (n - 1) % mod) * binpow(6LL, mod - 2) % mod;
 		
 		ans = (ans + p) % mod;
 		ans = ans * 2022 % mod;
 		cout << ans << '\n';
 	}	
    return 0;
}