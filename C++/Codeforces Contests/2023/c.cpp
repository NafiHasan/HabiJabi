#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

signed main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, m;
 		cin >> n>> m;
 		vector<int> a(n);
 		for (int i=0; i<n; i++)cin >> a[i];
 		// if(n == 1 && m == 1){
 		// 	cout << "0\n";
 		// 	continue;
 		// }
 		m--;
 		int sum = 0, ans = 0;
 		for (int i=m; i>0; i--){

 			if(sum+a[i] > 0){
 				a[i]=a[i]*-1;
 				sum+=a[i];
 				ans++;
 			}
 			else
 				sum+=a[i];

 		}
 		sum = 0;
 		int cur = 0;
 		// for (int i=0; i<m ;i++){
 		// 	cur += a[i];
 		// }
 		// cur *= -1;
 		for (int i = m+1; i<n; i++){
 			
 			if(sum+a[i] < 0){
 				ans++;
 				a[i]=a[i]*-1;
 				sum+=a[i];
 				// int ind = i -1;
 				// while(sum >= 0 && ind >= 0){
 				// 	if(a[ind] > 0){
 				// 		ans++;
 				// 		a[ind] *= -1;
 				// 		sum -= 2LL * a[ind];
 				// 	}
 				// }
 			}
 			else
 				sum+=a[i];
 		} 
 		cout << ans << '\n';
 	}	
    return 0;
}