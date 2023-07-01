#include <bits/stdc++.h>  
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
int main()
{
	fast_io();
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<pair<int,int>>vp(n);
		for (int i=0; i<n; i++)cin >> vp[i].first;
		for (int i=0; i<n; i++)cin >> vp[i].second;
		sort(vp.begin(), vp.end());
		for (int i=0; i<n; i++){
			if(vp[i].first > k)break;
			k+= vp[i].second;
		}
		cout<< k << '\n';
	}
	return 0;
}