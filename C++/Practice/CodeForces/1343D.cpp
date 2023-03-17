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
 		int n, k;
 		cin >> n >>k;
 		int a[n];
 		for (int i=0; i<n; i++) cin >> a[i];
 		int mx=0;
 		int mn=INT_MAX;
 		for (int i=0,j=n-1; i<n/2; j--,i++){
 			// int tmp= min(a[i],a[j]);
 			mn=min(mn,max(a[i],a[j])+k);
 			mx=max(mx,min(a[i],a[j])+1);
 		}
 		cout << mn << " " << mx <<en;
 		map<int,int>m;
 		int best=0;
 		for (int i=0, j=n-1; i<n/2; i++,j--)m[a[i]+a[j]]++;
 		for (int i=min(mn,mx); i<=max(mn,mx); i++){
 			best=max(best,m[i]);
 		}
 		int num=n;
 		num-=best*2;
 		int ans=num/2;
 		m.clear();
 		best=0;
 		for (int i=0, j=n-1; i<n/2; j--,i++){
 			m[a[i]+a[j]]++;
 			best=max(best,m[a[i]+a[j]]);
 		}
 		num=n;
 		num-=2*best;
 		ans=min(ans,num/2);
 		cout << ans <<en;
 	}	
    return 0;
}