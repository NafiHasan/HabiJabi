#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		vector<ll>v(n);
 		bool same = 1;
 		for (int i=0; i<n; i++){
 			cin >> v[i];
 			if(i && v[i] != v[i-1])same = 0;
 		}
 		if(same){
 			cout << "-1\n";
 			continue;
 		}
 		ll mn = *min_element(v.begin(), v.end());
 		ll ans = 0;
 		for (int i=0; i<n; i++){
 			ll dif = v[i] - mn;
 			if(ans == 0)ans = dif;
 			ans = __gcd(ans, dif); 
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}