#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
	#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	#endif
}

int main()
{
	fast_io();
    file_io();
 	w(t){
 		int n;
 		cin >>n;
 		vector<pair<int,int>> vp;
 		for (int i=0; i<n; i++){
 			int x,y;
 			cin >>x>>y;
 			vp.push_back({x,y});
 		}
 		int tm[n];
 		for (int i=0; i<n; i++){
 			cin >>tm[i];
 		}
 		int ans=0,prev=0;
 		for (int i=0; i<n; i++){
 			int ar= ans+(vp[i].first-prev) + tm[i];
 			if (i==n-1){
 				ans=ar;
 				break;
 			}
 			int mn=(vp[i].second-vp[i].first)/2;
 			if ((vp[i].second-vp[i].first)%2)mn++;
 			ans=max(ar+mn,vp[i].second);
 			prev=vp[i].second;
 		}
 		cout <<ans<<en;
 	}
    return 0;
}