#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

signed main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		vector<int> a(n);
 		int mx = 0;
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 			mx |= a[i];
 		}
 		vector<int> sq;
 		int tt = mx;
 		for (int i=0; i * i <= tt; i++){
 			sq.push_back(i * i);
 			mx |= (i *i);
 		}
 		int ans = 0;
 		for (int ii=0; ii<sq.size(); ii++){

 			int xar[n + 5];
 			// unordered_map<int, int> mp;
 			vector<int> mp(mx  + 5, 0);
 			xar[0] = a[0];

 			for (int i = 1; i < n; i++)
 				xar[i] = xar[i - 1] ^ a[i];

 			for (int i = 0; i < n; i++) {
 				int tmp = sq[ii] ^ xar[i];

 				ans += mp[tmp];
 				if (xar[i] == sq[ii]) ans++;
 				mp[xar[i]]++;
 			}
 		}
 		int tot = n * (n + 1)/ 2LL;
 		tot -= ans;
 		cout << tot << '\n';
 	}	
    return 0;
}