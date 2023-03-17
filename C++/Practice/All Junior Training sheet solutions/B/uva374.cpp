#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


// for (a^n) % p
long long bigmod (long long a, long long n, long long p){
	a %= p;
	long long ans = 1;
	while(n){
		if (n & 1) ans = ans * a % p;
		a = a * a % p;
		n >>= 1;
	}
	return ans;
}


int main()
{
	// fast_io();
 	while(1){
 		long long a, n, p;
 		cin>>a >> n >> p;
 		if(feof(stdin))break;
 		cout << bigmod(a,n,p) << '\n';
 	}
    return 0;
}