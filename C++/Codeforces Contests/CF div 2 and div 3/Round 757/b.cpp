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
 		vector<pair<long long,long long>>a(n);
 		for (int i=0; i<n; i++) {
 			cin >> a[i].first;
 			a[i].second = i;
 		}
 		sort(a.end(), a.begin());
 		long long ans = 0;
 		for (int i=0; i<n ;i++){
 			long long tmp = i+2;
 			if(i % 2)tmp--;
 			ans += tmp * a[i].first;
 		}
 		cout << ans << '\n';
 		for (int i=0; i<n; i++)
 	}	
    return 0;
}