#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

vector<int> v(100005);
int n, a , r , m;

int f(int num){
	// cout << num << '\n';
	int add = 0, rm = 0;
	for (int i=0; i<n; i++){
		if(v[i] < num)add += (num - v[i]);
		else if(v[i] > num)rm += (v[i] - num);
	}
	// cout << add << 'f' << rm << '\n';
	int ans = 0;
	if(m <= a || m <= r){
		int mv = min(add, rm);
		ans += mv * m;
		ans += a*(add - mv) + r * (rm - mv);
	}
	else {
		ans = a * add + r * rm;
	}
	// cout << ans << '\n';
	return ans;
}




signed main() {
	FastIO;
 	cin >> n >> a >> r >> m;
 	for (int i=0; i<n; i++)cin >> v[i];
 	int lo = 0, hi = 1e9, ans = LLONG_MAX;
 	// for (int i=0; i<300; i++){
 	// 	int m1 = lo + (hi - lo)/3;
 	// 	int m2 = hi - (hi - lo)/3;
 	// 	int f1 = f(m1), f2 = f(m2);
 	// 	// cout << m1 << ' ' << m2 << '\n';
 	// 	if(f1 >= f2){
 	// 		ans = min(ans, f2);
 	// 		lo = m1;
 	// 	}
 	// 	else {
 	// 		hi = m2;
 	// 		ans = min(ans, f1);
 	// 	}
 	// }
 	while(lo <= hi) {
 	    int mid = (lo + hi)/2;
 	    int f1 = f(mid), f2 = f(mid + 1);
 	    if(f1 < f2) {
 	        hi = mid - 1;
 	        ans = min(ans, f1);
 	    }
 	    else {
 	        lo = mid+1;
 	        ans = min(ans, f2);
 	    }
 	}	
 	cout << ans << '\n';
    return 0;
}