#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
const long long p = 1e9+7;

// for (a^n) % p
long long bigmod (long long a, long long n){
	a %= p;
	long long ans = 1;
	while(n){
		if (n & 1) {
			ans = ans * a % p;
			cout << "1 "<< n <<" " << a << en;
		}
		cout << "before " << a << en;
		a = a * a % p;
		cout << "before " << a << en;
		n >>= 1;
	}
	return ans;
}

int main()
{
	fast_io();
 	long long a,n;
 	cin >> a >> n;
 	long long ans = bigmod(a,n);
 	cout << ans << "\n";
    return 0;
}