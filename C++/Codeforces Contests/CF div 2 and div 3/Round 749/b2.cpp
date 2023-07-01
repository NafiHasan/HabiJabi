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
 		cin >> n >> m;
 		map<int,int>mp;
 		for (int i=0; i<m; i++){
 			int u, mid, v;
 			cin >> u >> mid >> v;
 			mp[mid]++;
 		}
 		int rt;
 		for (int i=1; i<=n; i++)if(mp[i] == 0)rt = i;
 		for (int i=1; i<=n; i++)if(i!= rt)cout << rt << ' ' << i << '\n';
 	}	
    return 0;
}