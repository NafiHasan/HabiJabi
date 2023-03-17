#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		long long n;
 		cin >> n;
 		map<long long,long long>cnt;
 		vector<pair<long long,long long>>v(n);
 		for (long long i=0; i<n; i++){
 			cin >> v[i].first >> v[i].second;
 			cnt[v[i].second]++;
 		}
 		long long ans = n* (n-1) * (n-2) /6LL;
 		sort(v.begin(), v.end());
 		for (int i=0; i<n; i++){
 			ans-=(long long)((cnt[v[i-1].second]-1) * (cnt[v[i].second] - 1));
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}