#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, x;
 		cin >> n >> x;
 		vector<int>v(n), sor(n);
 		for (int i=0; i<n; i++)cin >> v[i];
 		sor = v;
 		sort(sor.begin(), sor.end());
 		bool ans = 1;
 		for (int i=0;i<n; i++){
 			int ind = i+1;
 			if(v[i] != sor[i] && (ind-1) < x && (n-ind) < x){
 				ans = 0;
 				break;
 			}
 		}
 		if(ans)cout << "YES\n";
 		else cout << "NO\n";
 	}	
    return 0;
}