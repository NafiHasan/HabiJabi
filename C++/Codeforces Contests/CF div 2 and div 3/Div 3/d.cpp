#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	w(t){
 		int n;
 		cin>>n;
 		int a[n];
 		map<int,int>m;
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 			m[a[i]]++;
 		}
 		int mx=0;
 		for (int i=0; i<n; i++){
 			mx=max(mx,m[a[i]]);
 		}
 		int rest=n-mx;
 		int ans=mx-rest;
 		if(ans<=0 && n%2==0)cout << "0\n";
 		else if(ans<=0 && n%2)cout << "1\n";
 		else cout << ans <<en;
 	}	
    return 0;
}