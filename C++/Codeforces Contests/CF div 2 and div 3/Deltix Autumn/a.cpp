#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		cin>> n;
 		long long a[n];
 		for (int i=0; i<n; i++)cin>> a[i];
 		long long best = 0;
 		for (int i=0; i<n; i++){
 			long long ans = 0;
 			long long cnt = 0;
 			for (int j=0; j<n; j++){
 				if(i != j){
 					long long tmp = a[j];
 					while(tmp % 2== 0){
 						tmp /=2 ;
 						cnt++;
 					}
 					ans+= tmp;
 				}
 			}
 			ans+= a[i] * pow(2, cnt);
 			best = max(best, ans);

 		}
 		cout << best << '\n';
 	}	
    return 0;
}