#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int n;
 	cin >> n;
 	int pa[n];
 	int sum = 0;
 	for (int i=0; i<n; i++){
 		cin >> pa[i];
 		sum+= pa[i];
 	}
 	// cout << ( 1<< n) << '\n';
 	for (int mask=1; mask<=(1 << n); mask++){
 		int ans = 0;
 		for (int i=0; i<n; i++){
 			// cout << mask << ' ' << (1 << i) << '\n';
 			if((mask & (1 << i) )!= 0){
 				ans += pa[i];
 				// cout << ans << '\n';
 			}
 		}
 		if(ans == sum/2){
 			for (int i=0; i<n; i++){
 				if((mask & (1 << i)) != 0){
 					cout << pa[i] << ' ';
 				}
 			}
 			break;
 		}
 	}
 	cout << '\n';

    return 0;
}