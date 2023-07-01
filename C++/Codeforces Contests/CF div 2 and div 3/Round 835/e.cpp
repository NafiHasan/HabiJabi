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
 		int l0 = -1, r1 = -1;
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 			if(a[i] == 0 && l0 == -1)l0 = i;
 			if(a[i] == 1)r1 = i;
 		}
 		int ans = 0;

 		int cnt = 0, tmp = 0;
 			for (int i=0; i<n; i++){
 				if(a[i] == 1)cnt++;
 				else tmp += cnt;
 			}
		ans = max(ans, tmp);

 		if(l0 != -1){
 			a[l0] = 1 - a[l0];
 			int cnt = 0, tmp = 0;
 			for (int i=0; i<n; i++){
 				if(a[i] == 1)cnt++;
 				else tmp += cnt;
 			}
 			ans = max(ans, tmp);
 			a[l0] = 1 - a[l0];
 		}
 		if(r1 != -1){
 			a[r1] = 1 - a[r1];
 			int cnt = 0, tmp = 0;
 			for (int i=0; i<n; i++){
 				if(a[i] == 1)cnt++;
 				else tmp += cnt;
 			}
 			ans = max(ans, tmp);
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}