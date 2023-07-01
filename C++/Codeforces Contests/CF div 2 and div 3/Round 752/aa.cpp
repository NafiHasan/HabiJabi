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
 		vector<int> a(n);
 		long long ans = 0, last = 1;
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 			if(a[i] > last)ans += a[i] - (last);
 			last = max(last+1, (long long)a[i] + 1);
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}