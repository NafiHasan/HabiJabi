#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
int main()
{
	fast_io();
 	int tc;
 	cin>> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		vector<ll> v(n);
 		for(int i=0; i<n; i++)cin >> v[i];
 		sort(v.begin(), v.end());
 		ll ans = v[0];
 		for (int i=0; i<n-1; i++){
 			ans = max(ans, v[i+1] - v[i]);
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}