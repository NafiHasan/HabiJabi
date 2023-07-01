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
 		vector<int>v(n), cur(2005,0);
 		map<pair<int,int>,int>mp;
 		for (int i=0; i<n; i++){
 			cin >> v[i];
 		}
 		int now = 0;
 		while(1){
 			vector<int>freq(2005, 0);
 			for (int i=0; i<n; i++) freq[v[i]]++;
 			for (int i=0; i<n; i++) cur[i] = freq[v[i]];
 			for (int i=0; i<n; i++)mp[{now,i}] = v[i];
 			now++;
 			if(cur == v)break;
 			v = cur;
 			// for(int i=0; i<n; i++)cout << v[i] << ' ';
 			// cout << '\n';
 		}
 		int q;
 		cin >> q;
 		while(q--){
 			int ind, cnt;
 			cin >> ind >> cnt;
 			if(cnt >= now) cout << mp[{now-1, ind-1}]<< '\n';
 			else cout << mp[{cnt, ind-1}] << '\n';
 		}
 	}	
    return 0;
}