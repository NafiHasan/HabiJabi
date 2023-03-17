#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
const ll p=1e9+7; 
ll a[100000],cnt[10000],cnt2[1000];
int dp[1000][1000];
ll f(int l, int r){
	if(l==r) {
		//cnt[a[l]]++;
		return a[l];
	}
	//if(dp[l][r]!=0)return dp[l][r];
	ll s=0;
	for (int i=l; i<=r; i++){
		s+=a[i];
		cnt2[i]++;
	}
	//cout << l << " " << r << " " <<s << en;
	ll ans= s + f(l+1,r) + f(l,r-1);
	//cout <<l << " "<< r <<" " << ans << en;
	//dp[l][r]=ans;
	return ans;
}

int main()
{
	fast_io();
 	w(t){
 		int n;
 		cin >> n;
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 		}
 		cout << f(0,n-1) << en;
 		cout << 4000000000%p <<en;
 		//for (int i=0; i<n; i++)cout << cnt2[i]<<" ";
 	}
    return 0;
}