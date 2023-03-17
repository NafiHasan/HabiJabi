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
 		int ans = 0, cnt = 0;
 		for (int i=0; i<n; i++){
 			if(a[i] == 0 || b[i] == 0){
 				ans = max(ans, cnt);
 				cnt = 0;
 			}
 			else cnt++;
 			ans = max(ans, cnt);
 		}
 		ans = max(ans, cnt);
 		cout << ans << '\n';
 	}	
    return 0;
}