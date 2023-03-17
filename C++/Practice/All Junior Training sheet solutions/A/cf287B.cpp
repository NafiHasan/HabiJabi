#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	long long n, k;
 	cin >> n >> k;
 	long long hi = k * (k+1)/ 2 - 1;
 	hi -= (k-2);
 	if(n == 1){
 		cout << "0\n";
 		return 0;
 	}
 	if(hi < n)cout << "-1\n";
 	else {
 		 hi -= n;
 		 long long ans = -1 + sqrt(1LL + 8LL*hi);
 		 ans/=2;
 		 ans = k -1 -ans;
 		 cout << ans << '\n';
 	}	
    return 0;
}