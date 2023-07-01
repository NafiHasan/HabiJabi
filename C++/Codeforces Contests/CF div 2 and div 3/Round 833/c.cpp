#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		vector<ll> a(n), presum(n, 0);
 		for(int i=0; i<n; i++)cin >> a[i];
 		presum[0] = a[0];
 		ll mx = 0, add = 0;
 		bool got = 0;
 		map<ll,ll> mp;
 		if(a[0] == 0){
 			got = 1;
 			mp[a[0]]++;
 			mx = 1;
 		}
 		for (int i=1; i<n; i++){
 			presum[i] = presum[i - 1] + a[i];
 			// cout << presum[i] << '\n';
 			if(a[i] == 0)got = 1;
 			if(!got && presum[i] == 0){
 				add++;
 			}
 			if(got)
 				mp[presum[i]]++;
 			mx = max(mx, mp[presum[i]]);
 			// cout << "mx " << mx << '\n';
 		}
 		cout << mx + add << '\n';
 	}	
  return 0;
}