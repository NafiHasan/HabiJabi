#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

long long mod = 998244353;

// for (a^n) % p
long long bigmod (long long a, long long n){
	a %= mod;
	long long ans = 1;
	while(n){
		if (n & 1) ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}


int main() {
	FastIO;
 	long long p = 28LL * bigmod(35, mod - 2) % mod;
 	cout << p << '\n';
    return 0;
}