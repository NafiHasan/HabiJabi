#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long


ll x, y, ans = 0;

ll f(ll level, ll type){
	// if(dp[level][type] != -1)return dp[level][type];
	if(type == 0 && level <= 1)return 0;

	ll tmp = 0;

	if(type == 0){
		tmp += f(level - 1, type) + x * f(level, 1 - type);
	}
	else {
		if(level <= 1)tmp++;
		else {
			tmp += f(level - 1, 1 - type) + y * f(level - 1, type);
		}
	}
	return tmp;
}

int main() {
	FastIO;
 	ll n;
 	cin >> n>> x >> y;
 	ll ans = f(n, 0);
 	cout << ans << '\n';
    return 0;
}