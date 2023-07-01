#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		vector<int>a(n), cnt(200000,-1);
 		int ans = -1;
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 			if(cnt[a[i]] != -1){
 				ans = max(ans, n - i + cnt[a[i]]);
 			}
 			cnt[a[i]] = i;
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}