#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	int n;
 	cin >> n;
 	vector<vector<int>>cost(n);
 	for (int i=0; i<n; i++){
 		vector<int>tmp(3);
 		cin >> tmp[0] >> tmp[1] >> tmp[2];
 		cost[i]=tmp;
 	}
 	vector<vector<int>>dp(n);
 	dp[0]={cost[0][0],cost[0][1], cost[0][2]};
 	for (int i=1; i<n; i++){
 		vector<int>tmp(3,0);
 		for (int j=0; j<3; j++){
 			for (int k=0; k<3; k++){
 				if (j!=k){
 					tmp[k]=max(tmp[k], dp[i-1][j] + cost[i][k]);
 				}
 			}
 		}
 		dp[i]=tmp;
 	}
 	cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) << en;
    return 0;
}