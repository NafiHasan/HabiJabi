#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin>>tc;
 	while(tc--){
 		vector<int>a(3);
 		cin >> a[0] >> a[1] >> a[2];
 		sort(a.rbegin(), a.rend());
 		if(a[2] == a[1] && a[0] % 2 == 0)cout << "YES\n";
 		else if(a[0] == a[1] && a[2] % 2 == 0)cout << "YES\n";
 		else if(a[1] + a[2] == a[0])cout << "YES\n";
 		else cout << "NO\n";
 	}	
    return 0;
}