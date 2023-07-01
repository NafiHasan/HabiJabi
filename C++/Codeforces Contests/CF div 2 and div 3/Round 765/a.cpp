#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin>> tc;
 	while(tc--){
 		int n, l;
 		cin >> n >> l;
 		vector<int>a(n), cnt(l,0);
 		for (int i=0; i<n; i++)cin >> a[i];
 		for (int i=0; i<n; i++){
 			for (int j=0; j<l; j++){
 				if(((1 << j) & a[i]) != 0)cnt[j]++;
 			}
 		}
 		int ans = 0;
 		for (int i=0; i<l; i++){
 			if(cnt[i] > (n/2)){
 				ans = ans ^ (1 << i);
 			}
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}