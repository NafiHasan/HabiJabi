#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		ll n, k, s;
 		cin >> n >> k >> s;
 		vector<ll> a(n, 0);
 		a[0] = s;
 		bool ok = 1;
 		for (int i=0; i<n - 1 && ok; i++){
 			if(a[i] > -2 && a[i] < 2)break;
 			a[i + 1] += a[i] / k;
 			a[i] %= k;
 			if(a[i] > 1){
 				a[i] -= k;
 				a[i + 1]++;
 				if(a[i] < -1)ok = 0;
 			}
 		}
 		for (int i=0; i<n && ok; i++){
 			if(a[i] < -1 || a[i] > 1)ok = 0;
 		}
 		if(ok){
 			for (int i=0; i<n; i++)cout << a[i] << ' ' ;
 			cout << '\n';
 		}
 		else {
 			cout << "-2\n";
 		}
 	}	
    return 0;
}