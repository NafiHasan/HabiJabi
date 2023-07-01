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
 		map<int,int> mp;
 		for (int i=0; i<n; i++)cin >> a[i];
 		for (int i=0; i<n; i++)cin >> b[i];
 		for (int i=0; i<n; i++){
 			while(a[i] % 2 == 0)a[i]/=2;
 			mp[a[i]]++;
 		}
 		bool ans = 1;
 		for (int i=n - 1; i >= 0; i--){
 			bool ok = 0;
 			while(b[i] >= 1){
 				if(mp[b[i]] > 0){
 					mp[b[i]]--;
 					ok = 1;
 					break;
 				}
 				b[i]/=2;
 			}
 			if(!ok){
 				ans = 0;
 				break;
 			}
 		}
 		if(ans)cout << "YES\n";
 		else cout << "NO\n";
 	}	
    return 0;
}