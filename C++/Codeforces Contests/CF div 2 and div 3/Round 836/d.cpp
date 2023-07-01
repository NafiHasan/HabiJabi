#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

signed main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		vector<int>a(n);
 		int root = n * 2;
 		int avg = 4 * n ;
 		a[0] = avg - n;
 		a[n - 1] = avg + n;
 		for (int i=1; i<n - 1; i++){
 			a[i] = avg;
 		}
 		for (int i = 1, j = (n - 2)/2; i < n / 2; i++, j--){
 			a[i] -= j;
 		}
 		for (int i = (n + 1)/2, j = (n - 2)/2; i<n - 1; i++, j--){
 			a[i] += j;
 		}
 		for (int i=0; i<n; i++)cout << a[i] << ' ';
 		cout << '\n';
 	}	
    return 0;
}