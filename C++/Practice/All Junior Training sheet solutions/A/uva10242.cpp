#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	// fast_io();
 	while(1){
 		vector<pair<double, double>>vp(4);
 		for (int i=0; i<4; i++)cin >> vp[i].first >> vp[i].second;
 		if(feof(stdin))break;
 		sort(vp.begin(), vp.end());
 		pair<double,double>ans;
 		if(vp[1] == vp[0]){
 			ans = {vp[2].first + (vp[3].first - vp[1].first), vp[2].second + (vp[3].second - vp[1].second)};
 		}
 		else if(vp[2] == vp[1]){
 			ans = {vp[3].first + (vp[0].first - vp[2].first), vp[3].second + (vp[0].second - vp[2].second)};
 		}
 		else {
 			ans = {vp[0].first + (vp[1].first - vp[2].first), vp[0].second + (vp[1].second - vp[2].second)};
 		}
 		cout << fixed << setprecision(3) << ans.first << ' ' << ans.second << '\n';
 	}	
    return 0;
}