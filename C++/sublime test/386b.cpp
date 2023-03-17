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
 	int n,m;
 	cin >> n >> m;
 	map<int,int>mp;
 	int a[n], ans[n+1] , cnt=0;
 	for (int i=0; i<n ; i++) cin>> a[i];
 	for (int i=n-1; i>=0 ; i--){
 		if (mp[a[i]]==0){
 			mp[a[i]]++;
 			cnt++;
 		}
 		ans[i]=cnt;
 	}
 	while(m--){
 		int x;
 		cin >> x;
 		cout << ans[x-1] << '\n';
 	}
    return 0;
}