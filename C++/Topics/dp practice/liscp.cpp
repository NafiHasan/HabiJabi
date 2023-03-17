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

void restore(vector<int>a){
	int n=a.size();
	vector<int> dp(n,1), p(n,-1);
	for (int i=0; i<n; i++){
		for (int j=0; j<i; j++){
			if (a[j]<a[i] && dp[i] < dp[j]+1){
				dp[i]=dp[j]+1;
				p[i]=j;
			}
		}
	}
	int pos=0, ans=0;
	for (int i=0; i<n; i++){
		if (dp[i] > ans ){
			ans =dp[i];
			pos=i;
		}
	}
	vector<int> sub;
	while(pos != -1){
		sub.push_back(a[pos]);
		pos = p[pos];
	}
	cout << sub.size() << en;
	for (int i=sub.size()-1; i >= 0; i--)cout << sub[i]<<" ";
	cout << en;
}


int main()
{
	fast_io();
    file_io();
 	int n;
 	cin >> n;
 	vector<int> v(n);
 	for (int i=0; i<n; i++)cin>>v[i];
 	// vector<int> dp(n,1);
 	// dp[0]=1;
 	// for(int i=0; i<n; i++){
 	// 	for (int j=0; j<i; j++){
 	// 		if(v[j]<v[i])dp[i]=dp[j]+1;
 	// 	}
 	// }
 	// int ans=0;
 	// for (int i=0; i<n; i++)ans=max(ans,dp[i]);
 	// cout << ans << en;
 	restore(v);
    return 0;
}