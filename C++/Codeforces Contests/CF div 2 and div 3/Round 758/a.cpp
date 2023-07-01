#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int N = 100005;
vector<pair<int,int>>vp(N), vp1(N), vp2(N);
map<int,int>vis1,vis2, m1, m2;

void dfs(int num, int ind, int sz){
	if(ind == 1){
		vis1[num] = 1;
		num = m1[num]; 
	}
	else {
		vis2[num] = 1;
		num = m2[num];
	}
	int lo = 0, hi = sz - 1, mid;
	int start = 0;
	while(lo <= hi){
		mid = (lo + hi)/2;
		if(ind == 1){
			if(vp2[mid].first == num){
				start = mid;
				break;
			}
			else if(vp1[mid].first < num)lo = mid+1;
			else hi = mid-1;
		}
		else {
			if(vp1[mid].first == num){
				start = mid;
				break;
			}
			else if(vp2[mid].first < num)lo = mid+1;
			else hi = mid-1;
		}
	}
	for (int i=start + 1; i<sz; i++){
		if(ind == 1){
			if(vis2[vp2[i].] == 1)return;
			else dfs(vp2[i].first, 2, sz);
		}
		else {
			if(vis1[vp[i].first] == 1)return;
		}
	}
}

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		for (int i=0; i<n; i++)cin >> vp[i].first;
 		for (int i=0; i<n; i++)cin >> vp[i].second;
 		vp1 = vp;
 		sort(vp1.begin(), vp2.end());
 		for (int i=0; i<n; i++){
 			m1[vp[i].first] = vp[i].second;
 			m2[vp[i].second] = vp[i].first;
 			vp2[i].first = vp[i].second;
 			vp2[i].second = vp[i].first;
 		}
 		sort (vp2.begin(), vp2.end());
 		dfs(vp1[n-1].second, 1, n);
 	}	
    return 0;
}