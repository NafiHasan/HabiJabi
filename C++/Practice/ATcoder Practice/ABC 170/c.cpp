#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
	#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	#endif
}

int main()
{
	fast_io();
    file_io();
 	int x, n;
 	cin >> x >> n;
 	vector<int> v(n);
 	map<int,int>mp;
 	for (int i=0; i<n; i++){
 		cin >> v[i];
 		mp[v[i]]++;
 	}	
 	int ans=-1, mn=INT_MAX;
 	for (int i=0; i<102; i++){
 		if (mp[i]==0 && abs(i-x) < mn){
 			mn=abs(i-x);
 			ans=i;
 		}
 	}
 	cout << ans << en;
    return 0;
}