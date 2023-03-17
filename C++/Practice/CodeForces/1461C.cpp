#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, m;
 		cin>> n >> m;
 		vector<int> a(n);
 		for (int i=0; i<n; i++)cin>> a[i];
 		int cnt = n+1;
 		for (int i=n-1; i>=0; i--){
 			if(a[i] != i+1){
 				cnt = i+1;
 				break;
 			}
 		}
 		vector<pair<int,double>>vp(m);
 		for (int i=0; i<m; i++){
 			cin>> vp[i].first >> vp[i].second;
 		}
 		sort(vp.begin(), vp.end());
 		// vector<double>pre(n+1,1);
 		double ans = 0, gon = 0, last = 1;
 		for (int i=0; i<vp.size(); i++){
 			if(vp[i].first < cnt)continue;
 			// if(vp[i].first == cnt)pre[vp[i].first] = 1.0;
 			// else if(i>0)pre[vp[i].first] = pre[vp[i-1].first] * (1 - vp[i-1].second);
 			// if(vp[i].first > cnt)ans += vp[i].second * pre[vp[i].first];
 			// else ans += vp[i].second;
 			gon++;
 			if(gon == 1){
 				ans += vp[i].second;
 				last *= 1.0 - vp[i].second;
 			}
 			else {
 				ans += last * vp[i].second;
 				last *= 1.0 - vp[i].second;
 			}
 		}
 		if(cnt == n+1)ans = 1;
 		cout << fixed << setprecision(10) << ans << '\n';
 	}	
    return 0;
}