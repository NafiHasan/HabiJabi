#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

long long lcmm(long long a , long long b){
	return a*b/__gcd(a,b);
}

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		long long n;
 		cin >> n;
 		vector<long long>a(n);
 		long long lc = 1;
 		bool ans = 1;
 		for (long long i=0; i<n; i++){
 			cin >> a[i];
 			lc = lcmm(lc, i+2);
 			if(a[i] % lc == 0)ans = 0; 
 		}
 		if(ans)cout << "YES\n";
 		else cout << "NO\n";
 	}	
    return 0;
}