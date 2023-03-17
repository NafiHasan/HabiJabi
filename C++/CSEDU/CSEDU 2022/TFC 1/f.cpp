#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

double dp[5000006][20];
int mx ;

double rec(int n, int x){
	if(dp[n][x] != -1)return dp[n][x];
	if(n < 0 || n > mx*2)return 0;
	dp[n][x] = 0.5 * rec(n+1, 1) + 0.5 * rec(n-x, x*2);
	return dp[n][x];
}

int main()
{
	fast_io();
 	long long n;
 	cin >> n;
 	mx = n;
 	memset(dp, -1 , sizeof(dp));
 	cout << rec(n,1);
    return 0;
}