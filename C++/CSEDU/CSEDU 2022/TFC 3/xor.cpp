#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int a, b;
 	int tc;
 	cin>> tc;
 	cout << (28 ^ 7) << '\n';
 	while(tc--){
 		int n, gi;
 		cin >> n >> gi;
 		int ans = 0;
 		for (int i=0; i<n; i++){
 			int x;
 			cin >> x;
 			ans += (x ^ gi);
 			cout << (x ^ gi) << '\n';
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}