#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
	fast_io();
	#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	#endif
}

int main()
{
    file_io();
 	int n, m;
 	cin >> n >> m;
 	map<int,int>mp;
 	int tar;
 	vector<pair<int,int>>v(m);
 	for (int i=0; i<m; i++){
 		cin >> v[i].first >> v[i].second;
 		mp[v[i].first]++, mp[v[i].second]++;
 	}
 	for (int i=1; i<=n; i++){
 		if (mp[i] == 0) {
 			tar=i;
 			break;
 		}
 	}
 	cout << n-1 << en;
 	for (int i=1; i<=n; i++)
 		if (i != tar)cout << i << " " << tar << en;
    return 0;
}