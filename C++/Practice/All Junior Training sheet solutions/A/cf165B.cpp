#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	long long n, k;
 	cin >> n >> k;
 	long long lo = 1, hi = n, mid, ans = n;	
 	while(lo <= hi){
 		mid = (lo + hi) / 2;
 		long long tmp = mid;
 		for (int i=1; i<=32; i++){
 			if(pow(k,i) > mid)break;
 			tmp += mid/pow(k,i);
 		}
 		if(tmp >= n){
 			ans = min(ans, mid);
 			hi = mid - 1;
 		}
 		else lo = mid + 1;
 	}
 	cout << ans << '\n';
    return 0;
}