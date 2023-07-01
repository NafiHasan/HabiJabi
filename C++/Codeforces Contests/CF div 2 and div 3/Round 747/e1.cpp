#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// for (a^n) % p
const long long mod = 1e9+7;
long long bigmod (long long a, long long n){
	a %= mod;
	long long ans = 1;
	while(n > 0LL){
		if (n & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		n >>= 1LL;
	}
	return ans;
}
int main()
{
	fast_io();
 	long long n;
 	cin >> n;
 	long long all = (1LL << n) - 2LL;
 	long long ans = bigmod(4LL,all);
 	ans *= 6LL;
 	ans%=mod;
 	cout << ans << '\n';
    return 0;
}