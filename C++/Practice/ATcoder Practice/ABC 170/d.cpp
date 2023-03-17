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
 	int n;
 	cin >> n;
 	int a[n];
 	map<int,int>mp;
 	for (int i=0; i<n ; i++){
 		cin >> a[i];
 		mp[a[i]]++;
 	}
 	vector<int> v[n];
 	for (int i=0; i<n; i++){
 		int num=a[i];
 		v[i].push_back(1);
 		v[i].push_back(num);
 		for (int j=2; j*j<=num; j++){
 			if (num%j==0){
 				v[i].push_back(num/j);
 				v[i].push_back(j);
 			}
 		}
 	}
 	int ans=0;
 	for (int i=0; i<n ; i++){
 		bool found=0;
 		for (int j=0; j<v[i].size(); j++){
 			if (v[i][j]!=a[i] && mp[v[i][j]]>0)found=1;
 			else if (v[i][j]==a[i] && mp[a[i]]>=2)found = 1;
 		}
 		if(!found)ans++;
 	}
 	cout << ans << en;
    return 0;
}