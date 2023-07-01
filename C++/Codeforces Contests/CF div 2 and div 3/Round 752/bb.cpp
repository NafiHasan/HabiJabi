#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
	int tc ;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		int a[n];
		bool ys =0;
		for (int i=0; i<n; i++){
			cin >> a[i];
			if(i && a[i] <= a[i-1])ys = 1;
		}
		if(n % 2 == 0){
			cout << "YES\n";
		}
		else if( n%2 == 1 && ys )cout << "YES\n";
		else cout << "NO\n";

	}	
    return 0;
}