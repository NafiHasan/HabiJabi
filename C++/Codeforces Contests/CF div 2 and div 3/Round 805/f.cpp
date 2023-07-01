#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		vector<int> a(n), b(n);
 		for (int i=0; i<n; i++)cin >> a[i];
 		for (int i=0; i<n; i++)cin >> b[i];
 		map<int,int> mp, vis;
 		for (int i=0; i<n; i++){
 			vis.clear();
 			int tmp = b[i];
 			tmp *= 2;
 			while(tmp <= 1e9 && vis[tmp] == 0){
 				vis[tmp] = 1;
 				mp[tmp]++;
 				tmp *= 2;
 			}
 			while(__builtin_popcount(b[i]) != 1){
 				if(b[i] % 2){
 					if(vis[b[i]] == 0){
 						mp[b[i]]++;
 						vis[b[i]] = 1;
 					}
 					b[i]--;
 					if(vis[b[i]] == 0){
 						mp[b[i]]++;
 						vis[b[i]] = 1;
 					}
 					int now = b[i];
 					while(now <= 1e9 && __builtin_popcount(now) != 1){
 						now *= 2;
 						if(vis[now] == 0){
 							mp[now]++;
 							vis[now] = 1;
 						}
 					}
 					b[i]/=2;
 				}
 				else {
 					if(vis[b[i]] == 0){
 						mp[b[i]]++;
 						vis[b[i]] = 1;
 					}
 					b[i]/=2;
 				}
 			}
 		}
 		bool ans = 1;
 		for (int i=0; i<n; i++){
 			if(__builtin_popcount(a[i]) == 1)continue;
 			if(mp[a[i]] > 0)mp[a[i]]--;
 			else {
 				ans = 0;
 				break;
 			}
 		}
 		if(ans)cout << "YES\n";
 		else cout << "NO\n";
 	}	
    return 0;
}