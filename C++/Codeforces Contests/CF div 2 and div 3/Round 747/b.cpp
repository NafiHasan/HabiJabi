#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const long long mod = 1e9+7;

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		long long n, k;
 		cin >> n >> k;
 		vector<long long> v(40);
 		long long a = 1LL;
 		for(int i=0; i<40; i++){
 			v[i] = a;
 			a *= n%mod;
 			a %= mod;
 		}
 		long long ans = 0; 
 		for (long long i=0; i<40; i++){
 			if(((1LL << i) & (k)) != 0LL){
 				ans += v[i];
 				ans %= mod;
 			}
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}