#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const double pi = 3.14159265359;

int main()
{
	fast_io();
 	double d,h,v,e;
 	cin >> d >> h >> v >>e;
 	double total = pi * (d/2.0) * (d/2.0) * h;
 	if((pi * (d/2.0) * (d/2.0) * e) >= v){
 		cout << "NO\n";
 		return 0;
 	}
 	double ans = total / (v - (pi * (d/2.0) * (d/2.0) * e));
 	cout << "YES\n" << fixed << setprecision(10) << ans << '\n';
    return 0;
}