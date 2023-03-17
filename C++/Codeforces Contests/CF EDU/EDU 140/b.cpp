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
 		for (int i=0; i<n ;i++)cin>> a[i];
 		sort(a.begin() + 1, a.end());
 		for (int i=1; i<n; i++){
 			if(a[i] > a[0]){
 				a[0] = (a[0] + a[i] + 1)/2;
 			}
 		}
 		cout << a[0] << '\n';
 	}	
    return 0;
}