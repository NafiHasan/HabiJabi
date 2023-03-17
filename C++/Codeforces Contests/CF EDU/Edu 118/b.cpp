#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin>> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		vector<int>a(n);
 		for (int i=0; i<n; i++)cin >> a[i];
 		sort(a.begin(), a.end());
 		for (int i=n-1; i >= ((n+1)/2); i--)cout << a[i] << ' ' << a[0] << '\n';
 	}	
    return 0;
}