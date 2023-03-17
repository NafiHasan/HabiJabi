#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	double m, n;
 	cin >> m >> n;
 	double ans = m;
 	// cout << (long double)pow(0.5, 1000);
 	for (double i = 1; i<m; i++){
 		double tmp = i/m;
 		ans -= (double)pow(tmp, n);
 	}	
 	cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}