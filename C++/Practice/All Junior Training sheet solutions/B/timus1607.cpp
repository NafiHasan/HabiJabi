#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int a, b, c, d;
 	cin >> a >> b >> c >> d;
 	vector<int>v;
 	for (int i=a; i<=c; i+=b)v.push_back(i);
 	for (int i=c; i>=a; i-=d)v.push_back(i);
	sort(v.begin(), v.end());
 	int lo = 0, hi = v.size() - 1, mid, ans = -1;
 	while(lo <= hi){
 		mid = (lo + hi)/2;
 		// cout << v[mid] << '\n';
 		if((v[mid] - a) % b == 0){
 			int div = (v[mid] - a) / b;
 			int div2 = (c - v[mid]) / d;
 			if((c - v[mid]) % d != 0){
 				if(div2 == div - 1){
 					ans = v[mid];
 					break;
 				}
 			}
 			if(div2 == div){
 				ans = v[mid];
 				break;
 			}
 			if(div2 < div) hi = mid - 1;
 			else lo = mid + 1;
 		}
 		else {
 			int div = (c - v[mid]) / d;
 			int div2 = (v[mid] - a) / b;
 			if((v[mid] - a) % b != 0){
 				if(div2 == div - 1){
 					ans = v[mid];
 					break;
 				}
 			}
 			if(div == div2){
 				ans = v[mid];
 				break;
 			}
 			if(div2 < div) hi = mid - 1;
 			else lo = mid + 1;
 		}
 	}	
 	cout << ans << '\n';
    return 0;
}